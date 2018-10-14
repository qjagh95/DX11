#pragma once
#include "Macro.h"

JEONG_BEGIN

enum COMPONENT_TYPE
{
	CT_NONE,
	CT_TRANSFORM,
	CT_RENDER,
	CT_MATERIAL,
	CT_CAMERA,
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

enum CAMERA_TYPE
{
	CT_PERSPECTIVE,
	CT_ORTHO,
};

enum RENDER_STATE
{
	RS_BLEND,
	RS_RASTERIZER,
	RS_DEPTHSTENCIL,
	RS_END
};

enum MOVE_DIR
{
	MD_RIGHT = 1,
	MD_LEFT = -1,
	MD_UP = 1,
	MD_DOWN = -1
};

JEONG_END