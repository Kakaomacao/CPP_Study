#include <iostream>
using namespace std;

// 오늘의 주제 : 디버깅

// 중단점에 조건을 걸 수도 있음
// 중단점 마우스 우클릭 -> 조건
// 설정되면 중단점에 십자가 모양이 생김

void Test2()
{
	int b = 0;
}

void Test1()
{
	int a = 0;

	Test2();
}

int main()
{
	int number = 10;

	Test1();

	return 0;
}