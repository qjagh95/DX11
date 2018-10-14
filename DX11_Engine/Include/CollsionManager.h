#pragma once
#include "Component\Collider_Com.h"

JEONG_BEGIN

class JEONG_DLL CollsionManager
{
private:
	//�ϳ��� ���� �� ��ü�� �ǹ��ϴ� ����. Collider�� �����͸� �޾ƾ��ϱ⶧���� 2�������� (vector��� ����)
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
	//��ü�����̴�.
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