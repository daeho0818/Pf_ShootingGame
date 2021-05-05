#pragma once
#include "2. Manager/singleton.h"
class cParticleManager :
    public singleton<cParticleManager>
{
    vector<cParticle*> m_particles;
public:
    cParticleManager();
    ~cParticleManager();

    void AddParticle(Vec2 pos, float size, int kind, float frameTime = 0.005);
    void Update();
    void Render();
    void Release();
};

#define PART cParticleManager::GetInstance()