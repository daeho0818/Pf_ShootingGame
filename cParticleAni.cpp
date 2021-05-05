#include "DXUT.h"
#include "cParticleAni.h"

cParticleAni::cParticleAni(Vec2 pos, float size, int kind, float frameTime)
	:cParticle(pos, size, kind, frameTime)
{
	FrameTime = frameTime;
	if (kind == 0) // 파티클 종류 첫번째
		m_images = IMAGE->MakeVecImg("expl_mob"); // expl_mob이라는 이름의 이미지들을 애니메이션화하여 m_images에 저장
	else if (kind == 1) // 파티클 종류 두번째
		m_images = IMAGE->MakeVecImg("expl_player"); // expl_player라는 이름의 이미지들을 애니메이션화하여 m_images에 저장
	else if (kind == 2) // 파티클 종류 세번째
		m_images = IMAGE->MakeVecImg("skill_effect");
	isDestroy = false; // isDestroy에 false 대입 (불렸을 때 초기화)
}

cParticleAni::~cParticleAni()
{
	SAFE_DELETE(m_ani); // 만들어진 파티클 애니메이션 m_ani 메모리 해제
}

void cParticleAni::Update()
{
	// cTimer::Update() : 입력한 지연시간만큼 딜레이를 주는 함수
	if (m_ani != nullptr) m_ani->Update(); // cTimer가 nullptr이 아니라면 cTimer의 Update() 실행
	if (m_bOnce) // 하나의 파티클 애니메이션을 한번만 재생하기 위함
	{
		m_ani = new cTimer(FrameTime, [&]()->void { // 0.02초의 딜레이를 갖고 다음 프레임으로
			m_frame++; // 프레임 하나 넘김
			if (m_frame == m_images.size()) // m_frame이 m_images의 갯수를 넘어섰다면
				isDestroy = true; // isDestroy에 true 대입
		}, 1); // 위 과정을 한번 더 반복
		m_bOnce = false; // 한번만 반복하기 위해 m_bOnce를 flase로 바꿔줌
	}
}

void cParticleAni::Render()
{
	// Update에서 1씩 더해주는 m_frame을 통해 m_images에 접근하고 m_pos위치에 RenderSize크기로 애니메이션 연출
	RENDER->CenterRender(m_images[m_frame], m_pos, RenderSize);
}
