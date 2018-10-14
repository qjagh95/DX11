#pragma once
#include "../RefCount.h"

JEONG_BEGIN
//���÷��� ���͸������ ������ �ִ°��̴�. 
//���͸��� �̹����� Ȯ�� ��Ұ� ���� ��κ� �Ͼ �� �ۿ����⶧����
//������� �������ִ��ĸ� �������ִ� ��.
class Sampler : public RefCount
{
public:
	//��� ���͸� �� ���ΰ��� ���� ��� (����Ƽ�� �������� ������)
	//���漺 = �ϱ�
	//�������͸� = �߱�
	//����Ʈ���͸� = ���
	bool CreateSampler(const string& TagName, D3D11_FILTER eFilter = D3D11_FILTER_MIN_MAG_MIP_LINEAR, D3D11_TEXTURE_ADDRESS_MODE eU = D3D11_TEXTURE_ADDRESS_WRAP, D3D11_TEXTURE_ADDRESS_MODE eV = D3D11_TEXTURE_ADDRESS_WRAP, D3D11_TEXTURE_ADDRESS_MODE eW = D3D11_TEXTURE_ADDRESS_WRAP);
	void SetSampler(int RegisterNumber);

private:
	ID3D11SamplerState* m_SamplerState;

private:
	Sampler();
	~Sampler();
	
public:
	friend class ResourceManager;
};

JEONG_END