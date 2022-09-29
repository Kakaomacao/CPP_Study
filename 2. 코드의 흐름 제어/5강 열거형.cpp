#include <iostream>
using namespace std;

// ����ΰ� �˰ڴµ�, �ʹ� ���� ��� ����?
// �ϳ��� ��Ʈ�ε�?
// const int�� ��쿡 ���� �����Ϸ��� ����ȭ�ϴ� ���� �ٸ� �� ����
// �޸𸮸� ���� ���ɼ��� ����
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;


// ���ڸ� �������� ������ ù ���� 0���� ����
// �� ���� ������ ���� �� + 1
// ������ �ܰ迡�� �Ϻ��ϰ� �ٲ�ġ��� -> �޸� ���鿡�� ���� �� ����
enum ENUM_SRP // Scissors, Rock, Paper
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};


// #�� ���� ���� -> ��ó�� ���ù�
// #include <iostream>�̶�� ������ ã�Ƽ� �ش� ������ �׳� ����!
// 1) ��ó�� 2) ������ 3) ��ũ
// #define���� �� ������ ���°� �� ���� ����
// -> �����ϴ� ���̱� ������ Ʈ�� ���� (�켱 ������ ���� �ٸ� �� ���ɼ�)
// -> �ߴ��� �̿��� ���� Ʈ���̽��� ����� �� ����
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

		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl << "> ";

		if (total == 0)
			cout << "���� �·� : ����" << endl;
		else
		{
			double winPercentage = double(wins) / total * 100;

			cout << "���� �·� : " << winPercentage << endl;
		}

		int computherValue = 1 + rand() % 3;

		int input;
		cin >> input;

		if (input == ENUM_SCISSORS)
		{
			switch (computherValue)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
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
				cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			}
		}

		else if (input == PAPER)
		{
			switch (computherValue)
			{
			case SCISSORS:
				cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case ROCK:
				cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				break;
			}
		}
		else
			break;
	}
}