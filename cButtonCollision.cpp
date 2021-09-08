#include "DXUT.h"
#include "cButtonCollision.h"

cButtonCollision::cButtonCollision()
{
	lButton = false;
}

cButtonCollision::~cButtonCollision()
{
	Release();
}

void cButtonCollision::AddButton(cButton* button)
{
	m_buttons.push_back(button);
}

void cButtonCollision::AddButton(vector<cButton*> buttons)
{
	for (auto iter : buttons)
		m_buttons.push_back(iter);
}

void cButtonCollision::ChkCollision(Vec2 pos)
{
	if (INPUT->LButtonDown())
		lButton = true;
	else if (INPUT->LButtonUp())
		lButton = false;

	for (cButton* button : m_buttons)
	{
		button->SetImg(button->GetImg(0));
	}

	for (cButton* button : m_buttons)
	{
		if (button->ChkCollision(pos))
		{
			cTexture* img;
			if (lButton)
			{
				img = button->GetImg(2);
				if (img)
					button->SetImg(img);
			}
			else
			{
				img = button->GetImg(1);
				if (img)
					button->SetImg(img);
			}

			if (INPUT->LButtonDown())
				button->lButtonDown = true;
			else if (INPUT->LButtonUp())
			{
				if (button->lButtonDown)
					button->lButtonUp = true;
				else
				{
					button->lButtonDown = false;
					button->lButtonUp = false;
				}
			}

			if (button->lButtonDown && button->lButtonUp)
			{
				button->lButtonDown = false;
				button->lButtonUp = false;

				button->GetFunc()();
			}
		}
	}
}

void cButtonCollision::Render()
{
	for (cButton* button : m_buttons)
		RENDER->CenterRender(button->m_img, button->GetPos(), button->GetSize());
}

void cButtonCollision::Release()
{
	m_buttons.clear();
}
