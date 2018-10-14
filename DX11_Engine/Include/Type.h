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

//UV��ǥ�� �̹���ũ�⿡ ������� ������ 0���� 1������ ������ ���� �����̴�. (�»�� ��ǥ�� ����Ѵ�)
//Left = 0 , Right = 1
//Top = 0 , Bottom = 1
struct VertexUV
{
	Vector3 m_Pos;
	Vector2 m_UV;

	VertexUV() {}
	VertexUV(const VertexUV& Value) { *this = Value; }
	VertexUV(const Vector3& vec3, const Vector2& vec2) { m_Pos = vec3, m_UV = vec2; }
};

enum JEONG_DLL SHADER_TYPE
{
	ST_VERTEX,
	ST_PIXEL,
	ST_MAX,
};

//CBuffer�� ������� (C++�ڵ忡�� ���̴��� ����������)
struct JEONG_DLL CBuffer
{
	ID3D11Buffer* cBuffer;
	int BufferSize;
	int ShaderType;
	int RegisterNumber;
};

struct JEONG_DLL TransformCBuffer
{
	Matrix World;
	Matrix View;
	Matrix Projection;
	Matrix WV;
	Matrix WVP;
};

struct JEONG_DLL Material
{
	//�������� (����) ���߿� �߰� ����.
	Vector4 Diffuse;

	Material() : Diffuse(Vector4::White) {}
};

JEONG_END
