#include <iostream>
using namespace std;

// 오늘의 주제 : 동적 할당

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global) / 정적(static) 변수 -> 데이터 영역
// - 지역 변수 / 매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역

// 지금까지 데이터 영역 / 스택 영역 이용해서
// 이런 저런 프로그램을 잘 만들어 왔다!
// 굳이 새로운 영역이 필요할까?

// 실제 상황)
// - MMORPG 동접 1명~5만명, 몬스터 1마리~500만마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개 변수 넘긴다거나, 하는 용도로는 OK
// - 메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는 영역

// 희망사항)
// - 필요할 때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 없나?~~ -> HEAP
// 동적 할당과 연관된 함수/연산자 : malloc, free, new, delete, new[], delete[]

class Monster
{
public:
	int _hp;
	int _x;
	int _y;
};

//Monster monster[500 * 10000];

int main()
{
	// 유저 영역 [메모장] [LOL] [곰플레이어]
	// -----------------------------------
	// 커널 영역 (Windows 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리 할당해서 건네줌
	// 유저 영역) 감사합니다! 잘쓸게요~

	// [                                                           ]
	// C++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수 있음 (MMORPG 서버 메모리 풀링)



	return 0;
}