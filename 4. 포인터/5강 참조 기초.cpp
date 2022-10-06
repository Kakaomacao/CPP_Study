#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

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

// 매개변수로 포인터로 받는거랑 완전 다름
// 원본이 아니라 복사된 매개변수를 바꿈
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;

}

// 2) 주소 전달 방식

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------------" << endl;

}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사
// - (주소 전달) StatInfo*은 8바이트
// - (참조 전달) StatInfo&은 8바이트

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용하여 진짜를 건드리는!
// 일석이조의 방식!!

void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;
}

int main()
{
	// 4바이트 정수형 바구니를 사용할거야
	// 앞으로 그 바구니 이름을 number라고 할게
	// 그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면
	// 컴파일러가 알아서 알아듣고 해당 주소(data, stack, heap)에 1을 넣어주면 된다!
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터가 있음
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다.
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 
	int& reference = number;
	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것
	// number라는 바구니에 reference라는 다른 이름을 지어줄게!
	// 앞으로 reference 바구니에 뭘 넣거나 꺼내면
	// 실제 number 바구니에다가 그 값을 넣거나 꺼내면 됨!!
	reference = 3;

	// 작동 방식이 포인터랑 같은데 왜 귀찮게 또 다른 이름을 짓는 이유는??
	// 그냥 number = 3이라고 해도 똑같은데...
	// 두 방법의 섞인 방법이니까!!

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}