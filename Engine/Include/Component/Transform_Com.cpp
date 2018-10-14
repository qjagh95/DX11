#include "Transform_Com.h"

JEONG_USING

Transform_Com::Transform_Com()
{
	m_ComType = CT_TRANSFORM;
}

Transform_Com::Transform_Com(const Transform_Com& copyObject)
	:Component_Base(copyObject)
{
	
}

Transform_Com::~Transform_Com()
{
}

bool Transform_Com::Init()
{
	return true;
}

int Transform_Com::Input(float DeltaTime)
{
	return 0;
}

int Transform_Com::Update(float DeltaTime)
{
	return 0;
}

int Transform_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Transform_Com::Collision(float DeltaTime)
{
}

void Transform_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Transform_Com::Render(float DeltaTime)
{
}

Transform_Com * Transform_Com::Clone()
{
	return new Transform_Com(*this);
}
