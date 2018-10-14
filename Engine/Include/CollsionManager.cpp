#include "CollsionManager.h"

JEONG_USING
SINGLETON_VAR_INIT(CollsionManager)

CollsionManager::CollsionManager()
{
}

CollsionManager::~CollsionManager()
{
}

bool CollsionManager::Init()
{
	return true;
}

bool CollsionManager::CreateGroup(const string & KeyName, const Vector3 & Min, const Vector3 & Max, int CountX, int CountY, int CountZ)
{
	CollsionGroup* newGroup = FindGroup(KeyName);

	if (newGroup != NULLPTR)
		return false;

	newGroup = new CollsionGroup();
	newGroup->CountX = CountX;
	newGroup->CountY = CountY;
	newGroup->CountZ = CountZ;
	newGroup->Count = CountX * CountY * CountZ;
	newGroup->Max = Max;
	newGroup->Min = Min;
	newGroup->SelectionList = new CollsionSelection[newGroup->Count];

	Vector3 SelectionLenth = Max - Min;

	for (int z = 0; z < CountZ; z++)
	{
		for (int y = 0; y < CountY; y++)
		{
			for (int x = 0; x < CountX; x++)
			{
				int Index = z * (CountX * CountY) + y * CountX + x;
				
				newGroup->SelectionList[Index].Min = Min + (Vector3((float)x, (float)y, (float)z) * SelectionLenth);
				newGroup->SelectionList[Index].Max = Max + (Vector3((float)x + 1.0f, (float)y + 1.0f, (float)z + 1.0f) * SelectionLenth);
			}
		}
	}

	m_GroupMap.insert(make_pair(KeyName, newGroup));

	return true;
}

CollsionManager::CollsionGroup * CollsionManager::FindGroup(const string & KeyName)
{
	unordered_map<string, CollsionGroup*>::iterator FindIter = m_GroupMap.find(KeyName);

	if (FindIter == m_GroupMap.end())
		return NULLPTR;

	return FindIter->second;
}
