#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : enum class

// unscoped enum (범위없는)
enum PlayerType : char
{
	PT_None,
	PT_Knight, 
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	MT_None
};

enum class ObjectType
{
	Player,
	Monster, 
	Projectile
};

enum class ObjectType2
{
	Player,
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped)
	// 2) 암묵적인 변환 금지

	double value = static_cast<double>(ObjectType::Player);

	int choice;
	cin >> choice;

	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));

	// PlayerType t;
	// cout << sizeof(t) << endl;
	// cout << sizeof(PlayerType) << endl;

	return 0;
}