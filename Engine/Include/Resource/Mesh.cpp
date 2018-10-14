#include "Mesh.h"
#include "../Device.h"

JEONG_USING

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
	for (size_t i = 0; i < m_vecMeshContainer.size(); i++)
	{
		SAFE_RELEASE(m_vecMeshContainer[i]->vertexBuffer.vBuffer);
		SAFE_DELETE_ARRARY(m_vecMeshContainer[i]->vertexBuffer.vInfo);

		for (size_t j = 0; j < m_vecMeshContainer[i]->vecIndexBuffer.size(); j++)
		{
			SAFE_RELEASE(m_vecMeshContainer[i]->vecIndexBuffer[j].iBuffer);
			SAFE_DELETE_ARRARY(m_vecMeshContainer[i]->vecIndexBuffer[j].iInfo);
		}
		SAFE_DELETE(m_vecMeshContainer[i]);
	}

	m_vecMeshContainer.clear();
}

void Mesh::Render()
{
	for (size_t i = 0; i < m_vecMeshContainer.size(); i++)
	{
		//���� �������� �����Ѵ�.
		Device::Get()->GetContext()->IASetPrimitiveTopology(m_vecMeshContainer[i]->PrimitiveType);

		//��Ʈ���̵� : �ش� ���ؽ����ۿ��� ���� ũ��(������)
		UINT Stride = m_vecMeshContainer[i]->vertexBuffer.vSize;
		UINT Offset = 0;
		//���ؽ����۸� �����Ѵ�. (���ؽ� ���̴��� ���������� �ִ� �غ� �Ѵ�. (�Է� �������Ϳ� �ִ´�)
		Device::Get()->GetContext()->IASetVertexBuffers(0, 1, &m_vecMeshContainer[i]->vertexBuffer.vBuffer, &Stride, &Offset);
		//�ε������۰� �ִ��� üũ�Ѵ�.
		if (m_vecMeshContainer[i]->vecIndexBuffer.empty())
		{
			//���ٸ� ���ؽ����۷� �׸�
			Device::Get()->GetContext()->Draw(m_vecMeshContainer[i]->vertexBuffer.vCount, 0);
		}
		else
		{
			//�ε������۰� �ִٸ� �ε����� �׸� ���� ���� �� �ε����� �׸�.
			for (size_t j = 0; j < m_vecMeshContainer[i]->vecIndexBuffer.size(); j++)
			{
				//���̴��� ���������� �ִ��غ� �Ѵ�(�Է� �������Ϳ� �ִ´�)
				Device::Get()->GetContext()->IASetIndexBuffer(m_vecMeshContainer[i]->vecIndexBuffer[j].iBuffer, m_vecMeshContainer[i]->vecIndexBuffer[j].iFormat, 0);
				Device::Get()->GetContext()->DrawIndexed(m_vecMeshContainer[i]->vecIndexBuffer[j].iCount, 0, 0); ///�ε��������� ����, ��ġ(ù��°), �߰��Ǵ°�(0)
			}
		}
	}
}

bool Mesh::CreateMesh(const string & TagName, const string & ShaderKeyName, const string & LayOutKeyName, void * vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage, D3D11_PRIMITIVE_TOPOLOGY primitiveType, void * indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat)
{
	SetTag(TagName);
	m_ShaderKeyName = ShaderKeyName;

	MeshContainer* newContainer = new MeshContainer();
	newContainer->PrimitiveType = primitiveType;

	m_vecMeshContainer.push_back(newContainer);

	if (CreateVertexBuffer(vertexInfo, vertexCount, vertexSize, vertexUsage) == false)
		return false;
	if (CreateIndexBuffer(indexInfo, indexCount, indexSize, indexUsage, indexFormat) == false)
		return false;

	return true;
}

bool Mesh::CreateVertexBuffer(void * vertexInfo, int vertexCount, int vertexSize, D3D11_USAGE vertexUsage)
{
	//�׻� �������� �߰��� ���� �����´�.
	MeshContainer* getContainer = m_vecMeshContainer[m_vecMeshContainer.size() - 1];
	getContainer->vertexBuffer.vCount = vertexCount;
	getContainer->vertexBuffer.vInfo = new char[vertexSize * vertexCount];
	getContainer->vertexBuffer.vUsage = vertexUsage;
	getContainer->vertexBuffer.vSize = vertexSize;

	memcpy(getContainer->vertexBuffer.vInfo, vertexInfo, sizeof(vertexSize * vertexCount));

	D3D11_BUFFER_DESC bufferDesc = {}; ///������ ������ �����Ѵ�
	bufferDesc.ByteWidth = vertexSize * vertexCount; ///�� ����Ʈ��
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; ///�����뵵�ξ�����?
	bufferDesc.Usage = vertexUsage; ///������?

	if (vertexUsage == D3D11_USAGE_DYNAMIC)
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA SubResourceData = {};
	SubResourceData.pSysMem = getContainer->vertexBuffer.vInfo; ///���ؽ������� ����

	if (FAILED(Device::Get()->GetDevice()->CreateBuffer(&bufferDesc, &SubResourceData, &getContainer->vertexBuffer.vBuffer)))
		return false;

	return true;
}

bool Mesh::CreateIndexBuffer(void * indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat)
{
	//�׻� �������� �߰��� ���� �����´�.
	MeshContainer* getContainer = m_vecMeshContainer[m_vecMeshContainer.size() - 1];

	IndexBuffer TempIndexBuffer;

	TempIndexBuffer.iCount = indexCount;
	TempIndexBuffer.iInfo = new char[indexSize * indexCount];
	TempIndexBuffer.iUsage = indexUsage;
	TempIndexBuffer.iSize = indexSize;

	memcpy(TempIndexBuffer.iInfo, indexInfo, sizeof(indexSize * indexCount));

	D3D11_BUFFER_DESC bufferDesc = {}; ///������ ������ �����Ѵ�
	bufferDesc.ByteWidth = indexSize * indexCount; ///�� ����Ʈ��
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER; ///�����뵵�ξ�����?
	bufferDesc.Usage = indexUsage; ///������?

	if (indexUsage == D3D11_USAGE_DYNAMIC)
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA SubResourceData = {};
	SubResourceData.pSysMem = TempIndexBuffer.iInfo; ///�ε��������� ����

	if (FAILED(Device::Get()->GetDevice()->CreateBuffer(&bufferDesc, &SubResourceData, &TempIndexBuffer.iBuffer)))
		return false;

	getContainer->vecIndexBuffer.push_back(TempIndexBuffer);

	return true;
}

