#include "Component_Base.h"

#include "../Scene/Scene.h"
#include "../Scene/Layer.h"
#include "../GameObject.h"

#include "Transform_Com.h"

JEONG_USING

Component_Base::Component_Base()
	:m_Scene(NULLPTR), m_Layer(NULLPTR), m_Object(NULLPTR), m_Transform(NULLPTR), m_ComType(CT_NONE)
{
}

Component_Base::~Component_Base()
{
}

Component_Base::Component_Base(const Component_Base & copyObject)
{
	*this = copyObject;
}

int Component_Base::Input(float DeltaTime)
{
	return 0;
}

int Component_Base::Update(float DeltaTime)
{
	return 0;
}

int Component_Base::LateUpdate(float DeltaTime)
{
	return 0;
}

void Component_Base::Collision(float DeltaTime)
{
}

void Component_Base::CollisionLateUpdate(float DeltaTime)
{
}

void Component_Base::Render(float DeltaTime)
{
}

GameObject * Component_Base::GetGameObject() const
{
	m_Object->AddRefCount();
	return m_Object;
}
Transform_Com * Component_Base::GetTransform() const
{
	m_Transform->AddRefCount();
	return m_Transform;
}