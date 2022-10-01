#include <iostream>
using namespace std;

// 오늘의 주제 : 지역 변수와 값 전달
// Call by Value

// 전역 변수 -> 데이터 영역
// 참고) 초기화 여부, const 등 .rodata .data .bss
int globalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;
}

void IncreasHp(int hp) // 메인 함수의 주소가 아닌 그냥 값만 가져옴
{
	hp = hp + 1;
}

// 스택 영역
// [매개변수][RET][지역변수] [매개변수][RET][지역변수]
int main()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;

	Test();

	// 지역 변수
	int localValue = 1;

	int hp = 1;

	cout << "Increase 호출 전 : " << hp << endl; // 결과 1
	IncreasHp(hp); // IncreaseHp(1);과 동일
	cout << "Increase 호출 후 : " << hp << endl; // 결과 1
}