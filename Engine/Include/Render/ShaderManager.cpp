#include "ShaderManager.h"
#include "Shader.h"

#include "../Device.h"

JEONG_USING
SINGLETON_VAR_INIT(ShaderManager)

ShaderManager::ShaderManager() : m_InputLayOutSize(0)
{
}

ShaderManager::~ShaderManager()
{
	Safe_Release_Map(m_ShaderMap);
	Safe_Release_Map(m_LayOutMap);
}

bool ShaderManager::Init()
{
	char* Entry[ST_MAX] = {};

	//���̴����� �Լ� �̸�.
	Entry[ST_VERTEX] = "StandardColorVS";
	Entry[ST_PIXEL] = "StandardColorPS";

	if (LoadShader(STANDARD_COLOR_SHADER, TEXT("Standard.fx"), Entry) == false)
	{
		TrueAssert(true);
		return false;
	}

	AddInputElement("POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 12);
	AddInputElement("COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 16);

	if (CreateInputLayOut(POS_COLOR_LAYOUT, STANDARD_COLOR_SHADER) == false)
	{
		TrueAssert(true);
		return false;
	}

	return true;
}

bool ShaderManager::LoadShader(const string & KeyName, const TCHAR * FileName, char * Entry[ST_MAX], const string & PathKey)
{
	Shader* newShader = FindShader(KeyName);

	if (newShader != NULLPTR)
	{
		SAFE_RELEASE(newShader);
		return true;
	}

	newShader = new Shader();

	if (newShader->LoadShader(KeyName, FileName, Entry, PathKey) == false)
	{
		SAFE_RELEASE(newShader);
		return false;
	}

	m_ShaderMap.insert(make_pair(KeyName, newShader));

	return true;
}

void ShaderManager::AddInputElement(char * Semantic, int Index, DXGI_FORMAT Format, int Size, int InputSlot, D3D11_INPUT_CLASSIFICATION eInputClass, int InstanceStepRate)
{
	D3D11_INPUT_ELEMENT_DESC elementDesc;
	elementDesc.SemanticName = Semantic;				///���̴� ���Ͽ��ִ� �ø�ƽ �̸�
	elementDesc.SemanticIndex = Index;					///�ø�ƽ ���ʿ� ���ڸ� �ٿ��� �� �ִµ� �� ����
	elementDesc.AlignedByteOffset = m_InputLayOutSize;	///GPU���� �� ��Ұ� �޸𸮿��� ������������ ��ŭ�������ֳ�
	elementDesc.InputSlot = InputSlot;					///�Ⱦ����ߵ���Ʈ��
	elementDesc.InputSlotClass = eInputClass;			///�Ⱦ����ߵ���Ʈ��
	elementDesc.InstanceDataStepRate = InstanceStepRate;///�Ⱦ����ߵ���Ʈ��
	elementDesc.Format = Format;						///����R32��Ʈ...G32��Ʈ...

	m_InputLayOutSize += Size;

	m_vecInputElement.push_back(elementDesc);
}

bool ShaderManager::CreateInputLayOut(const string & InputLayoutKeyName, const string & ShaderKey)
{
	Shader* getShader = FindShader(ShaderKey);

	if (getShader == NULLPTR)
		return false;

	ID3D11InputLayout* newLayout = FindInputLayOut(InputLayoutKeyName);

	if (newLayout != NULLPTR)
	{
		TrueAssert(true);
		return false;
	}

	if (FAILED(Device::Get()->GetDevice()->CreateInputLayout(&m_vecInputElement[0], (UINT)m_vecInputElement.size(), getShader->GetVertexShaderCode(), getShader->GetVertexShaderCodeSize(), &newLayout)))
	{
		TrueAssert(true);
		return false;
	}

	SAFE_RELEASE(getShader);

	m_InputLayOutSize = 0;
	m_vecInputElement.clear();

	m_LayOutMap.insert(make_pair(InputLayoutKeyName, newLayout));

	return true;
}

Shader * ShaderManager::FindShader(const string & KeyName)
{
	unordered_map<string, Shader*>::iterator FindIter = m_ShaderMap.find(KeyName);

	if (FindIter == m_ShaderMap.end())
		return NULLPTR;

	FindIter->second->AddRefCount();

	return FindIter->second;
}

ID3D11InputLayout * ShaderManager::FindInputLayOut(const string & KeyName)
{
	unordered_map<string, ID3D11InputLayout*>::iterator FindIter = m_LayOutMap.find(KeyName);

	if (FindIter == m_LayOutMap.end())
		return NULLPTR;

	return FindIter->second;
}
