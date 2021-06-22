#pragma once
#include "cScene.h"
#include "cCollision.h"
class cTitleScene
	: public cScene
{
public:
	cTitleScene();
	~cTitleScene();

	bool bStartBtnOver = false;
	bool bQuitBtnOver = false;
	bool bGameStart = false;
	bool bGameQuit = false;

	Vec2 downPos;
	Vec2 upPos;

	cCollision* coll;

	//cScene을 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};