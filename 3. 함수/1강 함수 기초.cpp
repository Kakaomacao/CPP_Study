#include <iostream>
using namespace std;

// ������ ���� : �Լ�(���ν���, �޼ҵ�, ��ƾ)

/*
input���� ������ �ް�, output���� ������ ������ �����ش�.

��ȯŸ�� �Լ��̸�([����Ÿ�� �Ű�����])
{
	�Լ� ����

	return ~~~;
}
*/


// Hello World�� �ֿܼ� ����ϴ� �Լ��� ������!
// input : ���� / output : ����
// Ÿ�� : int, float, double, char, void
void PrintHelloWorld()
{
	cout << "Hello World" << endl;

	return; // ���⼭ ����

	cout << "Test" << endl; // ��� �ȵ�
}


// ������ �Է�(�Ű������� �Լ���) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������!
// input : int / output : ����
void PrintNumber(int n)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << n << "�Դϴ�." << endl;
}


// 2�� ���ϰ� ������� ��� �Լ��� ������!
// input : int / output : int
int MultiplyBy2(int n)
{
	return n * 2;
}


// �� ���ڸ� ���ؼ� ������� ��� �Լ��� ������!
// input : int, int / output : int
int MutiplyBy(int a, int b)
{
	return a * b;
}


int main()
{
	PrintHelloWorld();

	int result = MultiplyBy2(3);
	PrintNumber(result);

	int result2 = MutiplyBy(3, 5);
	PrintNumber(result2);
}