#include "Renderer_Com.h"
#include "Transform_Com.h"
#include "Camera_Com.h"
#include "Material_Com.h"

#include "../GameObject.h"

#include "../Scene/Scene.h"

#include "../Resource/ResourceManager.h"
#include "../Resource/Mesh.h"
#include "../Render/Shader.h"
#include "../Render/ShaderManager.h"
#include "../Render/RenderState.h"
#include "../Render/RenderManager.h"

#include "../Device.h"

JEONG_USING

Renderer_Com::Renderer_Com()
	:m_Mesh(NULLPTR), m_Shader(NULLPTR), m_LayOut(NULLPTR), m_Material(NULLPTR)
{
	m_ComType = CT_RENDER;
	ZeroMemory(m_RenderState, sizeof(RenderState*) * RS_END);
}

Renderer_Com::Renderer_Com(const Renderer_Com& copyObject)
	:Component_Base(copyObject)
{
	*this = copyObject;

	if (m_Mesh != NULLPTR)
		m_Mesh->AddRefCount();

	if (m_Shader != NULLPTR)
		m_Shader->AddRefCount();

	for (int i = 0; i < RS_END; ++i)
	{
		if (m_RenderState[i] != NULLPTR)
			m_RenderState[i]->AddRefCount();
	}

	m_Material = NULLPTR;
}


Renderer_Com::~Renderer_Com()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Shader);
	SAFE_RELEASE(m_Material);

	for (int i = 0; i < RS_END; ++i)
		SAFE_RELEASE(m_RenderState[i]);
}

bool Renderer_Com::Init()
{
	//���� �������ִ� ������Ʈ�� AddComponent
	m_Material = AddComponent<Material_Com>("Material");
	SAFE_RELEASE(m_Material);

	return true;
}

int Renderer_Com::Input(float DeltaTime)
{
	return 0;
}

int Renderer_Com::Update(float DeltaTime)
{
	if (m_Material == NULLPTR)
		m_Material = m_Object->FindComponentFromType<Material_Com>(CT_MATERIAL);

	return 0;
}

int Renderer_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Renderer_Com::Collision(float DeltaTime)
{
}

void Renderer_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Renderer_Com::Render(float DeltaTime)
{
	//������Ʈ �Լ����� �̹� World����� ��ȯ�� �Ǿ���.
	//������ ������Ʈ���� ������ȯ(Projection)���ϰ�, ���̴��� ���������� ������.(UpdateTransform)
	UpdateTransform();

	Device::Get()->GetContext()->IASetInputLayout(m_LayOut);
	m_Shader->SetShader();

	for (int i = 0; i < RS_END; i++)
	{
		if (m_RenderState[i] != NULLPTR)
			m_RenderState[i]->SetState();
	}

	for (size_t i = 0; i < m_Mesh->GetContainerCount(); i++)
	{
		for (size_t j = 0; j < m_Mesh->GetSubsetCount((int)i); j++)
		{
			m_Material->SetShader((int)i, (int)j);
			m_Mesh->Render((int)i, (int)j);
		}
	}

	for (int i = 0; i < RS_END; i++)
	{
		if (m_RenderState[i] != NULLPTR)
			m_RenderState[i]->ResetState();
	}
}

Renderer_Com * Renderer_Com::Clone()
{
	return new Renderer_Com(*this);
}

void Renderer_Com::SetMesh(Mesh * mesh)
{
	SAFE_RELEASE(m_Mesh);
	m_Mesh = mesh;

	if(mesh != NULLPTR)
	{
		mesh->AddRefCount();

		SetShader(mesh->GetShaderKey());
		SetLayOut(mesh->GetLayOutKey());
	}
}

void Renderer_Com::SetMesh(const string & KeyName)
{
	SAFE_RELEASE(m_Mesh);

	//FindMesh���� �̹� Add����
	m_Mesh = ResourceManager::Get()->FindMesh(KeyName);

	if (m_Mesh != NULLPTR)
	{
		SetShader(m_Mesh->GetShaderKey());
		SetLayOut(m_Mesh->GetLayOutKey());
	}
}

void Renderer_Com::SetShader(Shader * shader)
{
	SAFE_RELEASE(m_Shader);
	m_Shader = shader;

	if (shader != NULLPTR)
	{
		shader->AddRefCount();
	}
}

void Renderer_Com::SetShader(const string & KeyName)
{
	SAFE_RELEASE(m_Shader);
	m_Shader = ShaderManager::Get()->FindShader(KeyName);
}

void Renderer_Com::SetLayOut(const string & KeyName)
{
	m_LayOut = ShaderManager::Get()->FindInputLayOut(KeyName);
}

void Renderer_Com::SetRenderState(const string & KeyName)
{
	RenderState* getState = RenderManager::Get()->FindRenderState(KeyName);

	if (getState == NULLPTR)
		return;

	//������� �迭�� ������ Ÿ�Ի����°�� ����ִ´�.
	m_RenderState[getState->GetStateEnum()] = getState;
}

//���⿡�� �������� ���������� ��ȯ�� ���ش�!
void Renderer_Com::UpdateTransform()
{
	TransformCBuffer cBuffer = {};
	//m_Transform�� GameObject�� �����ɶ� �����Ҵ����� �ڵ������Ǹ� �ڵ��ʱ�ȭ�� �Ѵ�.
	//AddComponent�� �Ҷ� Component�� ���� Transform_Com������ ������Ʈ�� ���� Transform_Com
	//������ �̹� �ʱ�ȭ�� �Ǿ��ִ�.

	Camera_Com* getCamera = m_Scene->GetMainCamera();
	
	cBuffer.World = m_Transform->GetWorldMatrix();
	cBuffer.View = getCamera->GetViewMatrix();
	cBuffer.Projection = getCamera->GetProjection();

	cBuffer.WV = cBuffer.World * cBuffer.View;
	cBuffer.WVP = cBuffer.WV * cBuffer.Projection;

	cBuffer.Pivot = m_Transform->GetPivot();
	cBuffer.Lenth = m_Mesh->GetLanth();

	//���̴��� �����ֱ����Ͽ� ��ġ��ķ� ��ȯ�Ѵ�.
	cBuffer.World.Transpose();
	cBuffer.View.Transpose();
	cBuffer.Projection.Transpose();
	cBuffer.WV.Transpose();
	cBuffer.WVP.Transpose();

	//�̸� �����س��� �������(ID3D11Buffer)�� �����ͼ� ������Ʈ ��Ų��.
	//���ؽ����̴��� �ȼ����̴��� ������ ���� ������ ��ĵ��� (�������) �������ش�. 
	ShaderManager::Get()->UpdateCBuffer("Transform", &cBuffer);

	SAFE_RELEASE(getCamera);
}