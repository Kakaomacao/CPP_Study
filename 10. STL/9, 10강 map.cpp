#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// ������ ���� : map

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
	// ���� �����̳�

	/*
	vector<Player*> v;

	// 10���� ����
	for (int i = 0; i < 100000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5������ ����
	for (int i = 0; i < 50000; i++)
	{
		int randomIndex = rand() % v.size();

		Player* p = v[randomIndex];
		delete p;

		v.erase(v.begin() + randomIndex);
	}

	// (ID = 2�� �÷��̾�)�� (ID = 1�� �÷��̾�)�� �����ϰ� �;��
	// Q) ID = 1���� Player�� ã���ּ���
	// A) ã�ƺ���

	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId == 10000)
		{
			found = true;
			break;
		}
	}

	// vector, list�� ġ������ ����
	// -> ���ϴ� ���ǿ� �ش��ϴ� �����͸� ������ ã�� �� [����]
	*/

	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���

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

	srand(static_cast<unsigned int>(time(nullptr)));

	// (Key, Value) ���·� ������ ����
	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200));

	// ok.first;	// ���� ����
	// ok.second;	// ������ ����

	// 10����
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5���� ����
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);
	}

	// Q) ID = 10000�� Player ã�� �ʹ�!
	// A) �ſ� ������ ã�� �� ����

	map<int, int>::iterator findIt = m.find(10000);
	
	if (findIt != m.end())
	{
		cout << "ã��" << endl;
	}

	else
	{
		cout << "�� ã��" << endl;
	}

	// map ��ȸ
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>&p = (*it);
		int key = (*it).first;
		int value = it->second;

		cout << key << " " << value << endl;
	}

	// ������ �߰�, ������ ����
	map<int, int>::iterator findIt = m.find(10000);

	if (findIt != m.end())
	{
		findIt->second = 200;
	}

	else
	{
		m.insert(make_pair(10000, 10000));
	}

	// ������ �߰�, ������ ���� v2
	m[5] = 500;

	m.clear();

	// [] ������ ����� �� ����
	// ������ ���� �ʴ��� (Key/Value) ������ �����Ͱ� �߰��ȴ�!
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
	}

	// �ְ�		(insert, [])
	// ����		(erase)
	// ã��		(find, [])
	// �ݺ���	(map::iterator) (*it) pair<key, value>&

	return 0;
}