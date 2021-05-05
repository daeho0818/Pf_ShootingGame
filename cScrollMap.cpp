#include "DXUT.h"
#include "cScrollMap.h"

cScrollMap::cScrollMap()
{
}

cScrollMap::~cScrollMap()
{
}

void cScrollMap::Update(float speed)
{
	scroll_f += speed * Delta;
	scroll_m += (speed + 150) * Delta;
	scroll_p += (speed + 300) * Delta;
}

void cScrollMap::Render()
{
	if (SCENE->mobCount < 25)
		key = "stage_1_BG";
	else if (SCENE->mobCount < 50)
		key = "stage_2_BG";
	else
		key = "stage_3_BG";
	float renderPos_f = (int)scroll_f % IMAGE->FindImage(key)->info.Height;
	RENDER->CenterRender(IMAGE->FindImage(key), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f - IMAGE->FindImage("stage_1_BG")->info.Height));
	RENDER->CenterRender(IMAGE->FindImage(key), Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos_f));
}