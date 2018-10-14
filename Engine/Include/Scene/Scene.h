#pragma once
#include "../RefCount.h"
JEONG_BEGIN

class Layer;
class SceneComponent;
class JEONG_DLL Scene : public RefCount
{
public:
	bool Init();
	int Input(float DeltaTime);
	int Update(float DeltaTime);
	int LateUpdate(float DeltaTime);
	void Collision(float DeltaTime);
	void CollisionLateUpdate(float DeltaTime);
	void Render(float DeltaTime);

	void AddLayer(const string& TagName, int ZOrder);
	void ChangeLayerZOrder(const string& TagName, int ZOrder);
	void SortLayer();
	void SetEnableLayer(const string& TagName, bool isShow);
	void SetLayerDie(const string& TagName, bool isActive);
	Layer* FindLayer(const string& TagName);

	template<typename T>
	bool AddSceneComponent(const string& TagName)
	{
		T* newCom = new T();

		newCom->SetTag(TagName);
		newCom->m_Scene = this;

		if (newCom->Init() == false)
		{
			SAFE_RELEASE(newCom);
			return false;
		}

		m_SceneComponentList.push_back(newCom);
		return true;
	}

private:
	list<Layer*> m_LayerList;
	list<SceneComponent*> m_SceneComponentList;

private:
	Scene();
	~Scene();

public:
	static bool SortLayerFunc(const Layer* Src, const Layer* Dest);
	friend class SceneManager;
};

JEONG_END