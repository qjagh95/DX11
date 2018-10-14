#include "ResourceManager.h"
#include "Mesh.h"
#include "Texture.h"
#include "Sampler.h"

JEONG_USING

SINGLETON_VAR_INIT(ResourceManager)

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	Safe_Release_Map(m_MeshMap);
	Safe_Release_Map(m_TextureMap);
	Safe_Release_Map(m_SamplerMap);
}

bool ResourceManager::Init()
{
	VertexColor vInfo[3] =
	{
		//���������� -1 ~ 0�� ������ ���´�.
		VertexColor(Vector3(0.0f, 0.5f, 0.0f), Vector4::Chartreuse),
		VertexColor(Vector3(0.5f, -0.5f , 0.0f), Vector4::DarkOrchid),
		VertexColor(Vector3(-0.5f, -0.5f, 0.0f), Vector4::DarkGreen),
	};

	unsigned short IndexTri[3] = { 0, 1, 2 };

	VertexColor vInfoRect[4] =
	{
		//���������� -1 ~ 0�� ������ ���´�.
		VertexColor(Vector3(0.0f, 1.0f, 0.0f), Vector4::Red),
		VertexColor(Vector3(1.0f, 1.0f, 0.0f), Vector4::MediumSpringGreen),
		VertexColor(Vector3(0.0f, 0.0f, 0.0f), Vector4::Purple),
		VertexColor(Vector3(1.0f, 0.0f, 0.0f), Vector4::SteelBlue)
	};

	unsigned short IndexRect[6] = { 0, 1, 3, 0, 3, 2 };

	CreateMesh("ColorTri", STANDARD_COLOR_SHADER, POS_COLOR_LAYOUT, vInfo, 3, sizeof(VertexColor), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, IndexTri, 3, 2);
	CreateMesh("ColorRect", STANDARD_COLOR_SHADER, POS_COLOR_LAYOUT, vInfoRect, 4, sizeof(VertexColor), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, IndexRect, 6, 2);

	VertexUV TexRect[4] =
	{
		VertexUV(Vector3(0.f, 1.f, 0.f), Vector2(0.f, 0.f)),
		VertexUV(Vector3(1.f, 1.f, 0.f), Vector2(1.f, 0.f)),
		VertexUV(Vector3(0.f, 0.f, 0.f), Vector2(0.f, 1.f)),
		VertexUV(Vector3(1.f, 0.f, 0.f), Vector2(1.f, 1.f))
	};

	CreateMesh("UVRect", STANDARD_UV_SHADER, POS_UV_LAYOUT, vInfoRect, 4, sizeof(VertexUV), D3D11_USAGE_DEFAULT, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST, IndexRect, 6, 2);

	CreateTexture("Yso", TEXT("Yso.jpg"));
	CreateSampler(LINER_SAMPLER);	

	return true;
}

bool ResourceManager::CreateMesh(const string & KeyName, const string & ShaderKeyName, const string & LayOutKeyName, void * vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage, D3D11_PRIMITIVE_TOPOLOGY primitiveType, void * indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat)
{
	Mesh* newMesh = FindMesh(KeyName);

	if (newMesh != NULLPTR)
	{
		SAFE_RELEASE(newMesh);
		return false;
	}
	
	newMesh = new Mesh();

	if (newMesh->CreateMesh(KeyName, ShaderKeyName, LayOutKeyName, vertexInfo, vertexCount, vertexSize, vertexUsage, primitiveType, indexInfo, indexCount, indexSize, indexUsage, indexFormat) == false)
	{
		SAFE_RELEASE(newMesh);
		return false;
	}

	m_MeshMap.insert(make_pair(KeyName, newMesh));

	return true;
}

bool ResourceManager::CreateTexture(const string & KeyName, const TCHAR * FileName, const string & PathKey)
{
	Texture* newTexture = FindTexture(KeyName);

	if (newTexture != NULLPTR)
	{
		SAFE_RELEASE(newTexture);
		return false;
	}

	newTexture = new Texture();

	if (newTexture->LoadTexture(KeyName, FileName, PathKey) == false)
	{
		SAFE_RELEASE(newTexture);
		return false;
	}

	m_TextureMap.insert(make_pair(KeyName, newTexture));
	return true;
}

bool ResourceManager::CreateTextureFromFullPath(const string & KeyName, const TCHAR * FullPath)
{
	Texture* newTexture = FindTexture(KeyName);

	if (newTexture != NULLPTR)
	{
		SAFE_RELEASE(newTexture);
		return false;
	}

	newTexture = new Texture();

	if (newTexture->LoadTextureFromFullPath(KeyName, FullPath) == false)
	{
		SAFE_RELEASE(newTexture);
		return false;
	}

	m_TextureMap.insert(make_pair(KeyName, newTexture));

	return true;
}

bool ResourceManager::CreateSampler(const string & KeyName, D3D11_FILTER eFilter, D3D11_TEXTURE_ADDRESS_MODE eU, D3D11_TEXTURE_ADDRESS_MODE eV, D3D11_TEXTURE_ADDRESS_MODE eW)
{
	Sampler* newSampler = FindSampler(KeyName);

	if (newSampler != NULLPTR)
	{
		SAFE_RELEASE(newSampler);
		return false;
	}

	newSampler = new Sampler();

	if (newSampler->CreateSampler(KeyName, eFilter, eU, eV, eW) == false)
	{
		SAFE_RELEASE(newSampler);
		return false;
	}

	m_SamplerMap.insert(make_pair(KeyName, newSampler));

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

Texture * ResourceManager::FindTexture(const string & KeyName)
{
	unordered_map<string, Texture*>::iterator FindIter = m_TextureMap.find(KeyName);

	if (FindIter == m_TextureMap.end())
		return NULLPTR;

	FindIter->second->AddRefCount();

	return FindIter->second;
}

Sampler * ResourceManager::FindSampler(const string & KeyName)
{
	unordered_map<string, Sampler*>::iterator FindIter = m_SamplerMap.find(KeyName);

	if (FindIter == m_SamplerMap.end())
		return NULLPTR;

	FindIter->second->AddRefCount();

	return FindIter->second;
}
