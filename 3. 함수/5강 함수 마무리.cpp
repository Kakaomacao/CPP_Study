#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)
int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

// 기본 인자값 -> 항상 마지막으로 가야함, 갯수는 상관 없음
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0)
{

}

// 스택 오버플로우
// 스택 관련 메모리가 꽉차서 넘치는 것
int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

int main()
{
	int result = Add(1, 2);
	cout << result << endl;

	result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10);

	// 5! = 5 * 4 * 3 * 2 * 1
	cout << Factorial(5) << endl;
}