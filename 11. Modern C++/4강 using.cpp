#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 坷疵狼 林力 : using

typedef vector<int>::iterator VecIt;

typedef __int64 id;
using id2 = int;

// 1) 流包己
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 袍敲复
template<typename T>
using List = std::list<T>;

template<typename T>
struct List2
{
	typedef std::list<T> type;
};

int main()
{
	id playerId = 0;

	List<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	List2<int>::type li2;

	return 0;
}