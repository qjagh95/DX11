#pragma once
#include "stdafx.h"

JEONG_BEGIN

class JEONG_DLL RefCount
{
public:
	RefCount();
	virtual ~RefCount() = 0;

	string GetTag() const { return m_TagName;}
	void SetTag(const string& TagName) { m_TagName = TagName; }
	int AddRefCount() { ReferanceCount++; return ReferanceCount; }
	int Release();

protected:
	string m_TagName;
	int ReferanceCount;
};

JEONG_END
