#include "DXUT.h"
#include "cInputManager.h"

cInputManager::cInputManager()
{
}

cInputManager::~cInputManager()
{
}

void cInputManager::Update()
{
	for (int i = 0; i < 256; i++) oldkey[i] = nowkey[i]; // oldkey�� ��� ��Ҹ� nowkey�� �ʱ�ȭ
	for (int i = 0; i < 256; i++)
	{
		// GetAsyncKeyState() : Ű���� �Է� ó���ϴ� �Լ�
		if (GetAsyncKeyState(i)) nowkey[i] = true; // ���� Ű���� i�� �´� nowkey�� i��° ��ҿ� true ����
		else nowkey[i] = false; // �� �� �ٸ� ��� ���ο� false ����
	}
}

bool cInputManager::KeyPress(int key)
{
	return nowkey[key] && oldkey[key]; 
	// Ű���尡 "������ ��" true�� �Ǵ� nowkey�� ���� ���¿��� ���� �ڿ� true�� �Ǵ� oldkey�� ����	�Ѵ� true�� �� true ��ȯ
}

bool cInputManager::KeyDown(int key)
{
	return nowkey[key] && !oldkey[key];
	// Ű���尡 "������ ��" : nowkey�� true�� ������ oldkey�� ���� false�� ����
}

bool cInputManager::KeyUp(int key)
{
	return !nowkey[key] && oldkey[key];
	// Ű���尡 "������ ��" : nowkey�� false�� ������ oldkey�� ���� true�� ����
}