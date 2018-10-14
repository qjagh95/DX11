#include "RefCount.h"

JEONG_USING

RefCount::RefCount(): ReferanceCount(1)
{
}

RefCount::~RefCount()
{    
}

int RefCount::Release()
{
	ReferanceCount--;

	if (ReferanceCount == 0)
	{
		delete this;
		return 0;
	}
	return ReferanceCount;
}
