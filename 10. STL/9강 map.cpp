#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// 오늘의 주제 : map

class Player
{
public:
	Player() : _playerId(0)	{ }
	Player(int playerId) : _playerId(playerId) { }

public:
	int _playerId;
};

int main()
{
	// 연관 컨테이너

	/*
	vector<Player*> v;

	// 10만명 입장
	for (int i = 0; i < 100000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5만명이 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomIndex = rand() % v.size();

		Player* p = v[randomIndex];
		delete p;

		v.erase(v.begin() + randomIndex);
	}

	// (ID = 2만 플레이어)가 (ID = 1만 플레이어)를 공격하고 싶어요
	// Q) ID = 1만인 Player를 찾아주세요
	// A) 찾아본다

	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId == 10000)
		{
			found = true;
			break;
		}
	}

	// vector, list의 치명적인 단점
	// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 [없다]
	*/

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;

		// DATA
		pair<int, Player*> _data;
		// int		_key;
		// Player*	_value;
	};

	// (Key, Value) 형태로 데이터 저장
	map<int, int> m;

	// 10만명
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 10000인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음

	m.find(10000);


	return 0;
}