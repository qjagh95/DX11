#include "Core.h"

JEONG_USING

SINGLETON_VAR_INIT(Core)
bool Core::m_isLoop = true;

Core::Core()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(5399);
}

Core::~Core()
{
}

bool Core::Init(HINSTANCE hInst, unsigned int Width, unsigned int Height, const TCHAR * TitleName, const TCHAR * ClassName, int iIconID, int iSmallIconID, bool bWindowMode)
{
	m_hIstance = hInst;
	m_WinSize.Width = Width;
	m_WinSize.Height = Height;

	Register(ClassName, iIconID ,iSmallIconID);
	CreateWnd(TitleName, ClassName);
	
	return Init(m_hIstance,m_hWnd, Width, Height, bWindowMode);

	return true;
}

bool Core::Init(HINSTANCE hInst, HWND hWnd, unsigned int Width, unsigned int Height, bool bWindowMode)
{

	return true;
}

int Core::Run()
{
	MSG msg;

	while (m_isLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			//Logic();
		}
	}
	return (int)msg.wParam;
}

void Core::Register(const TCHAR * ClassName, int iIconID, int iSmallIconID)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Core::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hIstance;
	wcex.hIcon = LoadIcon(m_hIstance, MAKEINTRESOURCE(iIconID));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = ClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(iSmallIconID));

	RegisterClassEx(&wcex);
}

void Core::CreateWnd(const TCHAR * TitleName, const TCHAR * ClassName)
{
	m_hWnd = CreateWindow(ClassName, TitleName, WS_OVERLAPPEDWINDOW,	CW_USEDEFAULT, 0, m_WinSize.Width, m_WinSize.Height, NULL, NULL, m_hIstance, NULL);

	if (!m_hWnd)
		return;

	RECT rc = { 0, 0, (LONG)m_WinSize.Width, (LONG)m_WinSize.Height };

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
}

LRESULT Core::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
			m_isLoop = false;
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
