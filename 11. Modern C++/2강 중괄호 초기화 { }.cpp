#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// ������ ���� : �߰�ȣ �ʱ�ȭ { }

class Knight
{
public:
	Knight()
	{

	}

	Knight(int a, int b)
	{
		cout << "Knigt(int, int)" << endl;
	}

	Knight(initializer_list<int> li)
	{
		cout << "Knight(initializer_list)" << endl;
	}

};

int main()
{
	// �߰�ȣ �ʱ�ȭ { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1; // ���� ������ (���� ������ X)

	Knight k3;	// �⺻ ������
	k3 = k1;	// ���� ������

	Knight k4{ k2 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);
	int arr[] = { 1, 2, 3, 4 };

	// �߰�ȣ �ʱ�ȭ
	// 1) vector �� container�� �� ��︰��
	vector<int> v3{ 1, 2, 3, 4 };	// 1, 2, 3, 4 push_back�� �Ͱ� ������

	// 2) ��� ��ȯ ����
	int x = 0;
	// double y{ x };

	// 3) Bonus
	Knight k5(); // �⺻ ������ ȣ���� �ƴ�! �Լ� ����� ����!
	Knight k6{ };

	// ����
	Knight k7{ 1, 2 }; // initializer_list(��) vs int, int


	// ��ȣ �ʱ�ȭ ()�� �⺻���� ����
	// - �������� C++ (�źΰ��� ����)
	// - vector �� Ư���� ���̽��� ���ؼ��� { } ���

	// �߰�ȣ �ʱ�ȭ {}�� �⺻���� ����
	// - �ʱ�ȭ ������ ��ġȭ
	// - ��� ��ȯ ����

	return 0;
}