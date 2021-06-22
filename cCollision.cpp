#include "DXUT.h"
#include "cCollision.h"

cCollision::cCollision(vector<cBullet*>& bullet, vector<cMob*>& m_mob, cPlayer* player, cItemAdmin* itemAd)
	:m_bullet(bullet), m_player(player), m_mob(m_mob), m_itemAd(itemAd), m_item(m_itemAd->m_items)
{
}

cCollision::~cCollision()
{
}

void cCollision::Update()
{
	MPColl();
	MBPColl();
	MPBColl();
	IPColl();
}

void cCollision::MPColl() //플레이어와 몹
{
	for (auto iter = m_mob.begin(); iter != m_mob.end();)
	{
		if (7 + (*iter)->m_size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
		{
			if (b_PMcoll)
			{
				if ((*iter)->mobType == "Boss")
					b_PMcoll = false;
				m_player->m_Hp -= (*iter)->m_damage * 3;
				PART->AddParticle((*iter)->m_pos, 4, 1);
				if ((*iter)->mobType != "Boss")
					(*iter)->isDestroy = true;
			}

			else
			{
				if ((*iter)->mobType == "Boss") b_PMcoll = true;
			}
		}
			iter++;
	}
}
void cCollision::MPBColl() //플레이어 총알과 몹
{
	for (auto miter = m_mob.begin(); miter != m_mob.end();)
	{
		bool b_coll = false;
		for (auto biter = m_bullet.begin(); biter != m_bullet.end();)
		{
			if ((*biter)->bulletType == "player")
			{
				if ((*biter)->size + (*miter)->m_size >= D3DXVec2Length(&((*biter)->m_pos - (*miter)->m_pos)) && (*miter)->m_hp > 0)
				{
					(*miter)->m_hp--;
					PART->AddParticle((*biter)->m_pos, partSize, 1);
					b_coll = true;
					(*biter)->isDestroy = true;
				}
			}
			biter++;
		}
		if (b_coll)
		{
			if ((*miter)->m_hp <= 0)
			{
				m_itemAd->mobDead = true;
				m_itemAd->mobPos = (*miter)->m_pos;
				(*miter)->isDestroy = true;
				if(m_player->skillPoint < 12)
					m_player->skillPoint++;
			}
		}
		miter++;
	}
}

void cCollision::MBPColl() //적 총알과 플레이어
{
	for (auto iter = m_bullet.begin(); iter != m_bullet.end();)
	{
		if ((*iter)->bulletType == "mob")
		{
			if (7 + (*iter)->size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
			{
				SOUND->Play("playerHurt");
				m_player->m_Hp -= (*iter)->m_Damage;
				PART->AddParticle((*iter)->m_pos, 4, 0);
				(*iter)->isDestroy = true;
			}
		}
		iter++;
	}
}

void cCollision::IPColl()
{
	for (auto iter = m_item.begin(); iter != m_item.end();) //아이템과 플레이어
	{
		if (7 + (*iter)->m_size >= D3DXVec2Length(&(m_player->m_pos - (*iter)->m_pos)))
		{
			m_player->ItemName = (*iter)->itemName;
			(*iter)->isDestroy = true;
		}
		iter++;
	}
}

bool cCollision::CheckCollision(Vec2 pos1, Vec2 pos2, cTexture* ptr, float size)
{
	RECT rect = {
		pos2.x - ptr->info.Width / 2 * size,
		pos2.y - ptr->info.Height / 2 * size,
		pos2.x + ptr->info.Width / 2 * size,
		pos2.y + ptr->info.Height / 2 * size,
	};

	if (pos1.x >= rect.left && pos1.x <= rect.right && pos1.y >= rect.top && pos1.y <= rect.bottom)
	{
		return true;
	}
	return false;
}