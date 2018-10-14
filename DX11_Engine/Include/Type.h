#pragma once
#include "Macro.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Vector2.h"
#include "Matrix.h"

#include "Flag.h"

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

//UV좌표란 이미지크기에 상관없이 무조건 0에서 1까지의 범위를 갖는 숫자이다. (좌상단 좌표를 사용한다)
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

//CBuffer은 상수버퍼 (C++코드에서 쉐이더로 보내기위함)
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
	Vector3 Pivot;
	float Empty1;	//4바이트
	Vector3 Lenth;
	float Empty2;   //4바이트 (16바이트패딩으로 바이트 맞춰주기위함)
};

struct JEONG_DLL Material
{
	//재질정보 (색상) 나중에 추가 예정.
	Vector4 Diffuse;

	Material() : Diffuse(Vector4::White) {}
};

struct JEONG_DLL Clip2DFrame
{
	Vector2	LeftTop;
	Vector2	RightBottom;
};

struct JEONG_DLL AnimationClip2D
{
	ANIMATION2D_TYPE AnimationType;
	ANIMATION_OPTION AnimationOption;
	string AnimationName;
	class Texture* CurTexture;
	float TextureWidth;
	float TextureHeight;
	vector<Clip2DFrame>	vecFrame;
	int Frame;
	float PlayTime;
	float PlayLimitTime;
};

struct JEONG_DLL Animation2DCBuffer
{

};

JEONG_END
