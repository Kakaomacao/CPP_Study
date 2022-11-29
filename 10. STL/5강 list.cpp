#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 : list

// vector : 동적 배열
// 데이터가 다 붙어있음

// [ data(4) next(4 or 8) ]
class Node
{
public:
	Node* _next;
	int _data;
};

// 단일 / 이중 / 원형
// list : 연결 리스트
// STL은 이중 연결 리스트!!

// 떨어져 있어도 문제 X	
// [1]       -> [2]    -> [3] -> [4]     -> [5]				// 단일 연결
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]			// 이중 연결
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]	 <->	// 원형 연결

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;

	for (int i = 0; i < 100; i++)
		li.push_back(i);

	// li.push_front(10);
	int size = li.size();	// 동적 배열이 아니라서 capacity 개념 존재 X

	int first = li.front();
	int last = li.back();

	// li[3] = 10; // 임의 접근 X

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);

	li.erase(li.begin());

	li.pop_front();

	li.remove(10); // list는 vector와 다르게 지원하는군!! (vector는 중간 삽입/삭제가 너무 비효율적)

	return 0;
}