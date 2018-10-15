#include "Collider_Com.h"

#include "../Device.h"

#include "../Resource/Mesh.h"

#include "../Render/Shader.h"
#include "../Render/ShaderManager.h"
#include "../Render/RenderManager.h"
#include "../Render/RenderState.h"

JEONG_USING

Collider_Com::Collider_Com()
{
	m_CollType = CT_RECT;
	m_CollisionGroupName = "Default";
	m_UpdateCollision = true;

#ifdef _DEBUG
	m_Shader = NULLPTR;
	m_Layout = NULLPTR;
	m_Mesh = NULLPTR;
	m_DepthDisable = NULLPTR;
#endif // _DEBUG

}

Collider_Com::Collider_Com(const Collider_Com & CopyCollider)
	:Component_Base(CopyCollider)
{
#ifdef _DEBUG
	m_Layout = CopyCollider.m_Layout;
	m_Mesh = CopyCollider.m_Mesh;
	m_Shader = CopyCollider.m_Shader;
	m_DepthDisable = CopyCollider.m_DepthDisable;

	if (m_Shader)
		m_Shader->AddRefCount();

	if (m_Mesh)
		m_Mesh->AddRefCount();

	if (m_DepthDisable)
		m_DepthDisable->AddRefCount();
#endif // _DEBUG
}

Collider_Com::~Collider_Com()
{
	SAFE_RELEASE(m_DepthDisable);
	SAFE_RELEASE(m_Shader);
	SAFE_RELEASE(m_Mesh);
}

bool Collider_Com::Init()
{
	return true;
}

int Collider_Com::Input(float DeltaTime)
{
	return 0;
}

int Collider_Com::Update(float DeltaTime)
{
	return 0;
}

int Collider_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Collider_Com::Collision(float DeltaTime)
{
}

void Collider_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Collider_Com::Render(float DeltaTime)
{
}

bool Collider_Com::CheckPrevCollision(Collider_Com * Dest)
{
	list<Collider_Com*>::iterator StartIter = m_PrevCollision.begin();
	list<Collider_Com*>::iterator EndIter = m_PrevCollision.end();

	for (; StartIter != EndIter; StartIter++)
	{
		if ((*StartIter) == Dest)
			return true;
	}	

	return false;
}

void Collider_Com::ErasePrevCollision(Collider_Com * Dest)
{
	list<Collider_Com*>::iterator StartIter = m_PrevCollision.begin();
	list<Collider_Com*>::iterator EndIter = m_PrevCollision.end();

	for (; StartIter != EndIter; StartIter++)
	{
		if ((*StartIter) == Dest)
		{
			m_PrevCollision.erase(StartIter);
			return;
		}
	}
}

void Collider_Com::CheckPrevCollisionInSection(float DeltaTime)
{
	/*
	list<CCollider*>::iterator	iter;
	list<CCollider*>::iterator	iterEnd = m_PrevCollision.end();

	for (iter = m_PrevCollision.begin(); iter != iterEnd;)
	{
		if (m_strCollisionGroup != (*iter)->m_strCollisionGroup)
		{
			OnCollisionLeave((*iter), fTime);
			(*iter)->OnCollisionLeave(this, fTime);

			(*iter)->ErasePrevCollision(this);
			iter = m_PrevCollision.erase(iter);

			iterEnd = m_PrevCollision.end();
			continue;
		}

		const list<int>*	pSectionList = (*iter)->GetColisionSection();
		list<int>::const_iterator	iter1;
		list<int>::const_iterator	iter1End = pSectionList->end();


		list<int>::iterator	iter2;
		list<int>::iterator	iter2End = m_CollisionSectionList.end();

		bool	bPair = false;

		for (iter1 = pSectionList->begin(); iter1 != iter1End; ++iter1)
		{
			for (iter2 = m_CollisionSectionList.begin(); iter2 != iter2End; ++iter2)
			{
				if (*iter1 == *iter2)
				{
					bPair = true;
					break;
				}
			}

			if (bPair)
				break;
		}

		if (!bPair)
		{
			OnCollisionLeave((*iter), fTime);
			(*iter)->OnCollisionLeave(this, fTime);

			(*iter)->ErasePrevCollision(this);
			iter = m_PrevCollision.erase(iter);

			iterEnd = m_PrevCollision.end();
			continue;
		}
		++iter;
	}
	*/

}

void Collider_Com::SetCollsionCallback(COLLSION_CALLBACK_TYPE eType, void(*pFunc)(Collider_Com *, Collider_Com *, float))
{
	function<void(Collider_Com *, Collider_Com *, float)> newFunc;

	newFunc = bind(pFunc, placeholders::_1, placeholders::_2, placeholders::_3);
	m_CollisionFunc[eType].push_back(newFunc);
}
