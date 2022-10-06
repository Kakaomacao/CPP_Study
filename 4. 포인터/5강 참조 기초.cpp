#include <iostream>
using namespace std;

// ������ ���� : ����

struct StatInfo
{
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

// ������ �����Ͽ� ������ ����
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// �Ű������� �����ͷ� �޴°Ŷ� ���� �ٸ�
// ������ �ƴ϶� ����� �Ű������� �ٲ�
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����

// 1) �� ���� ���

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;

}

// 2) �ּ� ���� ���

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------------" << endl;

}

// StatInfo ����ü�� 1000����Ʈ¥�� ���� ����ü���?
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����
// - (�ּ� ����) StatInfo*�� 8����Ʈ
// - (���� ����) StatInfo&�� 8����Ʈ

// 3) ���� ���� ���
// �� ����ó�� ���ϰ� ����ϰ�!
// �ּ� ����ó�� �ּҰ��� �̿��Ͽ� ��¥�� �ǵ帮��!
// �ϼ������� ���!!

void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;
}

int main()
{
	// 4����Ʈ ������ �ٱ��ϸ� ����Ұž�
	// ������ �� �ٱ��� �̸��� number��� �Ұ�
	// �׷��ϱ� number���� �� �����ų�, number�� �� �ִ´ٰ� �ϸ�
	// �����Ϸ��� �˾Ƽ� �˾Ƶ�� �ش� �ּ�(data, stack, heap)�� 1�� �־��ָ� �ȴ�!
	int number = 1;

	// * �ּҸ� ��� �ٱ���
	// int �� �ٱ��ϸ� ���󰡸� int �����Ͱ� ����
	int* pointer = &number;
	// pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�.
	*pointer = 2;

	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
	// 
	int& reference = number;
	// C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��
	// number��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٰ�!
	// ������ reference �ٱ��Ͽ� �� �ְų� ������
	// ���� number �ٱ��Ͽ��ٰ� �� ���� �ְų� ������ ��!!
	reference = 3;

	// �۵� ����� �����Ͷ� ������ �� ������ �� �ٸ� �̸��� ���� ������??
	// �׳� number = 3�̶�� �ص� �Ȱ�����...
	// �� ����� ���� ����̴ϱ�!!

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}