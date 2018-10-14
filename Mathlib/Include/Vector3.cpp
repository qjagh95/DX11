#include "Vector3.h"
#include "Matrix.h"

Vector3	Vector3::Axis[3] = { Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f) };
Vector3	Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);
Vector3	Vector3::One = Vector3(1.0f, 1.0f, 1.0f);

float & Vector3::operator[](unsigned int Index)
{
	switch (Index)
	{
		case 1:
			return x;
			break;
		case 2:
			return y;
			break;
		case 3:
			return z;
			break;
	}

	TrueAssert(true);
	return x;
}

void Vector3::operator=(const Vector3 & vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

void Vector3::operator=(const XMVECTOR & Xmvec)
{
	XMStoreFloat3((XMFLOAT3*)this, Xmvec);
}

void Vector3::operator=(const XMFLOAT3 & XmFloat)
{
	x = XmFloat.x;
	y = XmFloat.y;
	z = XmFloat.z;
}

void Vector3::operator=(float Val)
{
	x = Val;
	y = Val;
	z = Val;
}

void Vector3::operator=(int Val)
{
	x = (float)Val;
	y = (float)Val;
	z = (float)Val;
}

void Vector3::operator=(float ValArr[3])
{
	x = (float)ValArr[0];
	y = (float)ValArr[1];
	z = (float)ValArr[2];
}

void Vector3::operator=(int ValArr[3])
{
	x = (float)ValArr[0];
	y = (float)ValArr[1];
	z = (float)ValArr[2];
}

Vector3 Vector3::operator+(const Vector3 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	return Vector3(Src + Dest);
}

Vector3 Vector3::operator+(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat3((XMFLOAT3*)this);

	return Vector3(Src + Xmvec);
}

Vector3 Vector3::operator+(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return Vector3(Src + Dest);
}

Vector3 Vector3::operator+(float Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src + Dest);
}

Vector3 Vector3::operator+(int Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src + Dest);
}

Vector3 Vector3::operator+(float ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src + Dest);
}

Vector3 Vector3::operator+(int ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src + Dest);
}
/////////////////////////////////////////////////////////////////////
Vector3 Vector3::operator-(const Vector3 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	return Vector3(Src - Dest);
}

Vector3 Vector3::operator-(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat3((XMFLOAT3*)this);

	return Vector3(Src - Xmvec);
}

Vector3 Vector3::operator-(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return Vector3(Src - Dest);
}

Vector3 Vector3::operator-(float Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src - Dest);
}

Vector3 Vector3::operator-(int Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src - Dest);
}

Vector3 Vector3::operator-(float ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src - Dest);
}

Vector3 Vector3::operator-(int ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src - Dest);
}
/////////////////////////////////////////////////////////////////////////
Vector3 Vector3::operator*(const Vector3 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	return Vector3(Src * Dest);
}

Vector3 Vector3::operator*(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat3((XMFLOAT3*)this);

	return Vector3(Src * Xmvec);
}

Vector3 Vector3::operator*(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return Vector3(Src * Dest);
}

Vector3 Vector3::operator*(float Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src * Dest);
}

Vector3 Vector3::operator*(int Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src * Dest);
}

Vector3 Vector3::operator*(float ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src * Dest);
}

Vector3 Vector3::operator*(int ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src * Dest);
}
/////////////////////////////////////////////////////////////////////////
Vector3 Vector3::operator/(const Vector3 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	return Vector3(Src / Dest);
}

Vector3 Vector3::operator/(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat3((XMFLOAT3*)this);

	return Vector3(Src / Xmvec);
}

Vector3 Vector3::operator/(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return Vector3(Src / Dest);
}

Vector3 Vector3::operator/(float Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src / Dest);
}

Vector3 Vector3::operator/(int Val) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src / Dest);
}

Vector3 Vector3::operator/(float ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src / Dest);
}

Vector3 Vector3::operator/(int ValArr[3]) const
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(Src / Dest);
}
/////////////////////////////////////////////////////////////////////////
void Vector3::operator+=(const Vector3 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	*this = (Src += Dest);
}

void Vector3::operator+=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Xmvec);

	*this = (Src += Dest);
}

void Vector3::operator+=(const XMFLOAT3 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	*this = (Src += Dest);
}
void Vector3::operator+=(float Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src += Dest);
}

void Vector3::operator+=(int Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src += Dest);
}

void Vector3::operator+=(float ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src += Dest);
}
void Vector3::operator+=(int ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src += Dest);
}
///////////////////////////////////////////////////////////////////////////////////
void Vector3::operator-=(const Vector3 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	*this = (Src -= Dest);
}

void Vector3::operator-=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Xmvec);

	*this = (Src -= Dest);
}

void Vector3::operator-=(const XMFLOAT3 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	*this = (Src -= Dest);
}
void Vector3::operator-=(float Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src -= Dest);
}

void Vector3::operator-=(int Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src -= Dest);
}
void Vector3::operator-=(float ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src -= Dest);
}
void Vector3::operator-=(int ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src -= Dest);
}
////////////////////////////////////////////////////////////////////////////////
void Vector3::operator*=(const Vector3 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	*this = (Src *= Dest);
}

void Vector3::operator*=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Xmvec);

	*this = (Src *= Dest);
}

void Vector3::operator*=(const XMFLOAT3 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	*this = (Src *= Dest);
}
void Vector3::operator*=(float Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src *= Dest);
}

void Vector3::operator*=(int Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src *= Dest);
}
void Vector3::operator*=(float ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src *= Dest);
}
void Vector3::operator*=(int ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src *= Dest);
}
////////////////////////////////////////////////////////////////////////////////
void Vector3::operator/=(const Vector3 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	*this = (Src /= Dest);
}

void Vector3::operator/=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Xmvec);

	*this = (Src /= Dest);
}

void Vector3::operator/=(const XMFLOAT3 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	*this = (Src /= Dest);
}
void Vector3::operator/=(float Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src /= Dest);
}

void Vector3::operator/=(int Val)
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3((float)Val);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src /= Dest);
}
void Vector3::operator/=(float ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src /= Dest);
}
void Vector3::operator/=(int ValArr[3])
{
	XMVECTOR Src, Dest;
	Vector3 Temp = Vector3(ValArr);

	Src = XMLoadFloat3((XMFLOAT3*)this);
	Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	*this = (Src /= Dest);
}
////////////////////////////////////////////////////////////////////////////////
bool Vector3::operator==(const Vector3 & vec) const
{
	return x == vec.x && y == vec.y && z == vec.z;
}
bool Vector3::operator==(const XMVECTOR & Xmvec) const
{
	Vector3 Temp = Vector3(Xmvec);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
bool Vector3::operator==(const XMFLOAT3 & XmFloat) const
{
	Vector3 Temp = Vector3(XmFloat);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
bool Vector3::operator==(float Val) const
{
	Vector3 Temp = Vector3(Val);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
bool Vector3::operator==(int Val) const
{
	Vector3 Temp = Vector3(Val);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
bool Vector3::operator==(float ValArr[3]) const
{
	Vector3 Temp = Vector3(ValArr);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
bool Vector3::operator==(int ValArr[3]) const
{
	Vector3 Temp = Vector3(ValArr);

	return Temp.x == x && Temp.y == y && Temp.z == z;
}
/////////////////////////////////////////////////////////////////////////
bool Vector3::operator!=(const Vector3 & vec) const
{
	return (!(x == vec.x && y == vec.y && z == vec.z));
}
bool Vector3::operator!=(const XMVECTOR & Xmvec) const
{
	Vector3 Temp = Vector3(Xmvec);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector3::operator!=(const XMFLOAT3 & XmFloat) const
{
	Vector3 Temp = Vector3(XmFloat);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector3::operator!=(float Val) const
{
	Vector3 Temp = Vector3(Val);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector3::operator!=(int Val) const
{
	Vector3 Temp = Vector3(Val);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector3::operator!=(float ValArr[3]) const
{
	Vector3 Temp = Vector3(ValArr);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector3::operator!=(int ValArr[3]) const
{
	Vector3 Temp = Vector3(ValArr);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

float Vector3::Lenth() const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);

	return XMVectorGetX(XMVector3Length(Src));
}

void Vector3::Nomallize()
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);

	*this = XMVector3Normalize(Src);
}
Vector3 Vector3::TransformNormal(const Matrix & mat)
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	return Vector3(XMVector3TransformNormal(Src, mat.matrix));
}

Vector3 Vector3::TransformNormal(const XMMATRIX & mat)
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	return Vector3(XMVector3TransformNormal(Src, mat));
}

Vector3 Vector3::TransformCoord(const Matrix & mat)
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	return Vector3(XMVector3TransformCoord(Src, mat.matrix));
}
Vector3 Vector3::TransformCoord(const XMMATRIX & mat)
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	return Vector3(XMVector3TransformCoord(Src, mat));
}

/////////////////////////////////////////////////////////////////////////
float Vector3::Dot(const Vector3 & vec) const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&vec);

	return XMVectorGetX(XMVector3Dot(Src, Dest));
}

float Vector3::Dot(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);

	return XMVectorGetX(XMVector3Dot(Src, Xmvec));
}

float Vector3::Dot(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return XMVectorGetX(XMVector3Dot(Src, Dest));
}

float Vector3::Dot(float Val[3]) const
{
	Vector3 Temp = Vector3(Val);

	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return XMVectorGetX(XMVector3Dot(Src, Dest));

}

float Vector3::Dot(int Val[3]) const
{
	Vector3 Temp = Vector3(Val);

	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return XMVectorGetX(XMVector3Dot(Src, Dest));
}
/////////////////////////////////////////////////////////////////////////
Vector3 Vector3::Cross(const Vector3 & vec) const
{
	Vector3 Temp = Vector3(vec);

	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(XMVector3Cross(Src, Dest));
}

Vector3 Vector3::Cross(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Xmvec);

	return Vector3(XMVector3Cross(Src, Dest));
}

Vector3 Vector3::Cross(const XMFLOAT3 & XmFloat) const
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&XmFloat);

	return Vector3(XMVector3Cross(Src, Dest));
}

Vector3 Vector3::Cross(float Val[3]) const
{
	Vector3 Temp = Vector3(Val);

	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(XMVector3Cross(Src, Dest));
}

Vector3 Vector3::Cross(int Val[3]) const
{
	Vector3 Temp = Vector3(Val);

	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)this);
	XMVECTOR Dest = XMLoadFloat3((XMFLOAT3*)&Temp);

	return Vector3(XMVector3Cross(Src, Dest));
}

Vector3 Vector3::Nomallize(const Vector3 & vec)
{
	XMVECTOR Src = XMLoadFloat3((XMFLOAT3*)&vec);

	return Vector3(XMVector3Normalize(Src));
}
/////////////////////////////////////////////////////////////////////////