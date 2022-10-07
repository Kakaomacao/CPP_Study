#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 참조

struct StatInfo
{
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

// 원본에 접근하여 데이터 수정
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
	// TODO : Heap 영역에서 뭔가를 찾아봄
	// 찾았다!
	// return monster~;

	return nullptr;
}


StatInfo globalInfo;

// 주소 전달 방식

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	if (!info)
		return;

	cout << "----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------------" << endl;

	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)을 바꿀 수 없음
	// info라는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!

	// 별 이전에 붙인다면?
	// const StatInfo* info
	// info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니 내용물을 바꿀 수 없다!

	// info[ 주소값 ]       주소값[ 데이터 ]
	// info = &globalInfo;
	// info->hp = 10000;
}

// 참조 전달 방식
// const랑 쓰는 경우가 많음
void PrintInfoByRef(const StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;

	CreateMonster(&info);

	// 포인터 vs 참조 세기의 대결
	// 성능 : 똑같음! (어셈블리 상에서 보면 완전 똑같음)
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는 것이 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있음
	// 참조는 자연스럽게 모르고 지나칠 수도 있음
	// ex) 마음대로 고친다면?
	// const를 사용해서 마음대로 고치는 부분 개선 가능

	// 참고로 포인터도 const를 사용 가능
	// * 기준으로 앞에 뒤에 붙이는 것이 의미가 다름


	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름을 붙여주는 느낌
	// -> 참조하는 대상이 없으면 안돼!!
	// 반면 초인터는 그냥 어떤 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음
	// 포인터에서 '없다'라는 의미로? nullptr
	// 참조 타입은 이런 nullptr의 개념이 없다

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(info);

	// 그래서 결론은?
	// 팀마다 개인마다 다른 수 있음
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에서는 reference도 애용

	ChangeInfo(OUT info); // 주의해서 보자는 의미로 OUT 사용


	// Bonus) 포인터로 사용하던 것을 참조로 넘겨주려면?
	// pointer[ 주소(&info) ]    info [ 데이터 ]
	PrintInfoByRef(*pointer);

	// Bonus) 참조로 사용하던 것을 포인터로 넘겨주려면?
	// pointer[ 주소(&info) ]    reference, info [ 데이터 ]
	PrintInfoByPtr(&reference);

	return 0;
}