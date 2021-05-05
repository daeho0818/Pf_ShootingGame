#pragma once
#include "cScene.h"
#include "cScrollMap.h"
#include "cPlayer.h"
#include "cMob.h"
#include "cBalloon.h"
#include "cBulletAdmin.h"
#include "cMobAdmin.h"
#include "cCollision.h"
#include "cItemAdmin.h"
class cIngameScene2
	: public cScene
{
	cScrollMap* map = nullptr;
	cPlayer* player = nullptr;
	cBulletAdmin* bullet = nullptr;
	cMobAdmin* mob = nullptr;
	cCollision* coll = nullptr;
	cItemAdmin* item = nullptr;
	bool playerSkill = true;

	bool left = false, right = true;
	float pos_x = 0;
	cTimer* AS = nullptr;
public:
	cIngameScene2();
	virtual ~cIngameScene2();

	//cScene을 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;

	void PlayerSkill();
	void SceneChange();
	void PrintStageTxt();
};