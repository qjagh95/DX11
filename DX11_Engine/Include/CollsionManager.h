#pragma once
#include "Component\Collider_Com.h"

JEONG_BEGIN

class JEONG_DLL CollsionManager
{
private:
	//하나의 공간 그 자체를 의미하는 변수. Collider의 포인터를 받아야하기때문에 2차포인터 (vector대신 쓴다)
	struct CollsionSelection
	{
		Collider_Com** ColliderList;
		int Size;
		int Capacity;
		Vector3 Min;
		Vector3 Max;

		CollsionSelection() : Size(0), Capacity(5) { ColliderList = new Collider_Com*[Capacity]; }
		~CollsionSelection() { SAFE_DELETE_ARRARY(ColliderList); }
	};
	//전체공간이다.
	struct CollsionGroup
	{
		CollsionSelection* SelectionList;
		int CountX;
		int CountY;
		int CountZ;
		int Count;
		Vector3 Min;
		Vector3 Max;
	};

public:
	bool Init();
	bool CreateGroup(const string& KeyName, const Vector3& Min, const Vector3& Max, int CountX, int CountY, int CountZ);

private:
	unordered_map<string, CollsionGroup*> m_GroupMap;

private:
	CollsionGroup* FindGroup(const string& KeyName);

public:
	CLASS_IN_SINGLE(CollsionManager)
};

JEONG_END