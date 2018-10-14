#pragma once
#include "Macro.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.h"
#include "Matrix.h"

JEONG_BEGIN

struct JEONG_DLL WinSize
{
	unsigned int Width;
	unsigned int Height;

	WinSize() : Width(0), Height(0) {}
	WinSize(const WinSize& size) {*this = size;}
	WinSize(unsigned int Width, unsigned Height) : Width(Width), Height(Height) {}
};

struct VertexColor
{
	Vector3 m_Pos;
	Vector4 m_Color;

	VertexColor() {}
	VertexColor(const VertexColor& Value) { *this = Value; }
	VertexColor(const Vector3& vec3, const Vector4& vec4) { m_Pos = vec3, m_Color = vec4; }
};

enum JEONG_DLL SHADER_TYPE
{
	ST_VERTEX,
	ST_PIXEL,
	ST_MAX,
};

JEONG_END
