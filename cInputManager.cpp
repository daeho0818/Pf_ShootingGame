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
	for (int i = 0; i < 256; i++) oldkey[i] = nowkey[i]; // oldkey의 모든 요소를 nowkey로 초기화
	for (int i = 0; i < 256; i++)
	{
		// GetAsyncKeyState() : 키보드 입력 처리하는 함수
		if (GetAsyncKeyState(i)) nowkey[i] = true; // 누른 키보드 i에 맞는 nowkey의 i번째 요소에 true 대입
		else nowkey[i] = false; // 그 외 다른 요소 전부에 false 대입
	}
}

bool cInputManager::KeyPress(int key)
{
	return nowkey[key] && oldkey[key]; 
	// 키보드가 "눌렸을 때" true가 되는 nowkey와 눌린 상태에서 한턴 뒤에 true가 되는 oldkey를 통해둘다 true일 때 true 반환
}

bool cInputManager::KeyDown(int key)
{
	return nowkey[key] && !oldkey[key];
	// 키보드가 "눌렸을 때" : nowkey는 true가 됐지만 oldkey는 아직 false인 상태
}

bool cInputManager::KeyUp(int key)
{
	return !nowkey[key] && oldkey[key];
	// 키보드가 "떼졌을 때" : nowkey는 false가 됐지만 oldkey는 아직 true인 상태
}

Vec2 cInputManager::GetMousePos()
{
	return mousePos;
}

void cInputManager::SetMousePos(Vec2 mousePos)
{
	this->mousePos = mousePos;
}
