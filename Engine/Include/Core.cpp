#include "Core.h"
#include "Device.h"
#include "./Resource/ResourceManager.h"
#include "PathManager.h"

JEONG_USING

SINGLETON_VAR_INIT(Core)
bool Core::m_isLoop = true;

Core::Core()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(5399);

	ZeroMemory(ClearColor, sizeof(float) * 4);
}

Core::~Core()
{
	Device::Delete();
	ResourceManager::Delete();
}

bool Core::Init(HINSTANCE hInst, unsigned int Width, unsigned int Height, const TCHAR * TitleName, const TCHAR * ClassName, int iIconID, int iSmallIconID, bool bWindowMode)
{
	m_hIstance = hInst;
	m_WinSize.Width = Width;
	m_WinSize.Height = Height;

	Register(ClassName, iIconID ,iSmallIconID);
	CreateWnd(TitleName, ClassName);
	
	return Init(m_hIstance,m_hWnd, Width, Height, bWindowMode);
}

bool Core::Init(HINSTANCE hInst, HWND hWnd, unsigned int Width, unsigned int Height, bool bWindowMode)
{
	m_hIstance = hInst;
	m_hWnd = hWnd;
	m_WinSize.Width = Width;
	m_WinSize.Height = Height;

	//DirectX11 Device초기화
	if (Device::Get()->Init(hWnd, Width, Height, bWindowMode) == false)
		return false;

	if (ResourceManager::Get()->Init() == false)
		return false;

	if (PathManager::Get()->Init() == false)
		return false;

	SetClearColor(0, 150, 255, 0);

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
			Logic();
		}
	}
	return (int)msg.wParam;
}

void Core::Logic()
{
	Input(0.0f);
	Update(0.0f);
	LateUpdate(0.0f);
	Collsion(0.0f);
	CollsionAfterUpdate(0.0f);
	Render(0.0f);
}

void Core::SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	ClearColor[0] = r / 255.0f;
	ClearColor[1] = g / 255.0f;
	ClearColor[2] = b / 255.0f;
	ClearColor[3] = a / 255.0f;
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
	wcex.lpszMenuName = NULLPTR;
	wcex.lpszClassName = ClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(iSmallIconID));

	RegisterClassEx(&wcex);
}

void Core::CreateWnd(const TCHAR * TitleName, const TCHAR * ClassName)
{
	m_hWnd = CreateWindow(ClassName, TitleName, WS_OVERLAPPEDWINDOW,	CW_USEDEFAULT, 0, m_WinSize.Width, m_WinSize.Height, NULLPTR, NULLPTR, m_hIstance, NULLPTR);

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

int Core::Input(float DeltaTime)
{
	return 0;
}

int Core::Update(float DeltaTime)
{
	return 0;
}

int Core::LateUpdate(float DeltaTime)
{
	return 0;
}

void Core::Collsion(float DeltaTime)
{
}

int Core::CollsionAfterUpdate(float DeltaTime)
{
	return 0;
}

void Core::Render(float DeltaTime)
{
	Device::Get()->Clear(ClearColor);
	{
		//여기에 출력한다.
	}
	Device::Get()->Present();
}
