#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)
int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

// �⺻ ���ڰ� -> �׻� ���������� ������, ������ ��� ����
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0)
{

}

// ���� �����÷ο�
// ���� ���� �޸𸮰� ������ ��ġ�� ��
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