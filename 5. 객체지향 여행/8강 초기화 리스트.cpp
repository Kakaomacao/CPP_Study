#include <iostream>
using namespace std;

// ������ ���� : �ʱ�ȭ ����Ʈ

// ��� ���� �ʱ�ȭ ? �پ��� ������ ����

// �ʱ�ȭ �� �ؾ� �ұ� ? ��������,,,
// - ���� ���濡 �߿�
// - ������ �� �ּҰ��� �����Ǿ� �ִ� ���

// �ʱ�ȭ ���
// - ������ ������
// - �ʱ�ȭ ����Ʈ
// - C++ 11 ����

// �ʱ�ȭ ����Ʈ
// - �ϴ� ��� ���迡�� ���ϴ� �θ� ������ ȣ���� �� �ʿ��ϴ�
// - ������ ������ �ʱ�ȭ vs �ʱ�ȭ ����Ʈ
// -- �Ϲ� ������ �� ���� ����
// -- ��� Ÿ���� Ŭ������ ��� ���� �߻�
// -- �����԰� ���ÿ� �ʱ�ȭ�� �ȿ��� ��� (���� Ÿ��, const Ÿ��)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }

	~Inventory() { cout << "~Inventory()" << endl; }
public:
	int _size = 10;
};

class Player
{
public:
	Player() { id = 0; }
	Player(int id) { this->id = id; }

public:
	int id;
};

// Is-A (Knight Is-A Player? ���� �÷��̾�� ) OK -> ��Ӱ��� 

// Has-A (Knight Has-A Inventory? ���� �κ��丮�� �����ϰ� �ִ� ( ���� �ִ� )) OK -> ���԰���

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		��ó�� ����
		
		Inventory() -> Inventory(20)���� ȣ���
		*/
	{
		_hp = 100;
		// _inventory = Inventory(20); // �κ��丮 �����ڰ� 2�� ȣ��
	}

public:
	int _hp = 200; // �����ϸ鼭 �ʱ�ȭ -> C++ 11 ����
	Inventory _inventory;

	int& _hpRef;
	const int _hpConst;
};

int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
	{
		cout << "Knight is Dead" << endl;
	}


	return 0;
}