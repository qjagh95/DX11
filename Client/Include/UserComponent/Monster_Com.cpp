#include "Monster_Com.h"
#include "GameObject.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"

Monster_Com::Monster_Com()
	:Target(NULLPTR)
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

	m_Transform->SetWorldPos(100.0f, 100.0f, 0.0f);
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
	if (m_Transform->GetWorldPos().GetDistance(Target->GetTransform()->GetWorldPos()) < 2.0f)
		m_Transform->LookAt(Target, AXIS_Y);

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
