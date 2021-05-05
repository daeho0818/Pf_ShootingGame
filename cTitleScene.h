#pragma once
#include "cScene.h"
class cTitleScene
	: public cScene
{
public:
	cTitleScene();
	~cTitleScene();

	int select;
	bool bGameStart = true;
	bool bExit = false;

	//cScene�� ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};