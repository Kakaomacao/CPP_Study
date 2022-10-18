#include <iostream>
using namespace std;

// ������ ���� : �����ڿ� �Ҹ���

// [������(Constructor)�� �Ҹ���(Destructor)]
// Ŭ������ '�Ҽ�'�� �Լ����� ��� �Լ���� ��
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���
// - ����(ź��) -> ������ (���� �� ���� ����)
// - ��(�Ҹ�) -> �Ҹ��� (���� 1���� ���� ����)

// [�Ͻ���(Implicit) ������]
// �����ڸ� ��������� ������ ������
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������
// -> �׷��� �츮�� �����(Explicit)���� �ƹ� �����ڸ� �ϳ� �����
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� �ʴ´�!!

class Knight
{
public:
	// [1] �⺻ ������ (���ڰ� ����)
	Knight()
	{
		cout << "Knight() �⺻ ������ ȣ��" << endl;

		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] ���� ������ (�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����)
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ����Ѵ�
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] ��Ÿ ������
	Knight(int hp)
	{
		cout << "Knight(int) �⺻ ������ ȣ��" << endl;
		_hp = hp;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// �Ҹ���
	~Knight()
	{
		cout << "Knight() �Ҹ��� ȣ��" << endl;
	}



	// ��� �Լ� ����
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		this->_hp = 1;
		cout << "Die" << endl;
	}

public:
	// ��� ���� -> ������ �� �ְ� ��Ģ�� ���ϴ°� ����
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Move(Knight* knight, int y, int x)
{
	knight->_posY = y;
	knight->_posX = x;
}

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate : ��ü�� �����!
int main()
{
	Knight k1(100);
	// k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}