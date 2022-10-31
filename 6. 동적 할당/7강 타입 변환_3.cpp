#include <iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ (������)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{

	}

	Item(const Item& item)
	{
		cout << "Item(const Item& item)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {}; // �̷� ���� ������� ���� �������
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

	int _defense = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [ �ּ� ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// �Ͻ������δ� NO
		// ��������δ� OK

		// Stack [ �ּ� ] 
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDbId = 1;

		delete knight;
	} 

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		// [ [ item ]    ]
		// [    _damage  ]
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		// [ [ item ]    ]
		// [    _damage  ]
		Weapon* weapon = new Weapon();

		// �Ͻ������ε� ����!!
		Item* item = weapon;

		delete weapon;
	}

	// ��������� Ÿ�� ��ȯ�� ���� �׻� �׻� �����ؾ� �Ѵ�!!
	// �Ͻ������� �� ���� �׻� �����Ѱ�??
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� ���ϸ� �Ǵ°� �ƴѰ�?

	Item* inventory[20] = {};

	srand(time(NULL));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2; // 0 Ȥ�� 1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}



	return 0;
}