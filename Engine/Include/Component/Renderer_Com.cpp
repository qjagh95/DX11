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
	//업데이트 함수에서 이미 World행렬은 변환이 되었다.
	//랜더러 컴포넌트에서 투영변환을하고, 쉐이더에 버퍼정보를 보낸다.(UpdateTransform)
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
//여기에서 실질적인 투영을위한 변환을 해준다!
void Renderer_Com::UpdateTransform()
{
	TransformCBuffer cBuffer = {};
	//m_Transform은 GameObject가 생성될때 동적할당으로 자동생성되며 자동초기화를 한다.
	//AddComponent를 할때 Component가 가진 Transform_Com변수는 오브젝트가 가진 Transform_Com
	//변수로 이미 초기화가 되어있다.
	cBuffer.World = m_Transform->GetWorldMatrix();
	//뷰 행렬을 만든다 (일단 상수) 1.눈의 위치(카메라위치) 2. 초점의 위치 3. 카메라의 위쪽방향(일반적으로Y)
	cBuffer.View = XMMatrixLookAtLH(Vector3(0.0f, 0.0f, -2.0f).Convert(), Vector3(0.0f, 0.0f, 0.0f).Convert(), Vector3::Axis[AXIS_Y].Convert());
	//프로젝션 행렬을 만든다 (일단상수) 1. 시야각, 2. 종횡비, 3. Z값이 0.03부터 1000까지 보겠다.
	cBuffer.Projection = XMMatrixPerspectiveFovLH(JEONG_PI / 3.0f, 1280.0f / 720.0f, 0.03f, 1000.0f);

	cBuffer.WV = cBuffer.World * cBuffer.View;
	cBuffer.WVP = cBuffer.WV * cBuffer.Projection;

	//쉐이더로 전해주기위하여 전치행렬로 변환한다.
	cBuffer.World.Transpose();
	cBuffer.View.Transpose();
	cBuffer.Projection.Transpose();
	cBuffer.WV.Transpose();
	cBuffer.WVP.Transpose();

	//미리 정의해놓은 버퍼(ID3D11Buffer)를 가져와서 업데이트 시킨다.
	//버텍스쉐이더와 픽셀쉐이더에 위에서 값을 가져온 행렬들을 (상수버퍼) 셋팅해준다. 
	ShaderManager::Get()->UpdateCBuffer("Transform", &cBuffer);
}
