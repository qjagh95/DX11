#include "Player_Com.h"
#include "GameObject.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"
#include "Component/Material_Com.h"

Player_Com::Player_Com()
{
}

Player_Com::Player_Com(const Player_Com & userCom)
	:UserComponent_Base(userCom)
{
}

Player_Com::~Player_Com()
{
}

bool Player_Com::Init()
{
	Renderer_Com* RenderComponent = m_Object->AddComponent<Renderer_Com>("PlayerRender");
	RenderComponent->SetMesh("TextureRect");
	RenderComponent->SetRenderState(ALPHA_BLEND);
	SAFE_RELEASE(RenderComponent);

	Material_Com* MaterialComponent = m_Object->FindComponentFromType<Material_Com>(CT_MATERIAL);
	MaterialComponent->SetMaterial(Vector4::Yellow);
	MaterialComponent->SetDiffuseTexture(0, "Player", TEXT("Player.png"));
	SAFE_RELEASE(MaterialComponent);

	m_Transform->SetWorldScale(100.0f, 100.0f, 1.0f);
	m_Transform->SetWorldPivot(0.5f, 0.0f, 0.0f);

	return true;
}

int Player_Com::Input(float DeltaTime)
{
	Material_Com* getMaterial = m_Object->FindComponentFromType<Material_Com>(CT_MATERIAL);
	getMaterial->SetMaterial(Vector4::White);

	//���� ���鿡�� �����ְ� �׸��°� �� ���� �׸��⶧���� ����-
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_Transform->RotationZ(180.0f, DeltaTime);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		m_Transform->RotationZ(-180.0f, DeltaTime);
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_Transform->Move(AXIS_Y, 200.0f, DeltaTime);
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		m_Transform->Move(AXIS_Y, -200.0f, DeltaTime);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		GameObject* newClone = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		newClone->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		newClone->GetTransform()->Rotation(m_Transform->GetWorldRotation());
		SAFE_RELEASE(newClone);

		getMaterial->SetMaterial(Vector4::DarkCyan);
	}

	SAFE_RELEASE(getMaterial);

	return 0;
}

int Player_Com::Update(float DeltaTime)
{
	return 0;
}

int Player_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Player_Com::Collision(float DeltaTime)
{
}

void Player_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Player_Com::Render(float DeltaTime)
{
}

Player_Com * Player_Com::Clone()
{
	return new Player_Com(*this);
}
