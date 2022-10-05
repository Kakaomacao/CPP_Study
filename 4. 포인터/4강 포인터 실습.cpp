#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습


// 총 12바이트
struct StatInfo
{
	int hp;		 // +0
	int attack;	 // +4
	int defense; // +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
// 플레이어 승리시 true, 패배시 false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defense = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(c,c,c), player(b,b,b))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
	player = CreatePlayer();
	// 컴파일하면 아래와 같은 형태로
	// StatInfo temp = CreatePlayer();
	// player = temp;


	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defense = 0xbbbbbbbb;

	// Player의 경우에 비해서 어셈블리 상에서 매우 깔끔해짐을 알 수 있음
	// 바로 몬스터 주소로 간 다음 수정

	// [매개변수][RET][지역변수monster(b,b,b)] [매개변수(&monster)][RET][지역변수]
	// 다음 바로 아래로
	// [매개변수][RET][지역변수monster(40,8,1)] [매개변수(&monster)][RET][지역변수]
	CreateMonster(&monster);

	// 번외편 1)
	// 구조체끼리 복사할 때 무슨 일이 발생할까?
	// 한줄이지만 한줄짜리가 아니라 모든 정보가 하나씩 옮겨짐
	// player = monster;

	bool victory = StartBattle(&player, &monster);
	if (victory)
		cout << "승리" << endl;
	else
		cout << "패배" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defense = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defense = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defense;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defense;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if ( player->hp < 0)
			 player->hp = 0;

		cout << "플레이어 HP : " << player->hp << endl;

		if (player->hp == 0)
			return false;
	}
}