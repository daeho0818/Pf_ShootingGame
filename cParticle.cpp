#include "DXUT.h"
#include "cParticle.h"

cParticle::cParticle(Vec2 pos, float size, int kind, float frameTime)
	:m_pos(pos), RenderSize(size) // m_pos�� �Է¹��� pos�� �����ϰ� RenderSize�� �Է¹��� size ����
{
}

cParticle::~cParticle()
{
}
