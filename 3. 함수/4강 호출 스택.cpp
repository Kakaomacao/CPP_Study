#include <iostream>
using namespace std;

// ������ ���� : ȣ�� ����

// �Լ� ����
void Func1();
void Func2(int a, int b);
void Func3(float a);

// ���� �Լ� ���� ���� Func1 Func2 Func3 ������ ������ ���� �߻�
void Func1()
{
	cout << "Func 1" << endl;

	// push 2
	// push 1
	// call Func2 -> �� Func2�� ��ġ�� �˸��
	Func2(1, 2);

	Func3(10.0f);
}

void Func2(int a, int b)
{
	cout << "Func 2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "Func 3" << endl;
}

// ����׽� ȣ�� ���� Ȯ�� ����
int main()
{
	cout << "main" << endl;
	Func1();
}