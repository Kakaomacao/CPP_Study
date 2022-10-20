#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 함수는 묶어줄 수가 없음
struct StatInfo
{
	int hp;
	int attack;
	int defense;
};

// 메모리

// [ [ Player ] ]
// [   Knight   ]

// 상속 (Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(여러 개 가능) / 소멸자(1개만 가능)

// 생성자는 탄생을 기념해서 호출하는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘 다 호출하자!

// GameObject
// - Creature
// -- Player, Monster, NPC, Pet
// - Projectile
// -- Arrow, Fireball
// - Env (채집물)

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll

class GameObject
{
public:
	int _objectId;
};

class Player : public GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defense = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defense = 0;
		cout << "Player(int hp) 생성자 호출" << endl;
	}


	~Player()
	{
		cout << "Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defense;
};

// class는 일종의 설계도
class Knight : public Player
{
public:
	Knight()
		/*
		선처리 영역
		- 여기서 Player() 생성자를 호출
		*/
	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
		선처리 영역
		- 여기서 Player(int hp) 생성자를 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "Knight() 소멸자 호출" << endl;
	}
	/*
	후처리 영역
	- 여기서 ~Player() 소멸자를 호출
	*/

	// 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든?
	void Move() { cout << "Knight Move 호출" << endl; }
	
public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mana;
};

int main()
{
	Knight k; // 생성자와 소멸자가 전부 호출됨 (부모 먼저 -> 자식)
	Knight k2(100); // 여전히 Player의 기본 생성자 호출

	k._hp = 100;
	k._attack = 10;
	k._defense = 5;
	k._stamina = 50;
	
	k.Move();		  // 나이트 버젼으로 호출됨
	k.Player::Move(); // 플레이어 버젼으로 호출됨 -> 거의 안씀 그냥 참고

	k.Attack();
	k.Die();

	return 0;
}