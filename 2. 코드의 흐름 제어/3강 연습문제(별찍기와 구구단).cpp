#include <iostream>
using namespace std;

int main()
{
	// �����
	// �������� � ������ �Է��ϸ�
	// n * n ���� ���� ������� ���ھ��!

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// ����� (2)
	// ��,, �׳� n * n ���� ���� �����ϱ� �ʹ� �ɽ��ϴ�.
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� ���ּ���!

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// ����� (3)
	// ����� ���� �����Ǳ� �ߴµ�
	// n������ �����ؼ� �ٸ��� 1���� �پ��� ���·�!

	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}


	// ������
	// 2 * 1 = 2
	// 2�ܺ��� 9�ܱ��� �������� ������ּ���

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}