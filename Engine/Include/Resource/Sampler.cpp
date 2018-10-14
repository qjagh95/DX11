#include "Sampler.h"
#include "../Device.h"

JEONG_USING

Sampler::Sampler()
	:m_SamplerState(NULLPTR)
{
}

Sampler::~Sampler()
{
	SAFE_RELEASE(m_SamplerState);
}

bool Sampler::CreateSampler(const string & TagName, D3D11_FILTER eFilter, D3D11_TEXTURE_ADDRESS_MODE eU, D3D11_TEXTURE_ADDRESS_MODE eV, D3D11_TEXTURE_ADDRESS_MODE eW)
{
	SetTag(TagName);

	D3D11_SAMPLER_DESC SamplerDesc = {};
	SamplerDesc.Filter = eFilter;
	SamplerDesc.AddressU = eU;
	SamplerDesc.AddressV = eV;
	SamplerDesc.AddressW = eW;
	SamplerDesc.MinLOD = -FLT_MAX;
	SamplerDesc.MaxLOD = FLT_MAX;
	SamplerDesc.MipLODBias = 0.0f; //테셀레이션 (버텍스를 쪼개거나 할때 사용)
	SamplerDesc.MaxAnisotropy = 1;
	SamplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;

	float f = 1.0f;
	memcpy(SamplerDesc.BorderColor, &f, sizeof(float) * 4);

	if (FAILED(Device::Get()->GetDevice()->CreateSamplerState(&SamplerDesc, &m_SamplerState)))
		return false;

	return true;
}

void Sampler::SetSampler(int RegisterNumber)
{
	Device::Get()->GetContext()->PSSetSamplers(RegisterNumber, 1, &m_SamplerState);
}
