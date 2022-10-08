#include <iostream>
using namespace std;

// 오늘의 주제 : 배열 

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};


int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VS 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음
	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작한다
	// StatInfo players[10];
	// players = monsters; 불가

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	// 주소[ (100, 10, 1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_0[ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈! 진짜 1을 더하라는게 아니라 StatInfo 타입 바구니 한개씩 이동하라는 의미
	// StatInfo[ ] 주소[ (200, 20, 2) ] StatInfo[ ] StatInfo[ ] ...
	// monster_1[ 주소 ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다.
	// StatInfo[ ] StatInfo[ ] moster_2, 주소[ ] StatInfo[ ] ...
	// monster_2[ 주소 ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 완전 다른 의미이다
	// StatInfo[ ] StatInfo[ ] 주소[ 내용물 ] StatInfo[ ] ...
	// temp[   내용물   ]  그냥 복사해오는거임 -> monster_2의 값이 바뀌는게 아님
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 이를 조금 더 자동화한다!
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = (i + 1) * 100;
		monster.attack = (i + 1) * 10;
		monster.defence = (i + 1);
	}

	// 근데 *(monsters + i) 너무 불편하고 가독성이 떨어진다... 더 편한 방법?
	// 인덱스!
	// 배열은 0번부터 시작. N번째 인덱스에 접근하려면 배열이름[N]
	// *(monsters + i) = monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monsters[i].hp = (i + 1) * 100;
		monsters[i].attack = (i + 1) * 10;
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {}; // 다 0으로 밀어버린다.
	int numbers1[10] = { 1, 2, 3, 4, 5 }; // 초기화 안한 부분은 다 0
	int numbers2[] = { 1, 2, 3, 4, 11, 24, 124, 14, 1 }; // 데이터 개수만큼 크기의 배열 형성
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << helloStr << endl;

	// 배열 요약 :
	// 1) 선언한다
	int arr[10] = { };

	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	cout << arr[1] << endl;

	return 0;
}