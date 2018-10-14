#pragma once
#include "stdafx.h"

JEONG_BEGIN

class JEONG_DLL Core
{
public:
	bool Init(HINSTANCE hInst, unsigned int Width,	unsigned int Height, const TCHAR* TitleName, const TCHAR* ClassName, int iIconID, int iSmallIconID,	bool bWindowMode = true);
	bool Init(HINSTANCE hInst, HWND hWnd, unsigned int Width, unsigned int Height, bool bWindowMode = true);
	int Run();
	void Logic();

	void SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

private:
	void Register(const TCHAR* ClassName, int iIconID, int iSmallIconID);
	void CreateWnd(const TCHAR* TitleName, const TCHAR* ClassName);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	int Input(float DeltaTime);
	int Update(float DeltaTime);
	int LateUpdate(float DeltaTime);
	void Collsion(float DeltaTime);
	int CollsionLateUpdate(float DeltaTime);
	void Render(float DeltaTime);

private:
	static bool m_isLoop;
	HINSTANCE m_hIstance;
	WinSize m_WinSize;
	HWND m_hWnd;
	float ClearColor[4];

public:
	CLASS_IN_SINGLE(Core);
};

JEONG_END
