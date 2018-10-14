#pragma once
#include "../RefCount.h"

JEONG_BEGIN
//샘플러는 필터링방법을 정의해 주는것이다. 
//필터링은 이미지의 확대 축소가 거의 대부분 일어날 수 밖에없기때문에
//어떤식으로 보정해주느냐를 설정해주는 것.
class Sampler : public RefCount
{
public:
	//어떻게 필터링 할 것인가에 대한 방법 (퀄리티가 높을수록 느리다)
	//비등방성 = 하급
	//선형필터링 = 중급
	//포인트필터링 = 고급
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