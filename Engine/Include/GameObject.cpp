#include "GameObject.h"
#include "Scene/Layer.h"
#include "Component\Transform_Com.h"

JEONG_USING

GameObject::GameObject()
	:m_Scene(NULLPTR), m_Layer(NULLPTR), m_Transform(NULLPTR)
{
	SetTag("GameObject");
}

GameObject::GameObject(const GameObject& copyObject)
{
	*this = copyObject;
	m_Transform = copyObject.m_Transform->Clone();

	m_ComponentList.clear();

	list<Component_Base*>::const_iterator StartIter = copyObject.m_ComponentList.begin();
	list<Component_Base*>::const_iterator EndIter = copyObject.m_ComponentList.end();

	for (; StartIter != EndIter ; StartIter++)
	{
		Component_Base* newComponent = (*StartIter)->Clone();
		newComponent->m_Object = this;
		newComponent->m_Transform = m_Transform;

		m_ComponentList.push_back(newComponent);
	}
}

GameObject::~GameObject()
{
	SAFE_RELEASE(m_Transform);
	Safe_Release_VecList(m_ComponentList);
}

bool GameObject::Init()
{
	m_Transform = new Transform_Com();
	m_Transform->Init();

	return true;
}

int GameObject::Input(float DeltaTime)
{
	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->Input(DeltaTime);
		StartIter++;
	}

	return 0;
}

int GameObject::Update(float DeltaTime)
{
	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->Update(DeltaTime);
		StartIter++;
	}

	m_Transform->Update(DeltaTime);

	return 0;
}

int GameObject::LateUpdate(float DeltaTime)
{
	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->LateUpdate(DeltaTime);
		StartIter++;
	}
	m_Transform->LateUpdate(DeltaTime);

	return 0;
}

void GameObject::Collision(float DeltaTime)
{
	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->Collision(DeltaTime);
		StartIter++;
	}

	m_Transform->Collision(DeltaTime);
}

void GameObject::CollisionLateUpdate(float DeltaTime)
{
	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->CollisionLateUpdate(DeltaTime);
		StartIter++;
	}

}

void GameObject::Render(float DeltaTime)
{
	m_Transform->Render(DeltaTime);

	list<Component_Base*>::iterator StartIter = m_ComponentList.begin();
	list<Component_Base*>::iterator EndIter = m_ComponentList.end();

	for (; StartIter != EndIter;)
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_ComponentList.erase(StartIter);
			continue;
		}
		else if ((*StartIter)->GetIsShow() == false)
		{
			StartIter++;
			continue;
		}
		(*StartIter)->Render(DeltaTime);
		StartIter++;
	}
}

GameObject * GameObject::Clone()
{
	return new GameObject(*this);
}

void GameObject::SetScene(Scene * scene)
{
}

void GameObject::SetLayer(Layer * layer)
{
}

GameObject * GameObject::CreateObject(const string & TagName, Layer * layer)
{
	GameObject*	newObject = new GameObject();
	newObject->SetTag(TagName);

	if (newObject->Init() == false)
	{
		SAFE_RELEASE(newObject);
		return NULLPTR;
	}

	//해당 레이어에 오브젝트 추가를 해준다.
	if (layer != NULLPTR)
		layer->AddObject(newObject);

	return newObject;
}

Component_Base * GameObject::AddComponent(Component_Base * component)
{
	component->m_Scene = m_Scene;
	component->m_Layer = m_Layer;
	component->m_Transform = m_Transform;
	component->m_Object = this;
	component->AddRefCount();

	m_ComponentList.push_back(component);

	return component;
}
