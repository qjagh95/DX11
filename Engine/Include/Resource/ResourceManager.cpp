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
		//투영공간은 -1 ~ 0의 범위를 갖는다.
		VertexColor(Vector3(0.0f, 0.5f, 0.0f), Vector4::Chartreuse),
		VertexColor(Vector3(0.5f, -0.5f , 0.0f), Vector4::DarkOrchid),
		VertexColor(Vector3(-0.5f, -0.5f, 0.0f), Vector4::DarkGreen),
	};

	unsigned short IndexTri[3] = { 0, 1, 2 };

	VertexColor vInfoRect[4] =
	{
		//투영공간은 -1 ~ 0의 범위를 갖는다.
		VertexColor(Vector3(0.0f, 1.0f, 0.0f), Vector4::Red),
		VertexColor(Vector3(1.0f, 1.0f, 0.0f), Vector4::MediumSpringGreen),
		VertexColor(Vector3(0.0f, 0.0f, 0.0f), Vector4::Purple),
		VertexColor(Vector3(1.0f, 0.0f, 0.0f), Vector4::SteelBlue)
	};

	unsigned short IndexRect[6] = { 0, 1, 3, 0, 3, 2 };

	CreateMesh("ColorTri", STANDARD_COLOR_SHADER, POS_COLOR_LAYOUT, vInfo, 3, sizeof(VertexColor), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, IndexTri, 3, 2);
	CreateMesh("ColorRect", STANDARD_COLOR_SHADER, POS_COLOR_LAYOUT, vInfoRect, 4, sizeof(VertexColor), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, IndexRect, 6, 2);

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
