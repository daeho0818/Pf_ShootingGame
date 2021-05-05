#pragma once
#include "cScene.h"
class cEndingScene
	:public cScene
{
public:
	cEndingScene();
	~cEndingScene();

	bool bTitle = true;
	bool bExit = false;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};