#include <iostream>
using namespace std;

// ������ ���� : ������ vs ����

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

// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
StatInfo* FindMonster()
{
	// TODO : Heap �������� ������ ã�ƺ�
	// ã�Ҵ�!
	// return monster~;

	return nullptr;
}


StatInfo globalInfo;

// �ּ� ���� ���

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	if (!info)
		return;

	cout << "----------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------------" << endl;

	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����
	// info��� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!

	// �� ������ ���δٸ�?
	// const StatInfo* info
	// info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
	// '����' �ٱ��� ���빰�� �ٲ� �� ����!

	// info[ �ּҰ� ]       �ּҰ�[ ������ ]
	// info = &globalInfo;
	// info->hp = 10000;
}

// ���� ���� ���
// const�� ���� ��찡 ����
void PrintInfoByRef(const StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------------" << endl;
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;

	CreateMonster(&info);

	// ������ vs ���� ������ ���
	// ���� : �Ȱ���! (����� �󿡼� ���� ���� �Ȱ���)
	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ� ���� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� ����
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� ������� ��ġ�� �κ� ���� ����

	// ����� �����͵� const�� ��� ����
	// * �������� �տ� �ڿ� ���̴� ���� �ǹ̰� �ٸ�


	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸��� �ٿ��ִ� ����
	// -> �����ϴ� ����� ������ �ȵ�!!
	// �ݸ� �����ʹ� �׳� � �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����
	// �����Ϳ��� '����'��� �ǹ̷�? nullptr
	// ���� Ÿ���� �̷� nullptr�� ������ ����

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(info);

	// �׷��� �����?
	// ������ ���θ��� �ٸ� �� ����
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// ex) �𸮾� ���������� reference�� �ֿ�

	ChangeInfo(OUT info); // �����ؼ� ���ڴ� �ǹ̷� OUT ���


	// Bonus) �����ͷ� ����ϴ� ���� ������ �Ѱ��ַ���?
	// pointer[ �ּ�(&info) ]    info [ ������ ]
	PrintInfoByRef(*pointer);

	// Bonus) ������ ����ϴ� ���� �����ͷ� �Ѱ��ַ���?
	// pointer[ �ּ�(&info) ]    reference, info [ ������ ]
	PrintInfoByPtr(&reference);

	return 0;
}