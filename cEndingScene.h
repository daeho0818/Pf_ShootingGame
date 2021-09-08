#pragma once
#include "cScene.h"
#include "cCollision.h"
class cEndingScene
	:public cScene
{
public:
	cEndingScene();
	~cEndingScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;

private:
	cButtonCollision* bcoll;

	cButton* lobbyButton;
	cButton* quitButton;

	Vec2 downPos;

};