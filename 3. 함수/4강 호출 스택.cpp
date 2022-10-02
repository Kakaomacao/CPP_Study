#include <iostream>
using namespace std;

// 오늘의 주제 : 호출 스택

// 함수 선언
void Func1();
void Func2(int a, int b);
void Func3(float a);

// 만약 함수 선언 없이 Func1 Func2 Func3 순으로 구현시 오류 발생
void Func1()
{
	cout << "Func 1" << endl;

	// push 2
	// push 1
	// call Func2 -> 즉 Func2의 위치만 알면됨
	Func2(1, 2);

	Func3(10.0f);
}

void Func2(int a, int b)
{
	cout << "Func 2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "Func 3" << endl;
}

// 디버그시 호출 스택 확인 가능
int main()
{
	cout << "main" << endl;
	Func1();
}