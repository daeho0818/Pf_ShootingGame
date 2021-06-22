#pragma once
#include "cScene.h"
#include "cCollision.h"
class cEndingScene
	:public cScene
{
public:
	cEndingScene();
	~cEndingScene();

	bool bTitle = false;
	bool bExit = false;
	bool bTitleBtnOver = false;
	bool bQuitBtnOver = false;

	cCollision* coll;

	Vec2 downPos;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};