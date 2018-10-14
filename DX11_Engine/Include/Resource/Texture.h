#pragma once
#include "../RefCount.h"

JEONG_BEGIN

class JEONG_DLL Texture : public RefCount
{

private:	
	Texture();
	~Texture();

public:
	friend class ResourceManager;
};

JEONG_END

