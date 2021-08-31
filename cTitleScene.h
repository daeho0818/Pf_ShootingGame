#pragma once
#include "cScene.h"
#include "cCollision.h"
class cTitleScene
	: public cScene
{
public:
	cTitleScene();
	~cTitleScene();

	//cScene을 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;

private:
	bool bStartBtnOver = false;
	bool bQuitBtnOver = false;
	bool bGameStart = false;
	bool bGameQuit = false;
	bool isMoonUp = false;

	float moon_oper_value = 0;
	
	int cloud_oper_value[2] = { 0, };
	int mountains_oper_value[2] = { 0, };

	Vec2 downPos;
	Vec2 upPos;
	Vec2 playerPos;

	cCollision* coll;
};