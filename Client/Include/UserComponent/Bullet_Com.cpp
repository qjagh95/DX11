#include "Bullet_Com.h"
#include "GameObject.h"

#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"

Bullet_Com::Bullet_Com()
{
}

Bullet_Com::Bullet_Com(const Bullet_Com & userCom)
	:UserComponent_Base(userCom)
{
	*this = userCom;
}

Bullet_Com::~Bullet_Com()
{
}

bool Bullet_Com::Init()
{
	Renderer_Com* RenderComponent = m_Object->AddComponent<Renderer_Com>("BulletRender");
	RenderComponent->SetMesh("ColorTri");
	SAFE_RELEASE(RenderComponent);

	m_Transform->SetWorldScale(100.0f, 100.0f, 0.0f);

	return true;
}

int Bullet_Com::Input(float DeltaTime)
{
	return 0;
}

int Bullet_Com::Update(float DeltaTime)
{
	//생성할때 로테이션 함수에서 이미 WorldAxis변수를 갱신한다.
	m_Transform->Move(AXIS_Y, 500.0f, DeltaTime);

	if (m_Transform->GetWorldPos().x <= 0.0f)
		m_Object->SetIsActive(false);
	else if(m_Transform->GetWorldPos().x >= 1000.0f)
		m_Object->SetIsActive(false);

	if(m_Transform->GetWorldPos().y <= 0.0f)
		m_Object->SetIsActive(false);
	else if(m_Transform->GetWorldPos().y >= 700.0f)
		m_Object->SetIsActive(false);

	return 0;
}

int Bullet_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Bullet_Com::Collision(float DeltaTime)
{
}

void Bullet_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Bullet_Com::Render(float DeltaTime)
{
}

Bullet_Com * Bullet_Com::Clone()
{
	return new Bullet_Com(*this);
}
