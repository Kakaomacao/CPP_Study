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
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]	 <-> [ _Myhead : end() ]		// 이중 연결
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]	 <->	// 원형 연결
// 연속된 공간이 아니여도 되기 때문에 vector와 다르게 중간 삽입/삭제 가능
// -> 포인터만 앞뒤로 잘 연결해주기만 하면 된다!

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제 (GOOD / GOOD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (i번째 데이터는 어디 있습니까?)

	list<int> li;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
			itRemember = li.insert(li.end(), i);

		else
			li.push_back(i);
	}

	// li.push_front(10); -> 처음에 삽입하는게 전혀 부담되지 않으므로 지원
	int size = li.size();	// 동적 배열이 아니라서 capacity 개념 존재 X

	int first = li.front();
	int last = li.back();

	// li[3] = 10; // 임의 접근 X -> 엄청 큰 값이라면 타고 가는걸 너무 많이 해줘야함

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	// list<int>::iterator it2 = itBegin + 10; 임의 접근이 안되니까 당연히 빠르게 동작할리가 없음

	// list<int>::iterator itTest1 = --itBegin; 디버그 하면서 접근이 불가능
	// list<int>::iterator itTest2 = --itEnd; End에서 앞으로 오는건 가능
	// list<int>::iterator itTest3 = ++itEnd; 마찬가지로 앞으로 넘어서 못 넘어감

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	// li.insert(itBegin, 100);
	// li.erase(li.begin());
	// li.pop_front();
	// li.remove(10); // list는 vector와 다르게 지원하는군!! (vector는 중간 삽입/삭제가 너무 비효율적)

	// * 임의 접근이 안된다
	// * 중간 삽입/삭제가 빠르다 (?)
	// -> 임의 접근하여 삽입/삭제하는 것이 빠르다는 것이 아니라 erase()자체가 빠르다는 것!!
	// 만약 위치를 알고 있다면 바로 삭제가 가능!!

	// 50번 인덱스에 있는 데이터를 삭제!
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;

	li.erase(itRemember);

	return 0;
}