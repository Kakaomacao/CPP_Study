#include "Player.h"

#include "Monster.h"

void Player::KillMonster()
{
	// �ּҷ� ���°Ŵ� ������µ� _hp�� ��� �ִ��� �� �� ����
	// [ �ּ� ] -> [ [monsterId][hp][defense] ]
	// Monster�� ���赵�� �˾ƾ� ������ ����
	// include "Monster.h"�� ����� ��!!	
	_target2->_hp = 0;

	// ���� �Ӹ� �ƴ϶� �Լ��� ��������!!
	_target2->KillMe();
}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}