#include <iostream>
using namespace std;
#include <vector>
#include <list>

// ������ ���� : list

// vector : ���� �迭
// �����Ͱ� �� �پ�����

// [ data(4) next(4 or 8) ]
class Node
{
public:
	Node* _next;
	int _data;
};

// ���� / ���� / ����
// list : ���� ����Ʈ
// STL�� ���� ���� ����Ʈ!!

// ������ �־ ���� X	
// [1]       -> [2]    -> [3] -> [4]     -> [5]				// ���� ����
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]	 <-> [ _Myhead : end() ]		// ���� ����
// [1]       <-> [2]    <-> [3] <-> [4]     <-> [5]	 <->	// ���� ����
// ���ӵ� ������ �ƴϿ��� �Ǳ� ������ vector�� �ٸ��� �߰� ����/���� ����
// -> �����͸� �յڷ� �� �������ֱ⸸ �ϸ� �ȴ�!

int main()
{
	// list (���� ����Ʈ)
	// - list�� ���� ����
	// - �߰� ����/���� (GOOD / GOOD)
	// - ó��/�� ����/���� (GOOD / GOOD)
	// - ���� ���� (i��° �����ʹ� ��� �ֽ��ϱ�?)

	list<int> li;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
			itRemember = li.insert(li.end(), i);

		else
			li.push_back(i);
	}

	// li.push_front(10); -> ó���� �����ϴ°� ���� �δ���� �����Ƿ� ����
	int size = li.size();	// ���� �迭�� �ƴ϶� capacity ���� ���� X

	int first = li.front();
	int last = li.back();

	// li[3] = 10; // ���� ���� X -> ��û ū ���̶�� Ÿ�� ���°� �ʹ� ���� �������

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	// list<int>::iterator it2 = itBegin + 10; ���� ������ �ȵǴϱ� �翬�� ������ �����Ҹ��� ����

	// list<int>::iterator itTest1 = --itBegin; ����� �ϸ鼭 ������ �Ұ���
	// list<int>::iterator itTest2 = --itEnd; End���� ������ ���°� ����
	// list<int>::iterator itTest3 = ++itEnd; ���������� ������ �Ѿ �� �Ѿ

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	// li.insert(itBegin, 100);
	// li.erase(li.begin());
	// li.pop_front();
	// li.remove(10); // list�� vector�� �ٸ��� �����ϴ±�!! (vector�� �߰� ����/������ �ʹ� ��ȿ����)

	// * ���� ������ �ȵȴ�
	// * �߰� ����/������ ������ (?)
	// -> ���� �����Ͽ� ����/�����ϴ� ���� �����ٴ� ���� �ƴ϶� erase()��ü�� �����ٴ� ��!!
	// ���� ��ġ�� �˰� �ִٸ� �ٷ� ������ ����!!

	// 50�� �ε����� �ִ� �����͸� ����!
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;

	li.erase(itRemember);

	return 0;
}