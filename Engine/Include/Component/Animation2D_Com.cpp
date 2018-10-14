#include "Animation2D_Com.h"

#include "../PathManager.h"

#include "../Resource/ResourceManager.h"
#include "../Resource/Texture.h"

JEONG_USING

Animation2D_Com::Animation2D_Com()
{
	m_ComType = CT_ANIMATION;
}

Animation2D_Com::Animation2D_Com(const Animation2D_Com& copyData)
{
	m_DefaultClipName = copyData.m_DefaultClipName;
	m_ClipMap.clear();

	unordered_map<string, AnimationClip2D*>::const_iterator	StartIter = copyData.m_ClipMap.begin();
	unordered_map<string, AnimationClip2D*>::const_iterator	EndIter = copyData.m_ClipMap.end();

	for (;StartIter != EndIter ; StartIter++ )
	{
		AnimationClip2D* CopyClip = new AnimationClip2D();

		*CopyClip = *(StartIter->second);
		CopyClip->CurTexture->AddRefCount();

		m_ClipMap.insert(make_pair(StartIter->first, CopyClip));

		if (copyData.m_CurClip->AnimationName == StartIter->first)
			m_CurClip = CopyClip;
	}
}

Animation2D_Com::~Animation2D_Com()
{
	unordered_map<string, AnimationClip2D*>::iterator	StartIter = m_ClipMap.begin();
	unordered_map<string, AnimationClip2D*>::iterator	EndIter = m_ClipMap.end();

	for (;StartIter != EndIter; StartIter++)
	{
		SAFE_RELEASE(StartIter->second->CurTexture);
		SAFE_DELETE(StartIter->second);
	}
}

bool Animation2D_Com::Init()
{
	return true;
}

int Animation2D_Com::Input(float DeltaTime)
{
	return 0;
}

int Animation2D_Com::Update(float DeltaTime)
{
	return 0;
}

int Animation2D_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Animation2D_Com::Collision(float DeltaTime)
{
}

void Animation2D_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Animation2D_Com::Render(float DeltaTime)
{
}

Animation2D_Com * Animation2D_Com::Clone()
{
	return new Animation2D_Com(*this);
}

void Animation2D_Com::AddClip(const string & AnimationName, ANIMATION2D_TYPE Type, ANIMATION_OPTION Option, float PlayLimitTime, const vector<Clip2DFrame>& vecFrame, const string & TexKey, const TCHAR * FileName, const string & PathKey)
{
	AnimationClip2D* newClip = FindClip(AnimationName);

	if (newClip != NULLPTR)
		return;

	ResourceManager::Get()->CreateTexture(TexKey, FileName, PathKey);

	newClip = new AnimationClip2D();
	newClip->AnimationName = AnimationName;
	newClip->AnimationOption = Option;
	newClip->AnimationType = Type;
	newClip->PlayLimitTime = PlayLimitTime;
	newClip->PlayTime = 0.0f;
	newClip->Frame = 0;
	newClip->CurTexture = ResourceManager::Get()->FindTexture(TexKey);
	newClip->TextureHeight = (float)newClip->CurTexture->GetHeight();
	newClip->TextureWidth = (float)newClip->CurTexture->GetWidth();

	m_ClipMap.insert(make_pair(AnimationName, newClip));
}

AnimationClip2D * Animation2D_Com::FindClip(const string & KeyName)
{
	unordered_map<string, AnimationClip2D*>::iterator FindIter = m_ClipMap.find(KeyName);

	if (FindIter == m_ClipMap.end())
		return NULLPTR;

	return FindIter->second;
}
