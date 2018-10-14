#pragma once
#include "../stdafx.h"
#include "../RefCount.h"

JEONG_BEGIN

struct JEONG_DLL VertexBuffer
{
	ID3D11Buffer* vBuffer;  ///���۰�ü
	void* vInfo;			///���ؽ� ������ ���� void* 
	int vCount;				///���ؽ� ����
	int vSize;				///���ؽ� ������
	D3D11_USAGE vUsage;		///��� ���?? (�������, �����Ұ����...)

	VertexBuffer() : vBuffer(NULLPTR), vInfo(NULLPTR), vCount(0), vSize(0), vUsage(D3D11_USAGE_DEFAULT) {}
};

struct JEONG_DLL IndexBuffer
{
	ID3D11Buffer* iBuffer;		///���۰�ü
	void* iInfo;				///�ε��� ������ ���� void* 
	int iCount;					///�ε��� ����
	int iSize;					///�ε��� ������
	D3D11_USAGE iUsage;			///��� ���?? (�������, �����Ұ����...)
	DXGI_FORMAT iFormat;		///���� (R16 = 16��Ʈ) �ϳ��� �޽��� �ε��� ������ ������ 65535�� ����ϰڴ�.

	//DXGI_FORMAT_R16_UINT (16��Ʈ) 2����Ʈ ������ŭ �������� ����. (65535��)
	IndexBuffer() : iBuffer(NULLPTR), iInfo(NULLPTR), iCount(0), iSize(0), iUsage(D3D11_USAGE_DEFAULT), iFormat(DXGI_FORMAT_R16_UINT) {}
};

//������� ġ�ڸ� ��, ����, �ٸ�, �Ӹ� -> �����̳�
//(��)�̶�� �����̳� �ȿ� ��� �ߴ� �ϴ��� �����
//-> ū ���ؽ� ���۾ȿ� �ε������۰� �������ִ²�.
struct JEONG_DLL MeshContainer
{
	VertexBuffer vertexBuffer;
	vector<IndexBuffer> vecIndexBuffer;
	//triangle "list", triangle "strip"
	D3D11_PRIMITIVE_TOPOLOGY PrimitiveType;
};

class Mesh : public RefCount
{
public:
	bool CreateMesh(const string& TagName, const string& ShaderKeyName, const string& LayOutKeyName, void* vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage, D3D11_PRIMITIVE_TOPOLOGY primitiveType, void* indexInfo = NULLPTR, int indexCount = 0,	int indexSize = 0, D3D11_USAGE indexUsage = D3D11_USAGE_DEFAULT, DXGI_FORMAT indexFormat = DXGI_FORMAT_R16_UINT);
	void Render();

private:
	vector<MeshContainer*> m_vecMeshContainer;
	string m_ShaderKeyName;

private:
	Mesh();
	~Mesh();

	bool CreateVertexBuffer(void* vertexInfo , int vertexCount , int vertexSize, D3D11_USAGE vertexUsage);
	bool CreateIndexBuffer(void* indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat);

public:
	friend class ResourceManager;
};

JEONG_END

