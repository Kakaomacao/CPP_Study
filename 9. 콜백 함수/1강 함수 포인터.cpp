#include <iostream>
using namespace std;

// ������ ���� : �Լ� ������

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
	int _itemId;	// ������ ������ ���� ID
	int _rarity;	// ��͵�
	int _ownerId;	// ������ ID
};

typedef bool(ITEM_SELECTOR)(Item* item, int);

Item* FindItem(Item items[], int itemCount, /*����*/ ITEM_SELECTOR* selector, int value)
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

	// �ٱ��� �ּ�
	// pointer[ �ּ� ] -> �ּ� [    ]

	typedef int DATA;

	// 1) ������			*
	// 2) ���� �̸�		pointer
	// 3) ������ Ÿ��	int
	DATA* pointer = &a;

	// �Լ�
	// int 2���� �޾Ƽ� int�� ��ȯ�ϴ� �Լ� Ÿ���� FUNC_TYPE���� ����
	typedef int(FUNC_TYPE)(int a, int b);

	// 1) ������			*
	// 2) ���� �̸�		fn
	// 3) ������ Ÿ��	�Լ� (���ڴ� int 2��, ��ȯ�� int)
	FUNC_TYPE* fn;

	// �Լ� ������
	fn = Add;	// �� �κи� Sub�� ���ļ� �ٲ� �� �־�

	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = fn(1, 2); // �⺻ ����
	cout << result << endl;

	int result2 = (*fn)(1, 2); // �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ�!!
	cout << result << endl;


	Item items[10];
	items[3]._rarity = 2;
	Item* rareItem = FindItem(items, 10, IsOwnerItem, 100);

	return 0;
}