#pragma once
#include "2. Manager/singleton.h"
class cInputManager :
	public singleton<cInputManager>
{
	bool nowkey[256]; // ��� ���� Ű ����
	bool oldkey[256]; // ������ ���� ���� Ű ����
public:
	cInputManager();
	~cInputManager();

	// Update() : � Ű���尡 ���ȴ��� �˻�
	void Update();
	// KeyPress() : Ű���尡 ������ ���� �� true, �ƴϸ� false�� ��ȯ�ϴ� �Լ�
	bool KeyPress(int key);
	// KeyDown() : Ű���尡 "������ ��" true��, �ƴϸ� false�� ��ȯ�ϴ� �Լ�
	bool KeyDown(int key);
	// KeyUp() : Ű���尡 "������ ��" true��, �ƴϸ� false�� ��ȯ�ϴ� �Լ�
	bool KeyUp(int key);
};

#define INPUT cInputManager::GetInstance()