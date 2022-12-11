#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : override, final

// final 사용시 더 이상 오버라이딩 불가
// 오버라이딩시 override를 붙여서 가독성은 높이고 실수 가능성은 낮추자

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
	// 재정의 (override)
	virtual void Attack() override
	{
		cout << "Knight!" << endl;
	}

	// 오버로딩(overloading) : 함수 이름의 재사용
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