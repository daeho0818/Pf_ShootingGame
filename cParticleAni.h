#pragma once
#include "cParticle.h"
class cParticleAni
    :public cParticle
{
public:
    //cParticleAni(Vec2 pos, float size, int kind) : m_images에 파티클을 애니메이션화하여 저장하는 생성자
    cParticleAni(Vec2 pos, float size, int kind, float frametime);
    // 만들어진 파티클 m_ani를 메모리 해제하는 소멸자
    ~cParticleAni();

    // Update() : m_frame 변수를 통해 m_images의 요소 하나하나를 접근하여 애니메이션화할 수 있도록 하는 함수
    virtual void Update() override;
    // Redner() : 화면에 파티클 애니메이션을 띄우는 함수
    virtual void Render() override;

private:
    vector<cTexture*> m_images; // 이미지들을 담는 벡터
    cTimer* m_ani = nullptr; // 애니메이션 프레임 한 컷마다 딜레이를 주기 위한 cTimer형 변수
    int m_frame = 0; // 애니메이션 프레임
    bool m_bOnce = true; // 반복문을 한번만 돌기 위한 bool 변수
};