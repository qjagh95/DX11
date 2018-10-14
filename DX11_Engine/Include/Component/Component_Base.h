#pragma once
#include "../RefCount.h"
JEONG_BEGIN

class Scene;
class Layer;
class GameObject;
class Transform_Com;
class JEONG_DLL Component_Base : public RefCount
{
public:
	virtual bool Init() = 0;
	virtual int Input(float DeltaTime);
	virtual int Update(float DeltaTime);
	virtual int LateUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void CollisionLateUpdate(float DeltaTime);
	virtual void Render(float DeltaTime);
	virtual Component_Base* Clone() = 0;

public:
	Scene* GetScene() const { return m_Scene; }
	Layer* GetLayer() const { return m_Layer; }
	GameObject* GetGameObject() const;
	Transform_Com* GetTransform() const;
	COMPONENT_TYPE GetComType() const { return m_ComType; }

protected:
	Scene* m_Scene;
	Layer* m_Layer;
	GameObject* m_Object;
	Transform_Com* m_Transform;
	COMPONENT_TYPE m_ComType;

protected:
	Component_Base();
	Component_Base(const Component_Base& copyObject);
	virtual ~Component_Base() = 0;

public:
	friend class GameObject;
};

JEONG_END

