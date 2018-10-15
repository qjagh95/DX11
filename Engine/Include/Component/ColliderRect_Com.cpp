#include "ColliderRect_Com.h"

JEONG_USING

ColliderRect_Com::ColliderRect_Com()
{
	m_CollType = CT_RECT;
}

ColliderRect_Com::ColliderRect_Com(const ColliderRect_Com & CopyCollider)
	:Collider_Com(CopyCollider)
{
	m_Virtual = CopyCollider.m_Virtual;
}

ColliderRect_Com::~ColliderRect_Com()
{
}

bool ColliderRect_Com::Init()
{
	return true;
}

int ColliderRect_Com::Input(float DeltaTime)
{
	return 0;
}

int ColliderRect_Com::Update(float DeltaTime)
{
	return 0;
}

int ColliderRect_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void ColliderRect_Com::Collision(float DeltaTime)
{
}

void ColliderRect_Com::CollisionLateUpdate(float DeltaTime)
{
}

void ColliderRect_Com::Render(float DeltaTime)
{
}

ColliderRect_Com * ColliderRect_Com::Clone()
{
	return new ColliderRect_Com(*this);
}
