#pragma once
#include "RenderState.h"

JEONG_BEGIN

class JEONG_DLL BlendState : public RenderState
{
public:
	bool CreateState();

private:

private:
	BlendState();
	~BlendState();
	
public:
	friend class RenderManager;
};
JEONG_END

