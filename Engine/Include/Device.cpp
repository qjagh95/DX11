#include "Device.h"

JEONG_USING

SINGLETON_VAR_INIT(Device);

Device::Device()
{
}

Device::~Device()
{
}

bool Device::Init(HWND hWnd, unsigned int Width, unsigned int Height, bool isWindowMode)
{
	return true;
}
