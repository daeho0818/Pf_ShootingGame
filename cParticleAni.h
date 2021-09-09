#pragma once
#include "cParticle.h"
class cParticleAni
    :public cParticle
{
public:
    //cParticleAni(Vec2 pos, float size, int kind) : m_images�� ��ƼŬ�� �ִϸ��̼�ȭ�Ͽ� �����ϴ� ������
    cParticleAni(Vec2 pos, float size, int kind, float frametime);
    // ������� ��ƼŬ m_ani�� �޸� �����ϴ� �Ҹ���
    ~cParticleAni();

    // Update() : m_frame ������ ���� m_images�� ��� �ϳ��ϳ��� �����Ͽ� �ִϸ��̼�ȭ�� �� �ֵ��� �ϴ� �Լ�
    virtual void Update() override;
    // Redner() : ȭ�鿡 ��ƼŬ �ִϸ��̼��� ���� �Լ�
    virtual void Render() override;

private:
    vector<cTexture*> m_images; // �̹������� ��� ����
    cTimer* m_ani = nullptr; // �ִϸ��̼� ������ �� �Ƹ��� �����̸� �ֱ� ���� cTimer�� ����
    int m_frame = 0; // �ִϸ��̼� ������
    bool m_bOnce = true; // �ݺ����� �ѹ��� ���� ���� bool ����
};