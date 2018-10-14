#pragma once
#include "RefCount.h"
JEONG_BEGIN

class Layer;
class Scene;
class Component_Base;
class Transform_Com;
class JEONG_DLL GameObject : public RefCount
{
public:
	bool Init();
	int Input(float DeltaTime);
	int Update(float DeltaTime);
	int LateUpdate(float DeltaTime);
	void Collision(float DeltaTime);
	void CollisionLateUpdate(float DeltaTime);
	void Render(float DeltaTime);
	GameObject* Clone(); //클론은 디자인패턴의 프로토타입패턴.

	Scene* GetScene() const { return m_Scene; }
	Layer* GetLayer() const { return m_Layer; }

	void SetScene(Scene* scene);
	void SetLayer(Layer* layer);

	static GameObject* CreateObject(const string& TagName, Layer* layer = NULLPTR);
	Transform_Com* GetTransform() const { return m_Transform; }

	Component_Base* AddComponent(Component_Base* component);
	template<typename T>
	T* AddComponent(const string& TagName)
	{
		T* newComponent = new T();
		newComponent->SetTag(TagName);
		newComponent->m_Scene = m_Scene;
		newComponent->m_Layer = m_Layer;
		newComponent->m_Transform = m_Transform;
		newComponent->m_Object = this;

		if (newComponent->Init() == false)
		{
			SAFE_RELEASE(newComponent);
			return NULLPTR;
		}
		return (T*)AddComponent(newComponent)
	}

private:
	list<Component_Base*> m_ComponentList;
	Transform_Com* m_Transform;
	Scene* m_Scene;
	Layer* m_Layer;

private:
	GameObject();
	GameObject(const GameObject& copyObject);
	~GameObject();
};

JEONG_END

