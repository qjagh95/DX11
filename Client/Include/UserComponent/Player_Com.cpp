#include "Player_Com.h"
#include "GameObject.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"

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
	RenderComponent->SetMesh("ColorTri");
	SAFE_RELEASE(RenderComponent);

	return true;
}

int Player_Com::Input(float DeltaTime)
{
	//나는 정면에서 보고있고 그리는건 앞 에서 그리기때문에 -
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
		m_Transform->Move(AXIS_Y, 2.0f, DeltaTime);
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_Transform->Move(AXIS_Y, -2.0f, DeltaTime);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		GameObject* newClone = GameObject::CreateClone("BulletObject", "Bullet_Clone", m_Layer);
		newClone->GetTransform()->Rotation(m_Transform->GetWorldRotation());
		newClone->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());
		SAFE_RELEASE(newClone);
	}

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
