#include "Core.h"
#include "resource.h"

JEONG_USING

int APIENTRY wWinMain(_In_ HINSTANCE hIstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	if (Core::Get()->Init(hIstance, 1280, 720, TEXT("JeongRealEngine"), TEXT("JeongRealEngine"), IDI_ICON1, IDI_ICON1) == false)
	{
		Core::Delete();
		return 0;
	}	
	//DLL���� ������ �̱��水ü�� ���⼭ ������ �̱��水ü�� ���� �ٸ���ü��.

	//Run���� �޼��� ���ѷ�����(����) ����.
	//������ Delete, Result = 0;
	//�̱��� ����

	int Result = Core::Get()->Run();
	Core::Delete();

	return Result;
}