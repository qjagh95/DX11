#include "Shader.h"
#include "../PathManager.h"

JEONG_USING

Shader::Shader()
 : m_VsBlob(NULLPTR), m_PsBlob(NULLPTR), m_Vs(NULLPTR), m_Ps(NULLPTR)
{	
}

Shader::~Shader()
{
	SAFE_RELEASE(m_VsBlob);
	SAFE_RELEASE(m_PsBlob);
	SAFE_RELEASE(m_Vs);
	SAFE_RELEASE(m_Ps);
}

bool Shader::LoadShader(const string & shaderName, const TCHAR * FileName, char * Entry[ST_MAX], const string & PathKey)
{
	m_ShaderName = shaderName;
	const TCHAR* pPath = PathManager::Get()->FindPath(PathKey);

	wstring	FullPath;

	if (pPath != NULLPTR)
		FullPath = pPath;
	FullPath += FileName;

	//HLSL파일을 컴파일한다.
	//D3DCompileFromFile(FullPath.c_str(), NULLPTR, D3D_COMPILE_STANDARD_FILE_INCLUDE, );

	return true;
}
