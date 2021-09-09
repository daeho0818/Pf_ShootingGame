#pragma once
class cParticle
{
public:
	// �Է¹��� ��ǥ pos�� ũ�� size, ���� kind�� �����ϴ� ������
	cParticle(Vec2 pos, float size, float frameTime);
	virtual ~cParticle();

	// Update() : ��� ����Ǵ� �Լ� -> cParticleAni�� Update() �Լ� ���� (��ü�� �ٲ�� �͵�)
	virtual void Update() = 0;
	// Render() : ��� ����Ǵ� �Լ� -> cParticleAni�� Render() �Լ� ���� (�̹��� ���� �� ��ü�� �ٲ��� �ʴ� �͵�)
	virtual void Render() = 0;

	bool isDestroy = false; // ��ƼŬ ���� ����

protected:
	Vec2 m_pos; // �Է¹��� pos�� �����ϴ� ����, ��ƼŬ ���� ��ǥ
	float RenderSize; // �Է¹��� size�� �����ϴ� ����, ��ƼŬ ũ��
	float m_frameTime;
};

