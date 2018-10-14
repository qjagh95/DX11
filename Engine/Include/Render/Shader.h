#pragma once
#include "../RefCount.h"

JEONG_BEGIN

class JEONG_DLL Shader : public RefCount
{
public:
	bool LoadShader(const string& shaderName, const TCHAR* FileName, char* Entry[ST_MAX], const string& PathKey = SHADER_PATH);

private:
	ID3DBlob* m_VsBlob;
	ID3DBlob* m_PsBlob;
	ID3D11VertexShader* m_Vs;
	ID3D11PixelShader* m_Ps;
	
	string m_ShaderName;

private:
	Shader();
	~Shader();
};

JEONG_END

