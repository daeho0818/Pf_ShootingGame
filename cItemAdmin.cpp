#include "DXUT.h"
#include "cItemAdmin.h"
#include "cHeal.h"

cItemAdmin::cItemAdmin(cPlayer* player)
	:m_player(player)
{
}

cItemAdmin::~cItemAdmin()
{
	for (auto iter : m_items) SAFE_DELETE(iter);
	m_items.clear();
}

void cItemAdmin::Update()
{
	for (auto iter : m_items) iter->Update();
	CreateItem();
	IsOut();
	IsDestroy();
}

void cItemAdmin::Render()
{
	for (auto iter : m_items)iter->Render();
}

void cItemAdmin::CreateItem()
{
	if (mobDead)
	{
		CreatePercent = rand() % 4;
		if (CreatePercent <= 1)
		{
			m_items.push_back(new cHeal(mobPos));
			mobDead = false;
		}
		else
			mobDead = false;
	}
}

void cItemAdmin::IsOut()
{
	for (auto& iter = m_items.begin(); iter != m_items.end();)
	{
		if ((*iter)->IsOutMap())
		{
			SAFE_DELETE(*iter);
			iter = m_items.erase(iter);
		}
		else
			iter++;
	}
}

void cItemAdmin::IsDestroy()
{
	for (auto& iter = m_items.begin(); iter != m_items.end();)
	{
		if ((*iter)->isDestroy)
		{
			SAFE_DELETE(*iter);
			iter = m_items.erase(iter);
		}
		else
			iter++;
	}
}