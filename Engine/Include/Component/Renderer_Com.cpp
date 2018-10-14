#include "Renderer_Com.h"
#include "Transform_Com.h"

#include "../Resource/ResourceManager.h"
#include "../Resource/Mesh.h"
#include "../Render/Shader.h"
#include "../Render/ShaderManager.h"

#include "../Device.h"

JEONG_USING

Renderer_Com::Renderer_Com()
	:m_Mesh(NULLPTR), m_Shader(NULLPTR), m_LayOut(NULLPTR)
{
	m_ComType = CT_RENDER;
}

Renderer_Com::Renderer_Com(const Renderer_Com& copyObject)
	:Component_Base(copyObject)
{
	*this = copyObject;

	if (m_Mesh != NULLPTR)
		m_Mesh->AddRefCount();

	if (m_Shader != NULLPTR)
		m_Shader->AddRefCount();
}


Renderer_Com::~Renderer_Com()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Shader);
}

bool Renderer_Com::Init()
{
	return true;
}

int Renderer_Com::Input(float DeltaTime)
{
	return 0;
}

int Renderer_Com::Update(float DeltaTime)
{
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
	UpdateTransform();

	Device::Get()->GetContext()->IASetInputLayout(m_LayOut);
	m_Shader->SetShader();
	m_Mesh->Render();
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

	//FindMesh에서 이미 Add해줌
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

void Renderer_Com::UpdateTransform()
{
	TransformCBuffer cBuffer = {};
	cBuffer.World = m_Transform->GetWorldMatrix();
	cBuffer.View = XMMatrixLookAtLH(Vector3(0.0f, 0.0f, -2.0f).Convert(), Vector3(0.0f, 0.0f, 0.0f).Convert(), Vector3::Axis[AXIS_Y].Convert());
	cBuffer.Projection = XMMatrixPerspectiveFovLH(JEONG_PI / 3.0f, 1280.0f / 720.0f, 0.03f, 1000.0f);

	cBuffer.WV = cBuffer.World * cBuffer.View;
	cBuffer.WVP = cBuffer.WV * cBuffer.Projection;
	//쉐이더로 전해주기위하여 전치행렬로 변환한다.
	cBuffer.World.Transpose();
	cBuffer.View.Transpose();
	cBuffer.Projection.Transpose();
	cBuffer.WV.Transpose();
	cBuffer.WVP.Transpose();

	ShaderManager::Get()->UpdateCBuffer("Transform", &cBuffer);
}
