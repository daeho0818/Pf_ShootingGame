#pragma once
#pragma comment(lib, "dsound.lib")

#include "SDKsound.h"
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional> //function : 함수 뿐만이 아닌 모든 Callable('()' 을 사용하여 호출할 수 있는 모든 것)을 객체의 형태로 저장할 수 있는 클래스
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <cstdarg> // DebugLog() 함수 쓰기 위함

#define g_device DXUTGetD3D9Device() // 디바이스를 실행하는 기기
#define Delta DXUTGetElapsedTime()// 이전 프레임이 완료될때까지 걸린 시간 (Unity의 Time.deltaTime)

using namespace std; // std:: 를 생략하기 위함

using Vec2 = D3DXVECTOR2; // 2D 좌표 관리
using Vec3 = D3DXVECTOR3; // 3D 좌표 관리

const int WINSIZEX = 1600; // 윈도우 가로 크기
const int WINSIZEY = 900; // 윈도우 세로 크기

#include "cTexture.h"
#include "cScene.h"
#include "cTimer.h"
#include "cParticle.h"
#include "DebugLog.h"

#include "cImageManager.h"
#include "cSceneManager.h"
#include "cUIManager.h"
#include "cRenderManager.h"
#include "cInputManager.h"
#include "cParticleManager.h"
#include "cSoundManager.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif