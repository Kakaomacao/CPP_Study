#include <iostream>
using namespace std;
#include "Player.h"

// ������ ���� : ���漱��

// ���赵�� �ʿ��Ѱ� �� ����غ��� ���漱������ ��������� include���� ���� ����!

int main()
{
	// Player�� �� ����Ʈ?
	// int 2�� = 2 * 4  = 8����Ʈ + sizeof(Monster*, Player*) = 16����Ʈ

	Player p1; // �������� (Stack)

	Player* p2 = new Player(); // �����Ҵ� (Heap)

	return 0;
}