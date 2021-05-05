#pragma once
class cParticle
{
public:
	// �Է¹��� ��ǥ pos�� ũ�� size, ���� kind�� �����ϴ� ������
	cParticle(Vec2 pos, float size, int kind, float frameTime = 0.005);
	virtual ~cParticle();

	// Update() : ��� ����Ǵ� �Լ� -> cParticleAni�� Update() �Լ� ���� (��ü�� �ٲ�� �͵�)
	virtual void Update() = 0;
	// Render() : ��� ����Ǵ� �Լ� -> cParticleAni�� Render() �Լ� ���� (�̹��� ���� �� ��ü�� �ٲ��� �ʴ� �͵�)
	virtual void Render() = 0;

	Vec2 m_pos; // �Է¹��� pos�� �����ϴ� ����, ��ƼŬ ���� ��ǥ
	float RenderSize; // �Է¹��� size�� �����ϴ� ����, ��ƼŬ ũ��
	bool isDestroy = false; // ��ƼŬ ���� ����
};

