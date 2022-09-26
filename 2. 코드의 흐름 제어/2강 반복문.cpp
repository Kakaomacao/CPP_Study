#include <iostream>
using namespace std;

// 오늘의 주제 : 반복문
// 데이터를 메모리에 할당하고 가공하는 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?

int main()
{
	// while for ~동안에
	// if-else 굉장히 유용하다
	// 하지만 한 번만 실행하는게 아니라, 특정 조건까지 계속 반복해야 하는 상황
	// ex) 게임을 끌때까지 계속 게임을 실행해라
	// ex) 목적지에 도달할때까지 계속 이동하라

	int count = 0;

	// while의 조건식이 참이면 안에 들어옴
	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}

	// do-while문은 적어도 한번은 do {} 실행
	// 거의 사용하지 않음
	do
	{
		cout << "Hello World" << endl;
		count++;

	} while (count < 5);

	// for문 (초기화식; 조건식; 증감식)
	for (int i = 0; i < 5; i++)
	{
		cout << "Hello World" << endl;
	}

	// 루프문의 흐름 제어
	// break; continue;
	// break는 반복문에서 빠져나가주세요 -> 해당 루프만!

	int round = 1;
	int hp = 100;
	int damage = 10;

	// 무한 루프 : 전투 시작
	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;	// 음수 체력을 0으로 보정

		// 시스템 메세지
		cout << "Round " << round << "몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// 1 ~ 10 사이의 홀수만 출력하기
	for (int count = 1; count <= 10; count++)
	{
		bool isEven = (count % 2) == 0;

		if (isEven)
			continue;
		
		cout << count << endl;
	}

}