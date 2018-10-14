#include "RenderManager.h"
#include "ShaderManager.h"
#include "BlendState.h"

JEONG_USING
SINGLETON_VAR_INIT(RenderManager)

RenderManager::RenderManager()
	:m_CreateState(NULLPTR)
{
}

RenderManager::~RenderManager()
{
	ShaderManager::Delete();
	Safe_Release_Map(m_RenderStateMap);
}

bool RenderManager::Init()
{
	if (ShaderManager::Get()->Init() == false)
	{
		TrueAssert(true);
		return false;
	}

	AddBlendTargetDesc(TRUE);
	CreateBlendState(ALPHA_BLEND);

	return true;
}

void RenderManager::AddBlendTargetDesc(BOOL bEnable, D3D11_BLEND srcBlend, D3D11_BLEND destBlend, D3D11_BLEND_OP blendOp, D3D11_BLEND srcAlphaBlend, D3D11_BLEND destAlphaBlend, D3D11_BLEND_OP blendAlphaOp, UINT8 iWriteMask)
{
	if (m_CreateState == NULLPTR)
		m_CreateState = new BlendState();

	m_CreateState->AddTargetDesc(bEnable, srcBlend, destBlend,blendOp, srcAlphaBlend, destAlphaBlend, blendAlphaOp,iWriteMask);
}

bool RenderManager::CreateBlendState(const string & KeyName, BOOL bAlphaCoverage, BOOL bIndependent)
{
	if (m_CreateState == NULLPTR)
		return false;

	if (m_CreateState->CreateState(bAlphaCoverage, bIndependent) == false)
	{
		SAFE_RELEASE(m_CreateState);
		return false;
	}

	m_RenderStateMap.insert(make_pair(KeyName, m_CreateState));
	m_CreateState = NULLPTR;

	return true;
}

RenderState * RenderManager::FindRenderState(const string & KeyName)
{
	unordered_map<string, RenderState*>::iterator FindIter = m_RenderStateMap.find(KeyName);

	if (FindIter == m_RenderStateMap.end())
		return NULLPTR;

	return FindIter->second;
}
