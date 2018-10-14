#pragma once
#include "../stdafx.h"
JEONG_BEGIN

class RenderState;
class BlendState;
class JEONG_DLL RenderManager
{
public:
	bool Init();
	void AddBlendTargetDesc(BOOL bEnable, D3D11_BLEND srcBlend = D3D11_BLEND_SRC_ALPHA, D3D11_BLEND destBlend = D3D11_BLEND_INV_SRC_ALPHA, D3D11_BLEND_OP blendOp = D3D11_BLEND_OP_ADD, D3D11_BLEND srcAlphaBlend = D3D11_BLEND_ONE, D3D11_BLEND destAlphaBlend = D3D11_BLEND_ZERO, D3D11_BLEND_OP blendAlphaOp = D3D11_BLEND_OP_ADD, UINT8 iWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL);
	bool CreateBlendState(const string& KeyName, BOOL bAlphaCoverage = FALSE, BOOL bIndependent = FALSE);

	RenderState* FindRenderState(const string& KeyName);

private:
	unordered_map<string, RenderState*> m_RenderStateMap;
	BlendState* m_CreateState;	

public:
	CLASS_IN_SINGLE(RenderManager)
};

JEONG_END

