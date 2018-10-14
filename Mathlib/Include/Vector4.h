#pragma once

//DirectX11에서 제공하는 수학 기능을 사용하기위함
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h> //제공되는 벡터들을 사용하기위함

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

#define TrueAssert(Type) assert(!(Type))

union  __declspec(dllexport) Vector4
{
	struct
	{
		float x, y, z, w;
	};
	struct
	{
		float r, g, b, a;
	};

	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	Vector4(const Vector4& vec3) : x(vec3.x), y(vec3.y), z(vec3.z),w(vec3.w)  {}
	Vector4(const XMVECTOR& Xmvec) { XMStoreFloat4((XMFLOAT4*)this, Xmvec); } ///XMVector -> XMFLOAT로 변환 (어차피 같은 메모리크기 여서 XMFLOAT4로 형변환해주면 된다)
	Vector4(const XMFLOAT4& Xmfloat) { x = Xmfloat.x, y = Xmfloat.y, z = Xmfloat.z, w = Xmfloat.w; }
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	Vector4(float ValArr[4]) :x(ValArr[0]), y(ValArr[1]), z(ValArr[2]), w(ValArr[3]) {}
	Vector4(int ValArr[4]) :x((float)ValArr[0]), y((float)ValArr[1]), z((float)ValArr[2]), w((float)ValArr[3]) {}
	Vector4(float Val) : x(Val), y(Val), z(Val), w(Val) {}
	Vector4(int Val) : x((float)Val), y((float)Val), z((float)Val), w((float)Val) {}

	//operator
	float& operator[] (unsigned int Index);

	void operator = (const Vector4& vec);
	void operator = (const XMVECTOR& Xmvec);
	void operator = (const XMFLOAT4& XmFloat);
	void operator = (float Val);
	void operator = (int Val);
	void operator = (float ValArr[4]);
	void operator = (int ValArr[4]);

	Vector4 operator + (const Vector4& vec)	const;
	Vector4 operator + (const XMVECTOR& Xmvec) const;
	Vector4 operator + (const XMFLOAT4& XmFloat) const;
	Vector4 operator + (float Val) const;
	Vector4 operator + (int Val) const;
	Vector4 operator + (float ValArr[4]) const;
	Vector4 operator + (int ValArr[4]) const;

	Vector4 operator - (const Vector4& vec)	const;
	Vector4 operator - (const XMVECTOR& Xmvec) const;
	Vector4 operator - (const XMFLOAT4& XmFloat) const;
	Vector4 operator - (float Val) const;
	Vector4 operator - (int Val) const;
	Vector4 operator - (float ValArr[4]) const;
	Vector4 operator - (int ValArr[4]) const;

	Vector4 operator * (const Vector4& vec)	const;
	Vector4 operator * (const XMVECTOR& Xmvec) const;
	Vector4 operator * (const XMFLOAT4& XmFloat) const;
	Vector4 operator * (float Val) const;
	Vector4 operator * (int Val) const;
	Vector4 operator * (float ValArr[4]) const;
	Vector4 operator * (int ValArr[4]) const;

	Vector4 operator / (const Vector4& vec)	const;
	Vector4 operator / (const XMVECTOR& Xmvec) const;
	Vector4 operator / (const XMFLOAT4& XmFloat) const;
	Vector4 operator / (float Val) const;
	Vector4 operator / (int Val) const;
	Vector4 operator / (float ValArr[4]) const;
	Vector4 operator / (int ValArr[4]) const;

	void operator += (const Vector4& vec);
	void operator += (const XMVECTOR& Xmvec);
	void operator += (const XMFLOAT4& XmFloat);
	void operator += (float Val);
	void operator += (int Val);
	void operator += (float ValArr[4]);
	void operator += (int ValArr[4]);

	void operator -= (const Vector4& vec);
	void operator -= (const XMVECTOR& Xmvec);
	void operator -= (const XMFLOAT4& XmFloat);
	void operator -= (float Val);
	void operator -= (int Val);
	void operator -= (float ValArr[4]);
	void operator -= (int ValArr[4]);

	void operator *= (const Vector4& vec);
	void operator *= (const XMVECTOR& Xmvec);
	void operator *= (const XMFLOAT4& XmFloat);
	void operator *= (float Val);
	void operator *= (int Val);
	void operator *= (float ValArr[4]);
	void operator *= (int ValArr[4]);

	void operator /= (const Vector4& vec);
	void operator /= (const XMVECTOR& Xmvec);
	void operator /= (const XMFLOAT4& XmFloat);
	void operator /= (float Val);
	void operator /= (int Val);
	void operator /= (float ValArr[4]);
	void operator /= (int ValArr[4]);

	bool operator == (const Vector4& vec)	const;
	bool operator == (const XMVECTOR& Xmvec) const;
	bool operator == (const XMFLOAT4& XmFloat) const;
	bool operator == (float Val) const;
	bool operator == (int Val) const;
	bool operator == (float ValArr[4]) const;
	bool operator == (int ValArr[4]) const;

	bool operator != (const Vector4& vec)	const;
	bool operator != (const XMVECTOR& Xmvec) const;
	bool operator != (const XMFLOAT4& XmFloat) const;
	bool operator != (float Val) const;
	bool operator != (int Val) const;
	bool operator != (float ValArr[4]) const;
	bool operator != (int ValArr[4]) const;

	//벡터의 크기를 구해주는 함수
	float Lenth() const;
	//노말라이즈
	void Nomallize();

	//내적
	float Dot(const Vector4& vec) const;
	float Dot(const XMVECTOR& Xmvec) const;
	float Dot(const XMFLOAT4& XmFloat) const;
	float Dot(float Val[4]) const;
	float Dot(int Val[4]) const;

	static Vector4 Nomallize(const Vector4& vec);
	static Vector4	Axis[4];
	static Vector4	Zero;
	static Vector4	One;
};
