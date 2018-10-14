#include "MainScene.h"
#include "Scene/Scene.h"
#include "scene/Layer.h"
#include "GameObject.h"
#include "Component/Transform_Com.h"
#include "Component/Renderer_Com.h"

MainScene::MainScene()
{
}

bool MainScene::Init()
{
	Layer* Default = m_Scene->FindLayer("Default");
	GameObject* newObject = GameObject::CreateObject("Player", Default);
	Renderer_Com* RenderComponent = newObject->AddComponent<Renderer_Com>("PlayerRender");

	RenderComponent->SetMesh("ColorTri");

	SAFE_RELEASE(RenderComponent);
	SAFE_RELEASE(newObject);
	SAFE_RELEASE(Default);

	return true;
}

MainScene::~MainScene()
{
}
