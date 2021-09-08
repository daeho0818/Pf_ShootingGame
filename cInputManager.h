#pragma once
#include "2. Manager/singleton.h"
class cInputManager :
	public singleton<cInputManager>
{
	bool nowkey[256]; // 방금 누른 키 저장
	bool oldkey[256]; // 누른지 한턴 지난 키 저장
	Vec2 mousePos;
public:
	cInputManager();
	~cInputManager();

	// Update() : 어떤 키보드가 눌렸는지 검사
	void Update();
	// KeyPress() : 키보드가 눌리고 있을 때 true, 아니면 false를 반환하는 함수
	bool KeyPress(int key);
	// KeyDown() : 키보드가 "눌렸을 때" true를, 아니면 false를 반환하는 함수
	bool KeyDown(int key);
	// KeyUp() : 키보드가 "떼졌을 때" true를, 아니면 false를 반환하는 함수
	bool KeyUp(int key);

	Vec2 GetMousePos();
	void SetMousePos(Vec2 mousePos);

	bool LButtonDown();
	bool LButtonUp();

	bool downLButton = false;
	bool upLButton = false;
};

#define INPUT cInputManager::GetInstance()