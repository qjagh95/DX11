#include "RenderManager.h"
#include "ShaderManager.h"

JEONG_USING
SINGLETON_VAR_INIT(RenderManager)

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	ShaderManager::Delete();
}

bool RenderManager::Init()
{
	if (ShaderManager::Get()->Init() == false)
	{
		TrueAssert(true);
		return false;
	}

	return true;
}
