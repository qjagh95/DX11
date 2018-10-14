#pragma once

#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <crtdbg.h>
#include <conio.h>
#include <assert.h>

//DX11���ʹ� ���Ե��͸� ���̺귯�� ���͸� �߰����� �ٷ� ����߰��� �����ϴ�.
//�������� ������Ʈ ���ø�(VS���)�� �̿��Ͽ� ������Ʈ�� ���� �������� �߰��ؼ� ����ߴ�.
#include <d3d11.h>
#include <d3dcompiler.h> //shader�� �������ϴ� ����� �����Ѵ�.

//DirectX11���� �����ϴ� ���� ����� ����ϱ�����
#include <DirectXMath.h>
#include <DirectXPackedVector.h> //�����Ǵ� ���͵��� ����ϱ�����

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3d11")
#pragma comment(lib, "d3dcompiler")

#include "Type.h"
#include "Macro.h"