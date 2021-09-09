#pragma once
class cTimer
{
public:
	/*cTimer(float time, function<void()> func, bool loop, int count) : 받아온 인자값들을 cTimer.h에서 선언한 변수들에게 할당하고
	현재 TickCount와 이전 TickCount 를 저장하는 함수
	time : 기다릴 시간, func : 실행할 내용들을 담은 클래스, loop : 반복 상태, count : 반복 횟수*/
	cTimer(double time, function<void()> func, bool loop = false, int count = 0);
	~cTimer();

	int m_count; // 입력받은 반복 횟수 저장하는 변수
	int m_count_t = 0; // 반복 횟수 구현할 변수 -> if(m_count_t <= m_count) { m_count_t ++; }
	double m_time; // 입력받은 딜레이 시간 저장하는 변수
	double m_curtime; // 딜레이 시간 구현할 변수 (계속 GetTickCount(0 값 할당)
	double m_oldtime; // 딜레이 시작할때 한번 GetTickCount() 값 할당하는 변수
	bool b_loop; // 무한반복 여부
	function<void()> func; // 실행할 문장들

	// Update() : 입력받은 time의 시간만큼 딜레이를 주는 함수
	void Update();
};