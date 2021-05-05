#pragma once
#include "cMob.h"
class cRifle
	:public cMob
{
public:
	cRifle(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	~cRifle();
	cTimer* AS = nullptr;
	vector<cBullet*>& m_bullet;
	bool fire = true;
	bool ready = true;
	int count = 0;

	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};