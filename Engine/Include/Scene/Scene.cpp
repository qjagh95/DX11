#include "Scene.h"
#include "Layer.h"
#include "SceneComponent.h"

JEONG_USING

Scene::Scene()
{
}

Scene::~Scene()
{
	Safe_Release_VecList(m_LayerList);
	Safe_Release_VecList(m_SceneComponentList);

}

bool Scene::Init()
{
	AddLayer("Default", 0);
	AddLayer("UI", INT_MAX);

	return true;
}

int Scene::Input(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter ; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}

		(*StartIter1)->Input(DeltaTime);
		StartIter1++;
	}
	return 0;
}

int Scene::Update(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}
		(*StartIter1)->Update(DeltaTime);
		StartIter1++;
	}

	return 0;
}

int Scene::LateUpdate(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}

		(*StartIter1)->LateUpdate(DeltaTime);
		StartIter1++;
	}
	return 0;
}

void Scene::Collision(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}

		(*StartIter1)->Collision(DeltaTime);
		StartIter1++;
	}
}

void Scene::CollisionLateUpdate(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}

		(*StartIter1)->CollisionLateUpdate(DeltaTime);
		StartIter1++;
	}
}

void Scene::Render(float DeltaTime)
{
	list<SceneComponent*>::iterator StartIter = m_SceneComponentList.begin();
	list<SceneComponent*>::iterator EndIter = m_SceneComponentList.end();

	for (; StartIter != EndIter; )
	{
		if ((*StartIter)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter));
			StartIter = m_SceneComponentList.erase(StartIter);
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

	list<Layer*>::iterator StartIter1 = m_LayerList.begin();
	list<Layer*>::iterator EndIter1 = m_LayerList.end();

	for (; StartIter1 != EndIter1; )
	{
		if ((*StartIter1)->GetIsActive() == false)
		{
			SAFE_RELEASE((*StartIter1));
			StartIter1 = m_LayerList.erase(StartIter1);
			continue;
		}
		else if ((*StartIter1)->GetIsShow() == false)
		{
			StartIter1++;
			continue;
		}
		(*StartIter1)->Render(DeltaTime);
		StartIter1++;
	}

}

void Scene::AddLayer(const string & TagName, int ZOrder)
{
	Layer* newLayer = new Layer();
	newLayer->m_Scene = this;
	newLayer->SetTag(TagName);

	if (newLayer->Init() == false)
	{
		SAFE_RELEASE(newLayer);
		return;
	}

	m_LayerList.push_back(newLayer);
	newLayer->SetZOrder(ZOrder);
}

void Scene::ChangeLayerZOrder(const string & TagName, int ZOrder)
{
	list<Layer*>::iterator StartIter = m_LayerList.begin();
	list<Layer*>::iterator EndIter = m_LayerList.end();

	for (; StartIter != EndIter; StartIter++)
	{
		if ((*StartIter)->GetTag() == TagName)
		{
			(*StartIter)->SetZOrder(ZOrder);
			return;
		}
	}
}

void Scene::SortLayer()
{
	m_LayerList.sort(Scene::SortLayerFunc);
}

void Scene::SetEnableLayer(const string & TagName, bool isShow)
{
	list<Layer*>::iterator StartIter = m_LayerList.begin();
	list<Layer*>::iterator EndIter = m_LayerList.end();

	for (; StartIter != EndIter ; StartIter++)
	{
		if ((*StartIter)->GetTag() == TagName)
		{
			(*StartIter)->SetIsShow(isShow);
			return;
		}
	}
}

void Scene::SetLayerDie(const string & TagName, bool isActive)
{
	list<Layer*>::iterator StartIter = m_LayerList.begin();
	list<Layer*>::iterator EndIter = m_LayerList.end();

	for (; StartIter != EndIter; StartIter++)
	{
		if ((*StartIter)->GetTag() == TagName)
		{
			(*StartIter)->SetIsActive(isActive);
		}
	}
}

Layer * Scene::FindLayer(const string & TagName)
{
	list<Layer*>::iterator StartIter = m_LayerList.begin();
	list<Layer*>::iterator EndIter = m_LayerList.end();

	for (; StartIter != EndIter; StartIter++)
	{
		if ((*StartIter)->GetTag() == TagName)
		{
			(*StartIter)->AddRefCount();
			return (*StartIter);
		}
	}
	return NULLPTR;
}

bool Scene::SortLayerFunc(const Layer * Src, const Layer * Dest)
{
	return Src->GetZOrder() > Dest->GetZOrder();
}
