#pragma once
#include "../stdafx.h"

JEONG_BEGIN

class Shader;
class JEONG_DLL ShaderManager
{
public:
	bool Init();

private:
	unordered_map<string, Shader*> m_ShaderMap;

public:
	CLASS_IN_SINGLE(ShaderManager)
};

JEONG_END

