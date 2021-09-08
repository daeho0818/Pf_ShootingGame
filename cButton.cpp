#include "DXUT.h"
#include "cButton.h"

cButton::~cButton()
{
}
cTexture* cButton::GetImg(int index)
{
	cTexture* images[3] = { m_basicImg, m_overImg, m_pressedImg };
	return images[index];
}

void cButton::InitImgs(cTexture* basicImg, cTexture* overImg, cTexture* pressedImg)
{
	m_basicImg = basicImg;
	m_overImg = overImg;
	m_pressedImg = pressedImg;
}
void cButton::SetImg(int index)
{
	cTexture* images[3] = { m_basicImg, m_overImg, m_pressedImg };
	m_img = images[index];
}

void cButton::SetImg(cTexture* img)
{
	m_img = img;
}

Vec2 cButton::GetPos()
{
	return m_pos;
}

float cButton::GetSize()
{
	return m_size;
}

function<void()> cButton::GetFunc()
{
	return m_func;
}

bool cButton::ChkCollision(Vec2 position)
{
	return (position.x >= m_rect.left && position.x <= m_rect.right && position.y >= m_rect.top && position.y <= m_rect.bottom);
}
