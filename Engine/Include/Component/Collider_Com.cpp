#include "Collider_Com.h"

JEONG_USING

Collider_Com::Collider_Com()
{
	m_CollType = CT_RECT;
}

Collider_Com::Collider_Com(const Collider_Com & CopyCollider)
	:Component_Base(CopyCollider)
{

}

Collider_Com::~Collider_Com()
{
}

bool Collider_Com::Init()
{
	return true;
}

int Collider_Com::Input(float DeltaTime)
{
	return 0;
}

int Collider_Com::Update(float DeltaTime)
{
	return 0;
}

int Collider_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Collider_Com::Collision(float DeltaTime)
{
}

void Collider_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Collider_Com::Render(float DeltaTime)
{
}
