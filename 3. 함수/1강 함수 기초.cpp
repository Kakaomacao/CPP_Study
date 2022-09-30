#include <iostream>
using namespace std;

// 오늘의 주제 : 함수(프로시져, 메소드, 루틴)

/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

반환타입 함수이름([인자타입 매개변수])
{
	함수 내용

	return ~~~;
}
*/


// Hello World를 콘솔에 출력하는 함수를 만들어보자!
// input : 없음 / output : 없음
// 타입 : int, float, double, char, void
void PrintHelloWorld()
{
	cout << "Hello World" << endl;

	return; // 여기서 끝남

	cout << "Test" << endl; // 출력 안됨
}


// 정수를 입력(매개변수로 함수가) 받아서, 콘솔에 출력하는 함수를 만들어보자!
// input : int / output : 없음
void PrintNumber(int n)
{
	cout << "넘겨주신 숫자는 " << n << "입니다." << endl;
}


// 2를 곱하고 결과물을 뱉는 함수를 만들어보자!
// input : int / output : int
int MultiplyBy2(int n)
{
	return n * 2;
}


// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자!
// input : int, int / output : int
int MutiplyBy(int a, int b)
{
	return a * b;
}


int main()
{
	PrintHelloWorld();

	int result = MultiplyBy2(3);
	PrintNumber(result);

	int result2 = MutiplyBy(3, 5);
	PrintNumber(result2);
}