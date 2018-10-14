#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

#ifdef JEONG_EXPORT
#define JEONG_DLL __declspec(dllexport)
#else
#define JEONG_DLL __declspec(dllimport)
#endif

#define TrueAssert(Type) assert(!(Type))

#define JEONG_PI 3.141592f

float JEONG_DLL RadianToDegree(float radian);
float JEONG_DLL DegreeToRadian(float degree);