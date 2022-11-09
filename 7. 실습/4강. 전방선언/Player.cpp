#include "Player.h"

#include "Monster.h"

void Player::KillMonster()
{
	// 주소로 가는거는 상관없는데 _hp는 어디 있는지 알 수 없어
	// [ 주소 ] -> [ [monsterId][hp][defense] ]
	// Monster의 설계도를 알아야 접근이 가능
	// include "Monster.h"를 해줘야 해!!	
	_target2->_hp = 0;

	// 변수 뿐만 아니라 함수도 마찬가지!!
	_target2->KillMe();
}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}