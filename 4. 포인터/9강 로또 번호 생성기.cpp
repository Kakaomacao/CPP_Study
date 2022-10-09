#include <iostream>
using namespace std;

// ������ ���� : �ζ� ��ȣ ������

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
// { 1, 42, 3, 15, 5, 6 } => { 1, 3, 5, 6, 15, 42 }
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i��° ���� ���� ���� �ĺ���� ����
		int best = i;

		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã�Ƴ�����
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[best] > numbers[j])
			{
				best = j;
			}
		}

		// ���� ���� �ĺ��� ��ü�ϴ� ����
		if (i != best)
		{
			Swap(numbers[i], numbers[best]);
		}
	}
}

void ChooseLotto(int numbers[])
{
	srand(time(NULL));

	int count = 0;
	while (count != 6)
	{
		int randValue = rand() % 45 + 1;

		// �̹� ã�� ������?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			// �̹� ã�� ��
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// �� ã������ �߰�!
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}
	// TODO : �������� 1 ~ 45 ������ ���� 6���� ����ּ���! (��, �ߺ��� ����� ��)
	Sort(numbers, 6);
}

int main()
{
	// 1) Swap �Լ� �����
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, 6); // sizeof(numbers) / sizeof(int)
	// { 1, 3, 5, 6, 15, 42 }

	// 3) �ζ� ��ȣ ������
	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}