#include "ResourceManager.h"
#include "Mesh.h"

JEONG_USING

SINGLETON_VAR_INIT(ResourceManager)

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	Safe_Release_Map(m_MeshMap);
}

bool ResourceManager::Init()
{
	VertexColor vInfo[3] =
	{
		//���������� -1 ~ 0�� ������ ���´�.
		VertexColor(Vector3(0.0f, 0.5f, 0.0f), Vector4::Azure),
		VertexColor(Vector3(0.5f, -0.5f , 0.0f), Vector4::Linen),
		VertexColor(Vector3(-0.5f, 0.5f, 0.0f), Vector4::OldLace),
	};

	unsigned short Index[3] = { 0, 1, 2 };

	CreateMesh("ColorTri", "", "", vInfo, 3, sizeof(VertexColor), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, Index, 3, 2);

	return true;
}

bool ResourceManager::CreateMesh(const string & TagName, const string & ShaderKeyName, const string & LayOutKeyName, void * vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage, D3D11_PRIMITIVE_TOPOLOGY primitiveType, void * indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat)
{
	Mesh* newMesh = FindMesh(TagName);

	if (newMesh != NULLPTR)
	{
		SAFE_RELEASE(newMesh);
		return false;
	}
	
	newMesh = new Mesh();

	if (newMesh->CreateMesh(TagName, ShaderKeyName, LayOutKeyName, vertexInfo, vertexCount, vertexSize, vertexUsage, primitiveType, indexInfo, indexCount, indexSize, indexUsage, indexFormat) == false)
	{
		SAFE_RELEASE(newMesh);
		return false;
	}

	m_MeshMap.insert(make_pair(TagName, newMesh));

	return true;
}

Mesh * ResourceManager::FindMesh(const string & TagName)
{
	unordered_map<string, Mesh*>::iterator FindIter = m_MeshMap.find(TagName);

	if (FindIter == m_MeshMap.end())
		return NULLPTR;

	FindIter->second->AddRefCount();

	return FindIter->second;
}