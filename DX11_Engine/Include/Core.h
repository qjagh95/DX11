#pragma once
#include "stdafx.h"

JEONG_BEGIN

class JEONG_DLL Core
{
public:
	bool Init(HINSTANCE hInst, unsigned int Width,	unsigned int Height, const TCHAR* TitleName, const TCHAR* ClassName, int iIconID, int iSmallIconID,	bool bWindowMode = true);
	bool Init(HINSTANCE hInst, HWND hWnd, unsigned int Width, unsigned int Height, bool bWindowMode = true);
	int Run();

private:
	void Register(const TCHAR* ClassName, int iIconID, int iSmallIconID);
	void CreateWnd(const TCHAR* TitleName, const TCHAR* ClassName);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	static bool m_isLoop;
	HINSTANCE m_hIstance;
	WinSize m_WinSize;
	HWND m_hWnd;

public:
	CLASS_IN_SINGLE(Core);
};

JEONG_END
