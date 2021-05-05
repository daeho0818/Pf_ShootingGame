#pragma once
#include "cMob.h"
class cBoss
	:public cMob
{
public:
	cBoss(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet, int mobNumber = 0);
	virtual ~cBoss();

	int random;
	int mobNumber;
	int count = 0;
	char chkLR = 'L';
	Vec2 UIPos;
	Vec2 curPos;
	vector<cBullet*>& m_bullet;
	cTimer* Pattern1T = nullptr;
	cTimer* Pattern2T = nullptr;
	cTimer* Pattern3T = nullptr;

	bool pattern1 = true;
	bool pattern2 = true;
	bool pattern3 = true;
	bool bMove = true;

	//cMob을 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	void Pattern1();
	void Pattern2();
	void Pattern3();
};