#include "DXUT.h"
#include "cItem.h"

cItem::cItem(Vec2 pos)
	:m_pos(pos)
{
}

cItem::~cItem()
{
}

void cItem::Update()
{
	m_pos.y += 300 * Delta;
}

void cItem::Render()
{
	RENDER->CenterRender(m_image, m_pos);
}

bool cItem::IsOutMap()
{
	return (m_pos.x < -200
		|| m_pos.x > WINSIZEX + 200
		|| m_pos.y < -200
		|| m_pos.y > WINSIZEY + 200);
}