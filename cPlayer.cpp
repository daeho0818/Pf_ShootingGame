#include "DXUT.h"
#include "cPlayer.h"
#include "cPBullet.h"
#include "cMobAdmin.h"

cPlayer::cPlayer(vector<cBullet*>& bullet)
	:m_pos(WINSIZEX / 2, 900), m_bullet(bullet)
{
	m_Hp = SCENE->m_Hp;
	Heal();
}

cPlayer::~cPlayer()
{
	SAFE_DELETE(playerAS);
	SCENE->m_Hp = m_Hp;
}

void cPlayer::Update()
{
	if (playerAS) playerAS->Update();

	if (saveHeal) if (INPUT->KeyDown(VK_SHIFT)) { Heal(); saveHeal = false; }

	if (INPUT->KeyDown(VK_F1)) m_Hp = 9999;

	if (skillPoint >= 12) playerSkill = true;

	Move();
	FireBullet();
	ItemUpdate();
}

void cPlayer::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("player"), m_pos, 0.5);
}

void cPlayer::UIRender()
{
	if (saveHeal) UI->CenterRender(IMAGE->FindImage("Hp+"), Vec2(40, 780));
	RECT hprc = {
		0,
		0,
		((float)IMAGE->FindImage("Hp")->info.Width / 100 + 50) * m_Hp,
		IMAGE->FindImage("Hp")->info.Height / 2
	};
	UI->CropRender(IMAGE->FindImage("Hp"), Vec2(50, 860), hprc);
	UI->PrintText("HP", Vec2(135, 835), 0.1);
	RECT sprc = {
		0,
		0,
		((float)IMAGE->FindImage("SkillPoint")->info.Width / 100 + 50) * skillPoint / 2,
		IMAGE->FindImage("SkillPoint")->info.Height / 2
	};
	UI->CropRender(IMAGE->FindImage("SkillPoint"), Vec2(50, 900), sprc);
}

void cPlayer::Move()
{
	if (INPUT->KeyPress(VK_UP) && m_pos.y >= 0) { m_pos.y -= 600 * Delta; }
	if (INPUT->KeyPress(VK_DOWN) && m_pos.y <= WINSIZEY) { m_pos.y += 600 * Delta; }
	if (INPUT->KeyPress(VK_LEFT) && m_pos.x >= 0) { m_pos.x -= 600 * Delta; }
	if (INPUT->KeyPress(VK_RIGHT) && m_pos.x <= WINSIZEX) { m_pos.x += 600 * Delta; }
}

void cPlayer::FireBullet()
{
	if (INPUT->KeyPress(90) && b_fire)
	{
		Vec2 Dir;
		if (SCENE->multiDir)
		{
			for (int i = -1; i < 2; i++)
			{
				Dir = { float(i * 0.2f), 1 };
				D3DXVec2Normalize(&Dir, &Dir);
				SOUND->Play("gun_fire");
				m_bullet.push_back(new cPBullet(m_pos, Dir));
			}
			b_fire = false;
		}
		else
		{
			SOUND->Play("gun_fire");
			m_bullet.push_back(new cPBullet(m_pos));
			b_fire = false;
		}
		playerAS = new cTimer(0.1, [&]()->void {b_fire = true; playerAS = nullptr; });
	}
}

void cPlayer::ItemUpdate()
{
	if (ItemName == "Heal")
	{
		Heal();
	}
}

void cPlayer::Heal()
{
	if (m_Hp >= 6) saveHeal = true;

	else if (m_Hp >= 4) m_Hp = 6;
	else m_Hp += 2;

	SOUND->Play("heal");
	ItemName = "none";
}