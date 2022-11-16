#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;	// 아이템 구분을 위한 ID
	int _rarity;	// 희귀도
	int _ownerId;	// 소지자 ID
};

typedef bool(ITEM_SELECTOR)(Item* item, int);

Item* FindItem(Item items[], int itemCount, /*동작*/ ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];

		if (selector(item, value))
			return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer[ 주소 ] -> 주소 [    ]

	typedef int DATA;

	// 1) 포인터			*
	// 2) 변수 이름		pointer
	// 3) 데이터 타입	int
	DATA* pointer = &a;

	// 함수
	// int 2개를 받아서 int를 반환하는 함수 타입을 FUNC_TYPE으로 정의
	typedef int(FUNC_TYPE)(int a, int b);

	// 1) 포인터			*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	함수 (인자는 int 2개, 반환은 int)
	FUNC_TYPE* fn;

	// 함수 포인터
	fn = Add;	// 이 부분만 Sub로 고쳐서 바꿀 수 있어

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본 문법
	cout << result << endl;

	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자) 붙어도 함수 주소!!
	cout << result << endl;


	Item items[10];
	items[3]._rarity = 2;
	Item* rareItem = FindItem(items, 10, IsOwnerItem, 100);

	return 0;
}