#pragma once

// #include "Monster.h"

class Monster;

class Player
{
public:

	void KillMonster();

	// ���漱�����δ� ������ �Ұ�����!!
	// #include "Monster.h"�� �ʿ���
	// ���� cpp�� �����ϴ°� ����
	void KillMonster2();


public:
	int _hp;
	int _attack;

	// _target�� �����ϸ� Monster�� ���赵�� ���� �ʴ� �̻� Player�� �� ����Ʈ���� �� �� ����
	// ���� #include "Monster.h"�� �ʿ���
	// Monster _target;

	// _target2�� �����ϸ� ���� ���赵�� ���� ���ص� �ּ��� ũ��� ������ �����Ƿ� �� ����Ʈ���� �� �� ����
	// Monster Ŭ������ ������ �˷��ָ� ��!
	// ���漱�� ���ϰ� class Monster* _target2;�� ����
	Monster* _target2;

	// �÷��̾� �ȿ� �÷��̾ ������ ��������?
	// - �÷��̾� ũ�⸦ �м� ���ؼ��� �÷��̾� ���赵�� �ʿ���
	// -- �������� ���� �ȵ�!!
	// --- ���� Player*�� �̿��ؾ� ��
	Player* _target;
};

