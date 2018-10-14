#include "ShaderManager.h"

JEONG_USING
SINGLETON_VAR_INIT(ShaderManager)

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
	Safe_Release_Map(m_ShaderMap);
}

bool ShaderManager::Init()
{
	return true;
}
