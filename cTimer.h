#pragma once
class cTimer
{
public:
	/*cTimer(float time, function<void()> func, bool loop, int count) : �޾ƿ� ���ڰ����� cTimer.h���� ������ �����鿡�� �Ҵ��ϰ�
	���� TickCount�� ���� TickCount �� �����ϴ� �Լ�
	time : ��ٸ� �ð�, func : ������ ������� ���� Ŭ����, loop : �ݺ� ����, count : �ݺ� Ƚ��*/
	cTimer(double time, function<void()> func, bool loop = false, int count = 0);
	~cTimer();

	int m_count; // �Է¹��� �ݺ� Ƚ�� �����ϴ� ����
	int m_count_t = 0; // �ݺ� Ƚ�� ������ ���� -> if(m_count_t <= m_count) { m_count_t ++; }
	double m_time; // �Է¹��� ������ �ð� �����ϴ� ����
	double m_curtime; // ������ �ð� ������ ���� (��� GetTickCount(0 �� �Ҵ�)
	double m_oldtime; // ������ �����Ҷ� �ѹ� GetTickCount() �� �Ҵ��ϴ� ����
	bool b_loop; // ���ѹݺ� ����
	function<void()> func; // ������ �����

	// Update() : �Է¹��� time�� �ð���ŭ �����̸� �ִ� �Լ�
	void Update();
};