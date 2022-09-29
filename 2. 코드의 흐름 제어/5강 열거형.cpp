#include <iostream>
using namespace std;

// 상수인건 알겠는데, 너무 따로 노는 느낌?
// 하나의 셋트인데?
// const int는 경우에 따라서 컴파일러가 최적화하는 법이 다를 수 있음
// 메모리를 잡을 가능성이 있음
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;


// 숫자를 지정하지 않으면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
// 컴파일 단계에서 완벽하게 바꿔치기됨 -> 메모리 측면에서 조금 더 유리
enum ENUM_SRP // Scissors, Rock, Paper
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};


// #이 붙은 문장 -> 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 1) 전처리 2) 컴파일 3) 링크
// #define보다 위 경우들을 쓰는게 더 좋은 선택
// -> 복사하는 것이기 때문에 트릭 존재 (우선 순위에 따라 다른 값 가능성)
// -> 중단점 이용할 때도 트레이스가 어려울 수 있음
#define DEFINE_SCISSORS 1
#define DEFINE_ROCK 2
#define DEFINE_PAPER 3
#define DEFINE_TEST cout << "Hello World" << endl;


int main()
{
	DEFINE_TEST;

	srand(time(NULL)); 

	int wins = 0;
	int total = 0;

	while (true) {

		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl << "> ";

		if (total == 0)
			cout << "현재 승률 : 없음" << endl;
		else
		{
			double winPercentage = double(wins) / total * 100;

			cout << "현재 승률 : " << winPercentage << endl;
		}

		int computherValue = 1 + rand() % 3;

		int input;
		cin >> input;

		if (input == ENUM_SCISSORS)
		{
			switch (computherValue)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			}
		}

		else if (input == DEFINE_ROCK)
		{
			switch (computherValue)
			{
			case SCISSORS:
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			}
		}

		else if (input == PAPER)
		{
			switch (computherValue)
			{
			case SCISSORS:
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case ROCK:
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
		else
			break;
	}
}