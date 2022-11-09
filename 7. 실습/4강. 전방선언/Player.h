#pragma once

// #include "Monster.h"

class Monster;

class Player
{
public:

	void KillMonster();

	// 전방선언만으로는 접근이 불가능해!!
	// #include "Monster.h"가 필요함
	// 따라서 cpp에 구현하는게 좋음
	void KillMonster2();


public:
	int _hp;
	int _attack;

	// _target을 선택하면 Monster의 설계도를 보지 않는 이상 Player가 몇 바이트인지 알 수 없음
	// 따라서 #include "Monster.h"가 필요함
	// Monster _target;

	// _target2를 선택하면 최종 설계도를 알지 못해도 주소의 크기는 정해져 있으므로 몇 바이트인지 알 수 있음
	// Monster 클래스가 있음을 알려주면 돼!
	// 전방선언 안하고 class Monster* _target2;도 가능
	Monster* _target2;

	// 플레이어 안에 플레이어를 넣으면 괜찮을까?
	// - 플레이어 크기를 분석 위해서는 플레이어 설계도가 필요함
	// -- 논리적으로 말이 안돼!!
	// --- 따라서 Player*를 이용해야 함
	Player* _target;
};

