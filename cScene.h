#pragma once
class cScene abstract
{
public:
	cScene() {}
	~cScene() {}

	//virtual void func() = 0; -> 순수 가상 함수 : 상속된 클래스에서 재정의해야 하는 함수
	// Init() : 초기화하는 함수 -> cTitleScene등 씬들의 Update() 함수 실행
	virtual void Init() = 0;
	// Update() : 계속 실행되는 함수 -> cTitleScene등 씬들의 Update() 함수 실행 (플레이어 이동 등 대체로 계속 바뀌는 것들)
	virtual void Update() = 0;
	// Render() : 계속 실행되는 함수 -> cTitleScene등 씬들의 Render() 함수 실행 (이미지 띄우기 등 대체로 바뀌지 않는 것들)
	virtual void Render() = 0;
	// UIRender() : 계속 실행되는 함수 -> cTitleScene등 씬들의 UIRender() 함수 실행 (이미지 띄우기 등 대체로 바뀌지 않는 것들)
	virtual void UIRender() = 0;
	// Release() : 데이터를 지워주는 함수 -> cTitleScene등 씬들의 Release() 함수 실행
	virtual void Release() = 0;

	// cEndingScene.h, cTitleScene.h, cIngameScene.h 에 상속됨
};