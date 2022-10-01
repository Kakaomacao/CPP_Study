#include <iostream>
using namespace std;

// ������ ���� : ���� ������ �� ����
// Call by Value

// ���� ���� -> ������ ����
// ����) �ʱ�ȭ ����, const �� .rodata .data .bss
int globalValue = 0;

void Test()
{
	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;
}

void IncreasHp(int hp) // ���� �Լ��� �ּҰ� �ƴ� �׳� ���� ������
{
	hp = hp + 1;
}

// ���� ����
// [�Ű�����][RET][��������] [�Ű�����][RET][��������]
int main()
{
	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;

	Test();

	// ���� ����
	int localValue = 1;

	int hp = 1;

	cout << "Increase ȣ�� �� : " << hp << endl; // ��� 1
	IncreasHp(hp); // IncreaseHp(1);�� ����
	cout << "Increase ȣ�� �� : " << hp << endl; // ��� 1
}