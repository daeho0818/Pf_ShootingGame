#include "DXUT.h"
#include "cParticleAni.h"

cParticleAni::cParticleAni(Vec2 pos, float size, int kind, float frameTime)
	:cParticle(pos, size, kind, frameTime)
{
	FrameTime = frameTime;
	if (kind == 0) // ��ƼŬ ���� ù��°
		m_images = IMAGE->MakeVecImg("expl_mob"); // expl_mob�̶�� �̸��� �̹������� �ִϸ��̼�ȭ�Ͽ� m_images�� ����
	else if (kind == 1) // ��ƼŬ ���� �ι�°
		m_images = IMAGE->MakeVecImg("expl_player"); // expl_player��� �̸��� �̹������� �ִϸ��̼�ȭ�Ͽ� m_images�� ����
	else if (kind == 2) // ��ƼŬ ���� ����°
		m_images = IMAGE->MakeVecImg("skill_effect");
	isDestroy = false; // isDestroy�� false ���� (�ҷ��� �� �ʱ�ȭ)
}

cParticleAni::~cParticleAni()
{
	SAFE_DELETE(m_ani); // ������� ��ƼŬ �ִϸ��̼� m_ani �޸� ����
}

void cParticleAni::Update()
{
	// cTimer::Update() : �Է��� �����ð���ŭ �����̸� �ִ� �Լ�
	if (m_ani != nullptr) m_ani->Update(); // cTimer�� nullptr�� �ƴ϶�� cTimer�� Update() ����
	if (m_bOnce) // �ϳ��� ��ƼŬ �ִϸ��̼��� �ѹ��� ����ϱ� ����
	{
		m_ani = new cTimer(FrameTime, [&]()->void { // 0.02���� �����̸� ���� ���� ����������
			m_frame++; // ������ �ϳ� �ѱ�
			if (m_frame == m_images.size()) // m_frame�� m_images�� ������ �Ѿ�ٸ�
				isDestroy = true; // isDestroy�� true ����
		}, 1); // �� ������ �ѹ� �� �ݺ�
		m_bOnce = false; // �ѹ��� �ݺ��ϱ� ���� m_bOnce�� flase�� �ٲ���
	}
}

void cParticleAni::Render()
{
	// Update���� 1�� �����ִ� m_frame�� ���� m_images�� �����ϰ� m_pos��ġ�� RenderSizeũ��� �ִϸ��̼� ����
	RENDER->CenterRender(m_images[m_frame], m_pos, RenderSize);
}
