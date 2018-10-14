#pragma once
#include "Macro.h"

JEONG_BEGIN

enum COMPONENT_TYPE
{
	CT_NONE,
	CT_TRANSFORM,
	CT_RENDER,
	CT_MAX,
};

//각 축의 방향
enum AXIS
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z,
	AXIS_MAX,
};

enum CBUFFER_SHADER_TYPE
{
	CST_VERTEX = 0x1,
	CST_PIXEL = 0x2,
};

JEONG_END