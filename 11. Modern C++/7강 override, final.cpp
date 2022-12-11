#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// ������ ���� : override, final

// final ���� �� �̻� �������̵� �Ұ�
// �������̵��� override�� �ٿ��� �������� ���̰� �Ǽ� ���ɼ��� ������

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}
};

class Player : public Creature
{
public:
	virtual void Attack() override 
	{
		cout << "Player!" << endl;
	}
};

class Knight : public Player
{
public:
	// ������ (override)
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

	// �����ε�(overloading) : �Լ� �̸��� ����
	void Attack(int a)
	{

	}

private:
	int _stamina = 100;
};

int main()
{
	Knight* knight = new Knight();
	knight->Attack();

	Player* player = new Knight();
	player->Attack();

	// Creature* c = new Knight();
	// c->Attack();

	return 0;
}