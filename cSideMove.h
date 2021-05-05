#pragma once
#include "cMob.h"
class cSideMove
	:public cMob
{
public:
	cSideMove(Vec2 pos, cPlayer* player, vector<cBullet*> &bullet);
	~cSideMove();
	cTimer* AS = nullptr;
	vector<cBullet*>& m_bullet;
	bool fire = true;
	int random;

	//cMob�� ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;

	void MoveToSide();
};