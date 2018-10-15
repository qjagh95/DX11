#include "CollsionManager.h"
#include "GameObject.h"
#include "Device.h"

#include "Scene/Scene.h"
#include "Scene/SceneManager.h"

#include "Component/Transform_Com.h"



JEONG_USING
SINGLETON_VAR_INIT(CollsionManager)

CollsionManager::CollsionManager()
{
}

CollsionManager::~CollsionManager()
{
	unordered_map<string, CollsionGroup*>::iterator StartIter = m_GroupMap.begin();
	unordered_map<string, CollsionGroup*>::iterator EndIter = m_GroupMap.end();

	for (; StartIter != EndIter; StartIter++)
	{
		SAFE_DELETE_ARRARY(StartIter->second->SelectionList);
		SAFE_DELETE(StartIter->second);
	}	

	m_GroupMap.clear();
}

bool CollsionManager::Init()
{
	return true;
}

bool CollsionManager::CreateGroup(const string & KeyName, const Vector3 & Min, const Vector3 & Max, int CountX, int CountY, int CountZ, COLLSION_GROUP_TYPE eType)
{
	CollsionGroup* newGroup = FindGroup(KeyName);

	if (newGroup != NULLPTR)
		return false;   

	newGroup = new CollsionGroup();
	newGroup->Type = eType;
	newGroup->CountX = CountX;
	newGroup->CountZ = CountZ;
	newGroup->Count = CountX * CountY * CountZ;
	newGroup->Max = Max;
	newGroup->Min = Min;	
	newGroup->Lenth = Max - Min;
	newGroup->SpaceLenth = newGroup->Lenth / Vector3((float)CountX, (float)CountY, (float)CountZ);

	newGroup->SelectionList = new CollsionSelection[newGroup->Count];

	m_GroupMap.insert(make_pair(KeyName, newGroup));

	return true;
}

void CollsionManager::ChangeGroupType(const string& KeyName, COLLSION_GROUP_TYPE eType)
{
	CollsionGroup* getGroup = FindGroup(KeyName);

	if (getGroup == NULLPTR)
		return;

	getGroup->Type = eType;
}

void CollsionManager::AddCollsion(GameObject * object)
{
	if (object->CheckComponentType(CT_COLLIDER) == false)
		return;

	Scene* CurScene = SceneManager::Get()->GetCurScene();
	Transform_Com* getTransform = CurScene->GetMainCameraTransform();
	Vector3 CameraPos = getTransform->GetWorldPos();

	SAFE_RELEASE(CurScene);

	const list<Component_Base*>* getComList = object->FindComponentFromType(CT_COLLIDER);

	list<Component_Base*>::const_iterator StartIter = getComList->begin();
	list<Component_Base*>::const_iterator EndIter = getComList->end();

	for (; StartIter != EndIter; StartIter++)
	{
		((Collider_Com*)*StartIter)->ClearSectionIndex();
		CollsionGroup* getGroup = FindGroup(((Collider_Com*)*StartIter)->GetCollisionGroup());

		if (getGroup == NULLPTR)
		{
			TrueAssert(true);
			return;
		}

		if (getGroup->Type == CGT_2D)
		{
			Vector3 cPos = Vector3((float)Device::Get()->GetWinSize().Width, (float)Device::Get()->GetWinSize().Height, 0.0f);
			CameraPos += cPos / 2.0f;
		}

		if (((Collider_Com*)*StartIter)->GetCollisionGroup() == "UI")
			CameraPos = Vector3::Zero;

		Vector3	SectionMin = ((Collider_Com*)*StartIter)->GetSectionMin() + CameraPos;
		Vector3	SectionMax = ((Collider_Com*)*StartIter)->GetSectionMax() + CameraPos;

		int	xMin = 0;
		int xMax = 0;
		int yMin = 0;
		int yMax = 0;
		int zMin = 0;
		int zMax = 0;

		//공간할당.
		//내가 속해있는 공간 최소값 - 전체공간 최소값 / 길이(사이즈) = 인덱스.
		xMin = (int)(SectionMin.x - getGroup->Min.x) / (int)getGroup->SpaceLenth.x;
		xMax = (int)(SectionMax.x - getGroup->Min.x) / (int)getGroup->SpaceLenth.x;
		yMin = (int)(SectionMin.y - getGroup->Min.y) / (int)getGroup->SpaceLenth.y;
		yMax = (int)(SectionMax.y - getGroup->Min.y) / (int)getGroup->SpaceLenth.y;

		if (getGroup->CountZ > 1)
		{
			zMin = (int)(SectionMin.z - getGroup->Min.z) / (int)getGroup->SpaceLenth.z;
			zMax = (int)(SectionMax.z - getGroup->Min.z) / (int)getGroup->SpaceLenth.z;
		}

		vector<int> Index;
		for (int z = zMin; z < zMax; z++)
		{
			//예외처리
			if (z < 0 || z >= getGroup->CountZ)
				continue;

			for (int y = yMin; y < yMax; y++)
			{
				if (y < 0 || y >= getGroup->CountY)
					continue;

				for (int x = xMin; x < xMax; x++)
				{
					if (x < 0 || x >= getGroup->CountX)
						continue;

					int	idx = z * (getGroup->CountX * getGroup->CountY) + y * getGroup->CountX + x;
					((Collider_Com*)*StartIter)->AddCollisionSection(idx);
					Index.push_back(idx);

					CollsionSelection* getSection = &getGroup->SelectionList[idx];
					
					//배열 재할당과정
					if (getSection->Capacity == getSection->Size)
					{
						getSection->Capacity *= 2;

						Collider_Com** Temp = new Collider_Com*[getSection->Capacity];
						memcpy(Temp, getSection->ColliderList, getSection->Size);
						SAFE_DELETE_ARRARY(getSection->ColliderList);

						getSection->ColliderList = Temp;
					}
					getSection->ColliderList[idx] = ((Collider_Com*)*StartIter);
					getSection->Size++;
				}
			}
		}
		((Collider_Com*)*StartIter)->Release();
	}
}

CollsionManager::CollsionGroup * CollsionManager::FindGroup(const string & KeyName)
{
	unordered_map<string, CollsionGroup*>::iterator FindIter = m_GroupMap.find(KeyName);

	if (FindIter == m_GroupMap.end())
		return NULLPTR;

	return FindIter->second;
}
