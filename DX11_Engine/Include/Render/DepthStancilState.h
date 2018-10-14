#pragma once
#include "RenderState.h"

JEONG_BEGIN

class DepthStancilState : public RenderState
{
public:
	bool CreateState(BOOL bDepthEnable, D3D11_DEPTH_WRITE_MASK eMask = D3D11_DEPTH_WRITE_MASK_ALL, D3D11_COMPARISON_FUNC eDepthFunc = D3D11_COMPARISON_LESS, BOOL bStencilEnable = FALSE, UINT8 iStencilReadMask = 0, UINT8 iStencilWriteMask = 0, D3D11_DEPTH_STENCILOP_DESC tFrontFace = {}, D3D11_DEPTH_STENCILOP_DESC tBackFace = {});

	void SetState() override;
	void ResetState() override;

private:
	UINT m_StencilRef;
	UINT m_OldStencilRef;

private:
	DepthStancilState();
	~DepthStancilState();

public:
	friend class RenderManager;
};

JEONG_END