#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

class Knight
{
public:
	// 정적 함수
	static void HelloKnight()
	{

	}

	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};

// typedef의 진실
// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)
// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]에서 typedef을 앞에 붙이는 쪽

typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];
typedef int(*PFUNC)(int, int);	// 일반 함수 포인터
typedef int(Knight::*PMEMFUNC)(int, int);	// 멤버 함수 포인터

class Dog
{
public:
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return 0;
	}
};

int Test(int a, int b)
{
	cout << "Test" << endl;
	return 0;
}

int main()
{
	// 함수 포인터
	// 1) 포인터			*
	// 2) 변수의 이름	fn
	// 3) 타입			함수 (인자로 int 2개를 받고, int 1개를 반환)
	
	// int(*fn)(int, int);

	// 두 번에 나눠서도 가능함
	// typedef int(FUNC_TYPE)(int, int);
	// FUNC_TYPE* fn;

	PFUNC fn;

	fn = &Test;	// &가 생략 가능, 배열과 마찬가지로 이름이 주소 의미

	fn(1, 2);
	(*fn)(1, 2);

	// 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다 (호출 규약이 동일한 애들)
	// fn = &Knight::GetHp();

	Test(1, 2);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp; // 멤버 함수 사용시에는 무조건 & 붙여야 함!!
	(k1.*mfn)(1, 2);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}