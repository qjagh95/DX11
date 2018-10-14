#include "RenderState.h"

JEONG_USING

RenderState::RenderState()
	:m_RenderState(NULLPTR)
{
}


RenderState::~RenderState()
{
	SAFE_RELEASE(m_RenderState);
}
