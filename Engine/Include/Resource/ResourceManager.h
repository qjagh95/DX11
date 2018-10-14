#pragma once
#include "../stdafx.h"
JEONG_BEGIN

class Mesh;
class JEONG_DLL ResourceManager
{
public:
	bool Init();
	bool CreateMesh(const string& TagName, const string& ShaderKeyName, const string& LayOutKeyName, void* vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage, D3D11_PRIMITIVE_TOPOLOGY primitiveType, void* indexInfo = NULLPTR, int indexCount = 0, int indexSize = 0, D3D11_USAGE indexUsage = D3D11_USAGE_DEFAULT, DXGI_FORMAT indexFormat = DXGI_FORMAT_R16_UINT);

	Mesh* FindMesh(const string& TagName);

private:
	unordered_map<string, Mesh*> m_MeshMap;

public:
	CLASS_IN_SINGLE(ResourceManager)
};

JEONG_END

