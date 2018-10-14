#pragma once

struct WinSize
{
	unsigned int Width;
	unsigned int Height;

	WinSize() : Width(0), Height(0) {}
	WinSize(const WinSize& size) {*this = size;}
	WinSize(unsigned int Width, unsigned Height) : Width(Width), Height(Height) {}
};