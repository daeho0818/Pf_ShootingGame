#pragma once
#include "cButton.h"
class cButtonCollision
{
public:
	cButtonCollision();
	~cButtonCollision();

	void AddButton(cButton* button);
	void AddButton(vector<cButton*> buttons);

	void ChkCollision(Vec2 pos);

	void Render();
	void Release();

private:
	vector<cButton*> m_buttons;

	bool lButton;
};

