#include "DXUT.h"
#include "cTimer.h"

cTimer::cTimer(float time, function<void()> func, bool loop, int count)
	:m_time(time * 1000), func(func), b_loop(loop), m_count(count)
{
	//GetTickCount() : OS ���ú��� ������ �ð��� msec(1 / 1000��)�� ��ȯ�ϴ� �Լ�, 1�ʸ��� 1000msec�� �ö�
	m_oldtime = GetTickCount(); // m_oldtime ������ GetTickCount() �� �Ҵ�
	m_curtime = m_oldtime; // m_curtime�� m_oldtime ���� �Ҵ� (�� ���� �Ȱ���)
}

cTimer::~cTimer()
{
}

void cTimer::Update()
{
	m_curtime = GetTickCount(); // m_curtime ������ GetTickCount() �� �Ҵ�
	// ex) ���� m_oldtime�� m_curtime�� 1000msec�� �������. �׸��� �Է¹��� time�� 10, ���� m_time�� 10000�̶� �غ���.
	if (m_curtime - m_oldtime >= m_time) // 1000 - 1000 > 10000 = 0 > 10000, 1�ʿ� 1000msec�� �����Ѵ� ������ �ᱹ 10�� �ڿ� ���� ����
	{
		func(); // �Է¹��� ����� ����
		if (b_loop) // �Է¹��� loop�� ���� true���.. ������ loop�� �Է¹޴� ���� ����. �� Update() �Լ� ���ο� �־��� ����
		{
			if (m_count == 0) // �Է¹��� m_count�� ���� 0�̶��
				m_oldtime = GetTickCount(); // m_oldtime ������ GetTickCount() �� �Ҵ� -> �ݺ��ϱ� ���ؼ�
			else // �Է¹��� m_count�� ���� 0�� �ƴ϶��
			{
				if (m_count_t <= m_count) // m_count_t = 0; �Է¹��� count�� �� ��ŭ '��' �ݺ��ϱ� ���� (�⺻ �ѹ� ���� ��)
				{
					m_oldtime = GetTickCount(); // m_oldtime ������ GetTickCount() �� �Ҵ� -> �ݺ��ϱ� ���ؼ�
					m_count_t++; // m_count_t �� 1 ����
				}
				else // m_count_t, m_count �� �� 0�̶��
					delete this; // cTimer ����
			}
		}
		else // b_loop�� false���
			delete this; // cTimer ����
	}
}