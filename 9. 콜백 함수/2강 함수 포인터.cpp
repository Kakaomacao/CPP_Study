#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

class Knight
{
public:
	// ���� �Լ�
	static void HelloKnight()
	{

	}

	// ��� �Լ�
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};

// typedef�� ����
// typedef ���� ������ -> ������ (Ŀ���� Ÿ�� ����)
// ��Ȯ���� ����/������ ������ �ƴ϶�,
// [���� ����]���� typedef�� �տ� ���̴� ��

typedef int INTEGER;
typedef int* POINTER;
typedef int ARRAY[20];
typedef int(*PFUNC)(int, int);	// �Ϲ� �Լ� ������
typedef int(Knight::*PMEMFUNC)(int, int);	// ��� �Լ� ������

class Dog
{
public:
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return 0;
	}
};

int Test(int a, int b)
{
	cout << "Test" << endl;
	return 0;
}

int main()
{
	// �Լ� ������
	// 1) ������			*
	// 2) ������ �̸�	fn
	// 3) Ÿ��			�Լ� (���ڷ� int 2���� �ް�, int 1���� ��ȯ)
	
	// int(*fn)(int, int);

	// �� ���� �������� ������
	// typedef int(FUNC_TYPE)(int, int);
	// FUNC_TYPE* fn;

	PFUNC fn;

	fn = &Test;	// &�� ���� ����, �迭�� ���������� �̸��� �ּ� �ǹ�

	fn(1, 2);
	(*fn)(1, 2);

	// �� �������� [���� �Լ� / ���� �Լ�]�� ���� �� �ִ� (ȣ�� �Ծ��� ������ �ֵ�)
	// fn = &Knight::GetHp();

	Test(1, 2);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp; // ��� �Լ� ���ÿ��� ������ & �ٿ��� ��!!
	(k1.*mfn)(1, 2);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}