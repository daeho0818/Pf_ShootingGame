#pragma once
#include "cMob.h"
class cBalloon
	:public cMob
{
public:
	cBalloon(Vec2 pos, cPlayer* player, vector<cBullet*> &bullet);
	~cBalloon();

	cTimer* AS = nullptr;
	vector<cBullet*>& m_bullet;
	bool fire = true;

	//cMob 을 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};