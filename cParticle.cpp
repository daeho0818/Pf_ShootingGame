#include "DXUT.h"
#include "cParticle.h"

cParticle::cParticle(Vec2 pos, float size, int kind, float frameTime)
	:m_pos(pos), RenderSize(size) // m_pos에 입력받은 pos를 저장하고 RenderSize에 입력받은 size 저장
{
}

cParticle::~cParticle()
{
}
