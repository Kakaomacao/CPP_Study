#include <iostream>
using namespace std;

// 오늘의 주제 : 초기화 리스트

// 멤버 변수 초기화 ? 다양한 문법이 존재

// 초기화 왜 해야 할까 ? 귀찮은데,,,
// - 버그 예방에 중요
// - 포인터 등 주소값이 연관되어 있는 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++ 11 문법

// 초기화 리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이 발생
// -- 정의함과 동시에 초기화가 팔요한 경우 (참조 타입, const 타입)

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

// Is-A (Knight Is-A Player? 기사는 플레이어다 ) OK -> 상속관계 

// Has-A (Knight Has-A Inventory? 기사는 인벤토리를 포함하고 있다 ( 갖고 있다 )) OK -> 포함관계

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		선처리 영역
		
		Inventory() -> Inventory(20)으로 호출됨
		*/
	{
		_hp = 100;
		// _inventory = Inventory(20); // 인벤토리 생성자가 2번 호출
	}

public:
	int _hp = 200; // 선언하면서 초기화 -> C++ 11 문법
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