#include "DXUT.h"
#include "cTimer.h"

cTimer::cTimer(float time, function<void()> func, bool loop, int count)
	:m_time(time * 1000), func(func), b_loop(loop), m_count(count)
{
	//GetTickCount() : OS 부팅부터 지나간 시간을 msec(1 / 1000초)로 반환하는 함수, 1초마다 1000msec씩 올라감
	m_oldtime = GetTickCount(); // m_oldtime 변수에 GetTickCount() 값 할당
	m_curtime = m_oldtime; // m_curtime에 m_oldtime 값을 할당 (두 값은 똑같음)
}

cTimer::~cTimer()
{
}

void cTimer::Update()
{
	m_curtime = GetTickCount(); // m_curtime 변수에 GetTickCount() 값 할당
	// ex) 현재 m_oldtime와 m_curtime엔 1000msec이 들어있음. 그리고 입력받은 time은 10, 따라서 m_time은 10000이라 해보자.
	if (m_curtime - m_oldtime >= m_time) // 1000 - 1000 > 10000 = 0 > 10000, 1초에 1000msec씩 증가한다 했으니 결국 10초 뒤에 조건 성립
	{
		func(); // 입력받은 문장들 실행
		if (b_loop) // 입력받은 loop의 값이 true라면.. 하지만 loop를 입력받는 곳은 없다. 다 Update() 함수 내부에 있었기 때문
		{
			if (m_count == 0) // 입력받은 m_count의 값이 0이라면
				m_oldtime = GetTickCount(); // m_oldtime 변수에 GetTickCount() 값 할당 -> 반복하기 위해서
			else // 입력받은 m_count의 값이 0이 아니라면
			{
				if (m_count_t <= m_count) // m_count_t = 0; 입력받은 count의 값 만큼 '더' 반복하기 위함 (기본 한번 실행 후)
				{
					m_oldtime = GetTickCount(); // m_oldtime 변수에 GetTickCount() 값 할당 -> 반복하기 위해서
					m_count_t++; // m_count_t 값 1 증가
				}
				else // m_count_t, m_count 둘 다 0이라면
					delete this; // cTimer 제거
			}
		}
		else // b_loop가 false라면
			delete this; // cTimer 제거
	}
}