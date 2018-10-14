#include "Monster_Com.h"
#include "GameObject.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"

#include "../UserComponent/Bullet_Com.h"

Monster_Com::Monster_Com()
	:Target(NULLPTR), TimeVar(0.0f)
{
}

Monster_Com::Monster_Com(const Monster_Com & userCom)
	:UserComponent_Base(userCom)
{
}

Monster_Com::~Monster_Com()
{
	SAFE_RELEASE(Target);
}

bool Monster_Com::Init()
{
	Renderer_Com* RenderComponent = m_Object->AddComponent<Renderer_Com>("MonsterRender");
	RenderComponent->SetMesh("ColorTri");
	SAFE_RELEASE(RenderComponent);

	m_Transform->SetWorldPos(600.0f, 500.0f, 0.0f);
	m_Transform->SetWorldScale(100.0f, 100.0f, 1.0f);

	Target = GameObject::FindObject("Player");

	return true;
}

int Monster_Com::Input(float DeltaTime)
{
	return 0;
}

int Monster_Com::Update(float DeltaTime)
{
	if (m_Transform->GetWorldPos().GetDistance(Target->GetTransform()->GetWorldPos()) < 300.0f)
		m_Transform->LookAt(Target, AXIS_Y);

	TimeVar += DeltaTime;

	if (TimeVar >= 1.0f)
	{
		GameObject* newBullet = GameObject::CreateClone("Bullet", "Bullet_Clone", m_Layer);
		newBullet->SetMoveDir(MD_DOWN);
		newBullet->GetTransform()->SetWorldPos(m_Transform->GetWorldPos());

		Vector3 Look = Target->GetTransform()->GetWorldPos() - m_Transform->GetWorldPos();
		Vector3 ShotDir = newBullet->GetTransform()->GetWorldAxis(AXIS_Y);
		float Angle = ShotDir.GetAngle(Look);

		//외적으로 앞뒤판단.
		Vector3 Cross = ShotDir.Cross(Look);
		Cross.Nomallize();

		newBullet->GetTransform()->RotationZ(Angle * Cross.z);

		SAFE_RELEASE(newBullet);
		TimeVar = 0.0f; 
	}

	return 0;
}

int Monster_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Monster_Com::Collision(float DeltaTime)
{
}

void Monster_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Monster_Com::Render(float DeltaTime)
{
}

Monster_Com * Monster_Com::Clone()
{
	return new Monster_Com(*this);
}
