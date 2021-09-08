#include "DXUT.h"
#include "cTitleScene.h"

cTitleScene::cTitleScene()
{
}

cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	SCENE->PlayerInit();
	SCENE->mobCount = 0;

	SOUND->StopAll();
	SOUND->Play("b", true);

	cloud_oper_value[0] = mountains_oper_value[0] = WINSIZEX / 2;
	cloud_oper_value[1] = mountains_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;

	playerPos = { WINSIZEX + 50, WINSIZEY / 2 };

	bcoll = new cButtonCollision();
	startButton =
		new cButton(IMAGE->FindImage("StartButton"), Vec2(WINSIZEX / 2 - 300, 700), 2, [&]()->void {SCENE->ChangeScene("cIngameScene"); });
	startButton->InitImgs(IMAGE->FindImage("StartButton"), IMAGE->FindImage("StartButtonHighlight"), IMAGE->FindImage("StartButtonPressed"));
	bcoll->AddButton(startButton);

	quitButton =
		new cButton(IMAGE->FindImage("QuitButton"), Vec2(WINSIZEX / 2 + 300, 700), 2, [&]()->void {exit(0); });
	quitButton->InitImgs(IMAGE->FindImage("QuitButton"), IMAGE->FindImage("QuitButtonHighlight"), IMAGE->FindImage("QuitButtonPressed"));
	bcoll->AddButton(quitButton);
}

void cTitleScene::Update()
{
	playerPos = *D3DXVec2Lerp(&playerPos, &playerPos, &Vec2(WINSIZEX / 2, WINSIZEY / 2), Delta * 2);

	if (moon_oper_value > 90) isMoonUp = false;
	else if (moon_oper_value < -90) isMoonUp = true;

	if (!isMoonUp)
		moon_oper_value--;
	else
		moon_oper_value++;

	cloud_oper_value[0] += 10;
	cloud_oper_value[1] += 10;

	mountains_oper_value[0] ++;
	mountains_oper_value[1] ++;

	if (cloud_oper_value[0] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Cloud")->info.Width / 2))
		cloud_oper_value[0] = (WINSIZEX / 2) - WINSIZEX;
	if (cloud_oper_value[1] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Cloud")->info.Width / 2))
		cloud_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;

	if (mountains_oper_value[0] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Mountains")->info.Width / 2))
		mountains_oper_value[0] = (WINSIZEX / 2) - WINSIZEX;
	if (mountains_oper_value[1] > (int)(WINSIZEX + IMAGE->FindImage("Title_BG_Mountains")->info.Width / 2))
		mountains_oper_value[1] = (WINSIZEX / 2) - WINSIZEX;

	bcoll->ChkCollision(INPUT->GetMousePos());
}

void cTitleScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Title_BG"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(mountains_oper_value[0], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Mountains"), Vec2(mountains_oper_value[1], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Moon"), Vec2(WINSIZEX / 4, sin(moon_oper_value * D3DX_PI / 180) * 50));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[0], WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[0] * 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("Title_BG_Cloud"), Vec2(cloud_oper_value[1], WINSIZEY / 2));

	RENDER->CenterRender(IMAGE->FindImage("player"), playerPos, 0.5f, 90 * D3DX_PI / 180);

	bcoll->Render();

	RENDER->CenterRender(IMAGE->FindImage("GameName"), Vec2(WINSIZEX / 2, 300));
}

void cTitleScene::UIRender()
{
}

void cTitleScene::Release()
{
    SAFE_DELETE(bcoll);
}