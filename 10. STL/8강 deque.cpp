#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// 오늘의 주제 : deque

// vector : 동적 배열
// [         ]

// list : 이중 연결 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ] <->

// deque : double-ended queue 데크
// [     ]
// [     ]
// [     ]

int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector, list, deque(데크) -> dequeue와 다른 말!!!

	// deque<int> dq;

	// dq.push_back(1);
	// dq.capacity(); // 필요할 때마다 통을 새로 만들어서 capacity 필요 X
	// dq.push_front(2);
	// cout << dq[0] << endl;

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다

	// vector
	// [        ] 꽉차면 50% 늘린 새로운 영역 생성
	// [               ] 새로운 영역에 이전 데이터 복사하고 이전 배열 삭제

	// deque
	// [    3 3] push_front했을 때
	// [1 1 1 2] 맨 처음 통
	// [2      ] 꽉차면 통을 하나 더 추가

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque의 동작 원리
	// - 중간 삽입/삭제 (BAD / BAD) -> 중간에 삭제하면 뒤에 다 한칸씩 당겨야함
	// - 처음/끝 삽입/삭제 (GOOD / GOOD) -> 통 추가 삭제로 가능함
	// - 임의 접근 (GOOD)

	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	// * 연산 방법
	// _Size_type _Block = _Mycont->_Getblock(_Myoff);	// 어떤 블록 소속인지
	// _Size_type _Off = _Myoff % _Block_size;			// 테스트에서는 _Block_size는 4였음
	// return _Mycont->_Map[_Block][_Off];				// 몇 번째 블록의 몇 번째 오프셋이군
	// 각각 동과 호수 느낌으로 데이터의 동호수가 매겨지는 느낌
	// -> 따라서 데이터가 중간에 빈 값이 있으면 안돼!! -> 그래서 중간 삽입/삭제가 어렵군

	return 0;
}