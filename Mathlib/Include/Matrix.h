#pragma once
//��� �����Ѵ�
#pragma warning(disable:4251)
#include "MathHeader.h"
#include "Vector4.h"

//����Ʈ���� ����Ʈ�� 16����� �����ش� (SIMD �������͸� ����Ѵ�)
union MATH_DLL __declspec(align(16)) Matrix
{
	XMMATRIX matrix;
	struct
	{
		float	_11, _12, _13, _14;
		float	_21, _22, _23, _24;
		float	_31, _32, _33, _34;
		float	_41, _42, _43, _44;
	};

	struct
	{
		Vector4 vec[4];
	};

	Matrix();
	Matrix(const Matrix& mat);
	Matrix(const XMMATRIX& mat);

	XMMATRIX operator * (const Matrix& mat)	const;
	XMMATRIX operator * (const XMMATRIX& mat)	const;
	XMMATRIX operator * (float val)	const;
	XMMATRIX operator * (int val)	const;
	// *=
	XMMATRIX& operator *= (const Matrix& mat);
	XMMATRIX& operator *= (const XMMATRIX& mat);
	XMMATRIX& operator *= (float val);
	XMMATRIX& operator *= (int val);

	Vector4& operator[] (unsigned int Index);

	void* operator new (size_t Size);
	void operator delete (void* Data);

	//�׵����
	XMMATRIX Identity();
	//��ġ���
	XMMATRIX Transpose();
	//�����
	XMMATRIX Inverse();

	//S R T����.
	XMMATRIX Scaling(float x, float y, float z);
	XMMATRIX Scaling(const union Vector3& Scale);
	XMMATRIX Rotation(float x, float y, float z);
	XMMATRIX Rotation(const union Vector3& Rot);
	XMMATRIX RotationX(float x);
	XMMATRIX RotationY(float y);
	XMMATRIX RotationZ(float z);
	//����̵�����.
	XMMATRIX Translation(float x, float y, float z);
	XMMATRIX Translation(const union Vector3& vPos);
};