#include <iostream>
using namespace std;

#include "member.h"

int main()
{
	int cmd;
	Member* curMember = new Member();

	do {
		cout << "********************************" << endl;
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
			break;

		case 2:
			break;

		case 3:
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