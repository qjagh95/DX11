#include "MathHeader.h"

float JEONG_DLL RadianToDegree(float radian)
{
	return radian / JEONG_PI * 180.f;
}

float JEONG_DLL DegreeToRadian(float degree)
{
	return degree / 180.f * JEONG_PI;
}