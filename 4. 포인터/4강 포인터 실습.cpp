#include <iostream>
using namespace std;

// ������ ���� : ������ �ǽ�


// �� 12����Ʈ
struct StatInfo
{
	int hp;		 // +0
	int attack;	 // +4
	int defense; // +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
// �÷��̾� �¸��� true, �й�� false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	cout << "�κ� �����߽��ϴ�." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defense = 0xbbbbbbbb;

	// [�Ű�����][RET][��������(temp(c,c,c), player(b,b,b))] [�Ű�����(&temp)][RET][��������(ret(100, 10, 2))]
	player = CreatePlayer();
	// �������ϸ� �Ʒ��� ���� ���·�
	// StatInfo temp = CreatePlayer();
	// player = temp;


	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defense = 0xbbbbbbbb;

	// Player�� ��쿡 ���ؼ� ����� �󿡼� �ſ� ��������� �� �� ����
	// �ٷ� ���� �ּҷ� �� ���� ����

	// [�Ű�����][RET][��������monster(b,b,b)] [�Ű�����(&monster)][RET][��������]
	// ���� �ٷ� �Ʒ���
	// [�Ű�����][RET][��������monster(40,8,1)] [�Ű�����(&monster)][RET][��������]
	CreateMonster(&monster);

	// ������ 1)
	// ����ü���� ������ �� ���� ���� �߻��ұ�?
	// ���������� ����¥���� �ƴ϶� ��� ������ �ϳ��� �Ű���
	// player = monster;

	bool victory = StartBattle(&player, &monster);
	if (victory)
		cout << "�¸�" << endl;
	else
		cout << "�й�" << endl;
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "�÷��̾� ����" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defense = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;

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

		cout << "���� HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defense;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if ( player->hp < 0)
			 player->hp = 0;

		cout << "�÷��̾� HP : " << player->hp << endl;

		if (player->hp == 0)
			return false;
	}
}