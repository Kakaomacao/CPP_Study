#include <iostream>
using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();


	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight; // ���� ������
	// Knight knight3(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �� ������ָ� �����Ϸ��� '�Ͻ�������' ������ش�
	
	// �߰� ���) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �׷� ���� ������ �����?? << NO

	// [ ���� ���� Shallow Copy ] 
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��
	// Stack : Knight  [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight3 [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// ���� ���� Pet�� ����Ű�� ���� -> �ϳ��� �Ҹ���״µ� �� �Ҹ��Ű���� �ϴϱ� ���� �߻�!

	// [ ���� ���� Deep Copy ]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش� (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü ����Ű�� ����
	// Stack : Knight  [ hp 0x1000 ] -> Heap 0x1000 Pet[    ]
	// Stack : Knight2 [ hp 0x2000 ] -> Heap 0x2000 Pet[    ]
	// Stack : Knight3 [ hp 0x3000 ] -> Heap 0x3000 Pet[    ]

	return 0;
}