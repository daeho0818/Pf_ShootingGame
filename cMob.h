#pragma once
#include "cPlayer.h"
class cMob abstract
{
public:
	cMob(Vec2 pos) : m_pos(pos) {}
	virtual ~cMob() {}

	Vec2 m_pos;
	Vec2 SpawnPos;
	float m_hp;
	float m_damage;
	float m_size;
	bool isDestroy = false;
	cPlayer* m_player;

	string mobType;
	string mobName;
	
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void UIRender() = 0;
	bool IsOutMap();
};