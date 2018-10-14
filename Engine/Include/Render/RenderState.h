#pragma once
#include "../RefCount.h"

JEONG_BEGIN

class JEONG_DLL RenderState : public RefCount
{
public:

protected:
	//BlendState, DepthCilState, ResterizerState의 최상위 부모클래스다.
	ID3D11DeviceChild* m_RenderState;

protected:
	RenderState();
	virtual ~RenderState() = 0;

public:
	friend class RenderManager;
};
JEONG_END
