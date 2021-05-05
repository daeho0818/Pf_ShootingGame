#pragma once
#include "cBullet.h"
class cPlayer
{
public:
	Vec2 m_pos;
	vector<cBullet*>& m_bullet;
	cTimer* playerAS = nullptr;

	bool b_fire = true;
	bool saveHeal = false;
	bool playerSkill = true;

	float m_Hp;
	float m_MaxHp;
	float skillPoint = 12;

	string ItemName;

	cPlayer(vector<cBullet*>& bullet);
	~cPlayer();

	void Update();
	void Render();
	void UIRender();

	void Move();
	void FireBullet();
	void ItemUpdate();
	void Heal();
};