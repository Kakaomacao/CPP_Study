#include <iostream>
using namespace std;

int main()
{
	srand(time(NULL)); // 시드 설정

	// 1 2 3만 얻으면 됨 
	// rand() : 0 ~ 32767
	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	int wins = 0;
	int total = 0;

	while (true) {
		
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl << "> ";

		if (total == 0)
			cout << "현재 승률 : 없음" << endl;
		else
		{
			// 확률을 구해준다.
			double winPercentage = double(wins) / total * 100;

			cout << "현재 승률 : " << winPercentage << endl;
		}

		// 컴퓨터의 값
		int computherValue = 1 + rand() % 3; // 0 ~ 2

		// 사용자의 값
		int input;
		cin >> input;

		if (input == SCISSORS)
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

		else if (input == ROCK)
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