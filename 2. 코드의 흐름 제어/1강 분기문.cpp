#include <iostream>
using namespace std;

// ������ ���� : �б⹮
// �����͸� �޸𸮿� �Ҵ��ϰ� �����ϰ� ����� ���� �˾ƺ�
// ������ �����͸� �̿��ؼ� �����ΰ��� �ϰ� �ʹٸ�?

int main()
{
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	if (input == ROCK)
		cout << "������ �����ϴ�." << endl;
	else if (input == PAPER)
		cout << "���� �����ϴ�." << endl;
	else if (input == SCISSORS)
		cout << "������ �����ϴ�." << endl;
	else
		cout << "�� ���̴ϱ�?" << endl;
	
	// switch - case - break
	// ������󿡼� ���� ���̴� ���� ����
	// �������� ���̸� �ִٰ� ���� ������

	// ���� �迭�� ���� �� �ִ�. (float double �Ұ�)
	switch (input)
	{
	case ROCK:
		cout << "������ �����ϴ�." << endl;
		break;
	case PAPER:
		cout << "���� �����ϴ�." << endl;
		break;
	case SCISSORS:
		cout << "������ �����ϴ�." << endl;
		break;
	default:
		cout << "�� ���̴ϱ�?" << endl;
		break;
	}

}