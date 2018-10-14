#include "Vector4.h"

Vector4	Vector4::Axis[4] = { Vector4(1.0f, 0.0f, 0.0f, 0.0f), Vector4(0.0f, 1.0f, 0.0f, 0.0f), Vector4(0.0f, 0.0f, 1.0f, 0.0f) , Vector4(0.0f, 0.0f, 0.0f, 1.0f) };
Vector4	Vector4::Zero = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
Vector4	Vector4::One = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
Vector4	Vector4::Red = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
Vector4	Vector4::Green = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
Vector4	Vector4::Blue = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
Vector4	Vector4::Black = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
Vector4	Vector4::Yellow = Vector4(1.0f, 1.0f, 0.0f, 1.0f);
Vector4	Vector4::Magenta = Vector4(1.0f, 0.0f, 1.0f, 1.0f);

float & Vector4::operator[](unsigned int Index)
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
		case 4:
			return w;
			break;
	}

	TrueAssert(true);
	return x;
}

void Vector4::operator=(const Vector4 & vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}

void Vector4::operator=(const XMVECTOR & Xmvec)
{
	XMStoreFloat4((XMFLOAT4*)this, Xmvec);
}

void Vector4::operator=(const XMFLOAT4 & XmFloat)
{
	x = XmFloat.x;
	y = XmFloat.y;
	z = XmFloat.z;
	w = XmFloat.w;
}

void Vector4::operator=(float Val)
{
	x = Val;
	y = Val;
	z = Val;
	w = Val;
}

void Vector4::operator=(int Val)
{
	x = (float)Val;
	y = (float)Val;
	z = (float)Val;
	w = (float)Val;
}

void Vector4::operator=(float ValArr[4])
{
	x = (float)ValArr[0];
	y = (float)ValArr[1];
	z = (float)ValArr[2];
	w = (float)ValArr[4];
}

void Vector4::operator=(int ValArr[4])
{
	x = (float)ValArr[0];
	y = (float)ValArr[1];
	z = (float)ValArr[2];
	w = (float)ValArr[4];
}

Vector4 Vector4::operator+(const Vector4 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	return Vector4(Src + Dest);
}

Vector4 Vector4::operator+(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat4((XMFLOAT4*)this);

	return Vector4(Src + Xmvec);
}

Vector4 Vector4::operator+(const XMFLOAT4 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	return Vector4(Src + Dest);
}

Vector4 Vector4::operator+(float Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src + Dest);
}

Vector4 Vector4::operator+(int Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src + Dest);
}

Vector4 Vector4::operator+(float ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src + Dest);
}

Vector4 Vector4::operator+(int ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src + Dest);
}
/////////////////////////////////////////////////////////////////////
Vector4 Vector4::operator-(const Vector4 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	return Vector4(Src - Dest);
}

Vector4 Vector4::operator-(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat4((XMFLOAT4*)this);

	return Vector4(Src - Xmvec);
}

Vector4 Vector4::operator-(const XMFLOAT4 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	return Vector4(Src - Dest);
}

Vector4 Vector4::operator-(float Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src - Dest);
}

Vector4 Vector4::operator-(int Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src - Dest);
}

Vector4 Vector4::operator-(float ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src - Dest);
}

Vector4 Vector4::operator-(int ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src - Dest);
}
/////////////////////////////////////////////////////////////////////////
Vector4 Vector4::operator*(const Vector4 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	return Vector4(Src * Dest);
}

Vector4 Vector4::operator*(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat4((XMFLOAT4*)this);

	return Vector4(Src * Xmvec);
}

Vector4 Vector4::operator*(const XMFLOAT4 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	return Vector4(Src * Dest);
}

Vector4 Vector4::operator*(float Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src * Dest);
}

Vector4 Vector4::operator*(int Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src * Dest);
}

Vector4 Vector4::operator*(float ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src * Dest);
}

Vector4 Vector4::operator*(int ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src * Dest);
}
/////////////////////////////////////////////////////////////////////////
Vector4 Vector4::operator/(const Vector4 & vec) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	return Vector4(Src / Dest);
}

Vector4 Vector4::operator/(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src;
	Src = XMLoadFloat4((XMFLOAT4*)this);

	return Vector4(Src / Xmvec);
}

Vector4 Vector4::operator/(const XMFLOAT4 & XmFloat) const
{
	XMVECTOR Src, Dest;
	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	return Vector4(Src / Dest);
}

Vector4 Vector4::operator/(float Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src / Dest);
}

Vector4 Vector4::operator/(int Val) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src / Dest);
}

Vector4 Vector4::operator/(float ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src / Dest);
}

Vector4 Vector4::operator/(int ValArr[4]) const
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return Vector4(Src / Dest);
}
/////////////////////////////////////////////////////////////////////////
void Vector4::operator+=(const Vector4 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	*this = (Src += Dest);
}

void Vector4::operator+=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Xmvec);

	*this = (Src += Dest);
}

void Vector4::operator+=(const XMFLOAT4 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	*this = (Src += Dest);
}
void Vector4::operator+=(float Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src += Dest);
}

void Vector4::operator+=(int Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src += Dest);
}
void Vector4::operator+=(float ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src += Dest);
}
void Vector4::operator+=(int ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src += Dest);
}
///////////////////////////////////////////////////////////////////////////////////
void Vector4::operator-=(const Vector4 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	*this = (Src -= Dest);
}

void Vector4::operator-=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Xmvec);

	*this = (Src -= Dest);
}

void Vector4::operator-=(const XMFLOAT4 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	*this = (Src -= Dest);
}
void Vector4::operator-=(float Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src -= Dest);
}

void Vector4::operator-=(int Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src -= Dest);
}
void Vector4::operator-=(float ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src -= Dest);
}
void Vector4::operator-=(int ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src -= Dest);
}
////////////////////////////////////////////////////////////////////////////////
void Vector4::operator*=(const Vector4 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	*this = (Src *= Dest);
}

void Vector4::operator*=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Xmvec);

	*this = (Src *= Dest);
}

void Vector4::operator*=(const XMFLOAT4 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	*this = (Src *= Dest);
}
void Vector4::operator*=(float Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src *= Dest);
}

void Vector4::operator*=(int Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src *= Dest);
}
void Vector4::operator*=(float ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src *= Dest);
}
void Vector4::operator*=(int ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src *= Dest);
}
////////////////////////////////////////////////////////////////////////////////
void Vector4::operator/=(const Vector4 & vec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	*this = (Src /= Dest);
}

void Vector4::operator/=(const XMVECTOR & Xmvec)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Xmvec);

	*this = (Src /= Dest);
}

void Vector4::operator/=(const XMFLOAT4 & XmFloat)
{
	XMVECTOR Src, Dest;

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	*this = (Src /= Dest);
}
void Vector4::operator/=(float Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src /= Dest);
}

void Vector4::operator/=(int Val)
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4((float)Val);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src /= Dest);
}
void Vector4::operator/=(float ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src /= Dest);
}
void Vector4::operator/=(int ValArr[4])
{
	XMVECTOR Src, Dest;
	Vector4 Temp = Vector4(ValArr);

	Src = XMLoadFloat4((XMFLOAT4*)this);
	Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	*this = (Src /= Dest);
}
////////////////////////////////////////////////////////////////////////////////
bool Vector4::operator==(const Vector4 & vec) const
{
	return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
}
bool Vector4::operator==(const XMVECTOR & Xmvec) const
{
	Vector4 Temp = Vector4(Xmvec);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
bool Vector4::operator==(const XMFLOAT4 & XmFloat) const
{
	Vector4 Temp = Vector4(XmFloat);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
bool Vector4::operator==(float Val) const
{
	Vector4 Temp = Vector4(Val);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
bool Vector4::operator==(int Val) const
{
	Vector4 Temp = Vector4(Val);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
bool Vector4::operator==(float ValArr[4]) const
{
	Vector4 Temp = Vector4(ValArr);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
bool Vector4::operator==(int ValArr[4]) const
{
	Vector4 Temp = Vector4(ValArr);

	return Temp.x == x && Temp.y == y && Temp.z == z && w == Temp.w;
}
/////////////////////////////////////////////////////////////////////////
bool Vector4::operator!=(const Vector4 & vec) const
{
	return (!(x == vec.x && y == vec.y && z == vec.z));
}
bool Vector4::operator!=(const XMVECTOR & Xmvec) const
{
	Vector4 Temp = Vector4(Xmvec);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}

bool Vector4::operator!=(const XMFLOAT4 & XmFloat) const
{
	Vector4 Temp = Vector4(XmFloat);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}
bool Vector4::operator!=(float Val) const
{
	Vector4 Temp = Vector4(Val);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}
bool Vector4::operator!=(int Val) const
{
	Vector4 Temp = Vector4(Val);

	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}
bool Vector4::operator!=(float ValArr[4]) const
{
	Vector4 Temp = Vector4(ValArr);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}
bool Vector4::operator!=(int ValArr[4]) const
{
	Vector4 Temp = Vector4(ValArr);
	return (!(x == Temp.x && y == Temp.y && z == Temp.z));
}
float Vector4::Lenth() const
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);

	return XMVectorGetX(XMVector3Length(Src));
}
void Vector4::Nomallize()
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);

	*this = XMVector3Normalize(Src);
}
/////////////////////////////////////////////////////////////////////////
float Vector4::Dot(const Vector4 & vec) const
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);
	XMVECTOR Dest = XMLoadFloat4((XMFLOAT4*)&vec);

	return XMVectorGetX(XMVector4Dot(Src, Dest));
}
float Vector4::Dot(const XMVECTOR & Xmvec) const
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);

	return XMVectorGetX(XMVector4Dot(Src, Xmvec));
}
float Vector4::Dot(const XMFLOAT4 & XmFloat) const
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);
	XMVECTOR Dest = XMLoadFloat4((XMFLOAT4*)&XmFloat);

	return XMVectorGetX(XMVector4Dot(Src, Dest));
}
float Vector4::Dot(float Val[4]) const
{
	Vector4 Temp = Vector4(Val);

	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);
	XMVECTOR Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return XMVectorGetX(XMVector4Dot(Src, Dest));

}
float Vector4::Dot(int Val[4]) const
{
	Vector4 Temp = Vector4(Val);

	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)this);
	XMVECTOR Dest = XMLoadFloat4((XMFLOAT4*)&Temp);

	return XMVectorGetX(XMVector4Dot(Src, Dest));
}
Vector4 Vector4::Nomallize(const Vector4 & vec)
{
	XMVECTOR Src = XMLoadFloat4((XMFLOAT4*)&vec);

	return Vector4(XMVector3Normalize(Src));
}
/////////////////////////////////////////////////////////////////////////