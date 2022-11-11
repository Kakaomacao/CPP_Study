#include <iostream>
using namespace std;

#include "member.h"
int Member::memberCount = 0;

#include "Food.h"

int main()
{
	srand(time(NULL));

	int cmd;
	Member members[20];
	members[0] = Member("Admin", "Admin");
	Member* curMember = new Member();

	Food foods[4][3] = { {Food(1000, "�Ұ��ҹ��"), Food(2000, "�ӹ�����"), Food(3000, "��â����")},
		{Food(4000, "�����"), Food(5000, "������"), Food(6000, "«��")},
		{Food(7000, "�ʹ�����"), Food(8000, "Ƣ��쵿"), Food(9000, "��� ȸ")},
		{Food(10000, "���ġŲ"), Food(11000, "�������� ����"), Food(12000, "�Ұ�����")} };
	Food* curFood = nullptr;

	do {
		cout << endl << "********************************" << endl;
		cout << "<�޴� ����>" << endl;
		cout << "1. ȸ�� ����" << endl;
		cout << "2. ���� �޴�" << endl;
		cout << "3. �α���" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "�Է� >> ";

		cin >> cmd;

		switch (cmd)
		{
		case 1:
			Member::showMemberMenu(curMember, members);
			break;

		case 2:
			Food::showFoodMenu(curFood, foods);
			break;

		case 3:
			Member::login(curMember, members);
			break;

		case 0:
			break;

		default:
			cout << "��ȿ���� ���� �����Դϴ�." << endl;
			break;
		}

	} while (cmd != 0);

	return 0;
}
