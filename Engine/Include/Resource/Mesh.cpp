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
		//도형 위상구조를 지정한다.
		Device::Get()->GetContext()->IASetPrimitiveTopology(m_vecMeshContainer[i]->PrimitiveType);

		//스트라이드 : 해당 버텍스버퍼에서 사용될 크기(사이즈)
		UINT Stride = m_vecMeshContainer[i]->vertexBuffer.vSize;
		UINT Offset = 0;
		//버텍스버퍼를 셋팅한다. (버텍스 쉐이더에 정점정보를 넣는 준비를 한다. (입력 레지스터에 넣는다)
		Device::Get()->GetContext()->IASetVertexBuffers(0, 1, &m_vecMeshContainer[i]->vertexBuffer.vBuffer, &Stride, &Offset);
		//인덱스버퍼가 있는지 체크한다.
		if (m_vecMeshContainer[i]->vecIndexBuffer.empty())
		{
			//없다면 버텍스버퍼로 그림
			Device::Get()->GetContext()->Draw(m_vecMeshContainer[i]->vertexBuffer.vCount, 0);
		}
		else
		{
			//인덱스버퍼가 있다면 인덱스를 그릴 순서 지정 후 인덱스로 그림.
			for (size_t j = 0; j < m_vecMeshContainer[i]->vecIndexBuffer.size(); j++)
			{
				//쉐이더에 정점정보를 넣는준비를 한다(입력 레지스터에 넣는다)
				Device::Get()->GetContext()->IASetIndexBuffer(m_vecMeshContainer[i]->vecIndexBuffer[j].iBuffer, m_vecMeshContainer[i]->vecIndexBuffer[j].iFormat, 0);
				Device::Get()->GetContext()->DrawIndexed(m_vecMeshContainer[i]->vecIndexBuffer[j].iCount, 0, 0); ///인덱스버퍼의 갯수, 위치(첫번째), 추가되는값(0)
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
	//항상 마지막에 추가된 것을 가져온다.
	MeshContainer* getContainer = m_vecMeshContainer[m_vecMeshContainer.size() - 1];
	getContainer->vertexBuffer.vCount = vertexCount;
	getContainer->vertexBuffer.vInfo = new char[vertexSize * vertexCount];
	getContainer->vertexBuffer.vUsage = vertexUsage;
	getContainer->vertexBuffer.vSize = vertexSize;

	memcpy(getContainer->vertexBuffer.vInfo, vertexInfo, sizeof(vertexSize * vertexCount));

	D3D11_BUFFER_DESC bufferDesc = {}; ///버퍼의 정보를 설정한다
	bufferDesc.ByteWidth = vertexSize * vertexCount; ///총 바이트수
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; ///무슨용도로쓸꺼야?
	bufferDesc.Usage = vertexUsage; ///어떻게출력?

	if (vertexUsage == D3D11_USAGE_DYNAMIC)
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA SubResourceData = {};
	SubResourceData.pSysMem = getContainer->vertexBuffer.vInfo; ///버텍스버퍼의 정보

	if (FAILED(Device::Get()->GetDevice()->CreateBuffer(&bufferDesc, &SubResourceData, &getContainer->vertexBuffer.vBuffer)))
		return false;

	return true;
}

bool Mesh::CreateIndexBuffer(void * indexInfo, int indexCount, int indexSize, D3D11_USAGE indexUsage, DXGI_FORMAT indexFormat)
{
	//항상 마지막에 추가된 것을 가져온다.
	MeshContainer* getContainer = m_vecMeshContainer[m_vecMeshContainer.size() - 1];

	IndexBuffer TempIndexBuffer;

	TempIndexBuffer.iCount = indexCount;
	TempIndexBuffer.iInfo = new char[indexSize * indexCount];
	TempIndexBuffer.iUsage = indexUsage;
	TempIndexBuffer.iSize = indexSize;

	memcpy(TempIndexBuffer.iInfo, indexInfo, sizeof(indexSize * indexCount));

	D3D11_BUFFER_DESC bufferDesc = {}; ///버퍼의 정보를 설정한다
	bufferDesc.ByteWidth = indexSize * indexCount; ///총 바이트수
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER; ///무슨용도로쓸꺼야?
	bufferDesc.Usage = indexUsage; ///어떻게출력?

	if (indexUsage == D3D11_USAGE_DYNAMIC)
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	D3D11_SUBRESOURCE_DATA SubResourceData = {};
	SubResourceData.pSysMem = TempIndexBuffer.iInfo; ///인덱스버퍼의 정보

	if (FAILED(Device::Get()->GetDevice()->CreateBuffer(&bufferDesc, &SubResourceData, &TempIndexBuffer.iBuffer)))
		return false;

	getContainer->vecIndexBuffer.push_back(TempIndexBuffer);

	return true;
}

