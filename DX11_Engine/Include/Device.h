#pragma once

#include "stdafx.h"

JEONG_BEGIN

class JEONG_DLL Device
{
public:
	bool Init(HWND hWnd, unsigned int Width, unsigned int Height, bool isWindowMode);

private:
	//Com - Component Object�� ���� - ���� RefCount������� ���ư���.
	//Device�����͵��� Com�� ��ӹ޴´�(RefCount)

	//DX�� �������۸������ �������ø����� ����Ѵ�.
	//�������ø��� - ����ۿ� �׸���->���۹��� �� ǥ���̵ǰ� �� ǥ���� ����۰��ȴ�.��� �Դٰ����ϴ� ���. (����Ʈ�� �����Ϳ���� ���)
	//�����ϴ� �۾��� ���⶧���� �� ������ (API�� BitBlt - �ȼ��� ����)

	//11�� ��Ƽ�����巣������ �����ϴٴ����� ������.
	//��Ƽ������ - ����ó�����α׷��� 1���Լ����� 2���Լ����� ����

	//11���ʹ� ����̽� ���ؽ�Ʈ�� �����ִ�

	//1. �̵̹�������ؽ�Ʈ - �Ϲ������� ���(��ö�¶�)
	//2. ���۵����ؽ�Ʈ - ��Ƽ������

	//9�� ����̽��� ���� ����ϴٺ��� 11���ʹ� ����
	//����̽��� ���� ���ۻ��� ���ؽ�Ʈ�� �̿��Ͽ� ���¼������Ѵ�.

	ID3D11Device* m_Device;
	ID3D11DeviceContext* m_Context;
	//����ü�� - ����۸� �������ٳ�(�����츦 �ø��� ����ü���� �þ�� �̰��� Ȱ���ϸ� ����ȭ��, ����ȭ��, �ĸ�ȭ�� ���� �� �� �ִ�)
	IDXGISwapChain* m_SwapChain;

public:
	CLASS_IN_SINGLE(Device)
};

JEONG_END