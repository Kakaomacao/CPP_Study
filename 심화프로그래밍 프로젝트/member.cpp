#include <iostream>
using namespace std;

#include "member.h"

Member::Member()
{
	id = "";
	password = "";
	membership = "��ȸ��";
	point = 0;
	memberPoint = 0;
}

Member::Member(string id = "", string pw = "")
{
	this->id = id;
	password = pw;
	membership = "Bronze";
	point = 0;
	memberPoint = 0;
}

//-------------------------------------------------------------------

bool Member::isNonMember()
{
	if (this->membership == "��ȸ��")
		return true;

	else
		return false;
}

//-------------------------------------------------------------------

bool Member::isAdmin()
{
	if (this->id == "Admin")
	{
		return true;
	}

	else
		return false;
}

//-------------------------------------------------------------------

int Member::getMemberCount()
{
	return memberCount;
}

//-------------------------------------------------------------------

void Member::showMemberMenu(Member* curMember, Member members[])
{
	int cmd;
	int input;
	string input1, input2;

	cout << endl << "********************************" << endl;
	cout << "<ȸ�� ����>" << endl;
	cout << "1. ȸ�� ����" << endl;
	cout << "2. ȸ�� Ż��" << endl;
	cout << "3. ��� Ȯ��" << endl;
	cout << "4. ����Ʈ����" << endl;
	cout << "5. ȸ�� ��� (������ ����)" << endl;
	cout << "�Է� >> ";
	cin >> cmd;

	switch (cmd)
	{
	case 1:
		memberCount++;
		cout << endl << "<ȸ�� ����>" << endl;
		cout << "���̵� �Է��ϼ���." << endl << ">> ";
		cin >> input1;
		cout << "��й�ȣ�� �Է��ϼ���." << endl << ">> ";
		cin >> input2;
		members[memberCount] = Member(input1, input2);
		break;

	case 2:
		cout << endl << "<ȸ�� Ż��>" << endl;
		if (curMember->isNonMember())
		{
			cout << "ȸ���� �ƴմϴ�." << endl;
			break;
		}

		else
		{
			// ���̵� ���� && ��� �����
			cout << endl << "<ȸ�� Ż��>" << endl;
			cout << "������ ���� " << curMember->id <<"�� �����Ͻðڽ��ϱ� ? " << endl;
			cout << "1) �� 2) �ƴϿ�" << endl;
			cout << ">> ";
			cin >> input;

			if (input == 1)
			{
				for (int i = 1; i < memberCount; i++)
				{

				}

				memberCount--;
			}

			else
			{
				cout << "ȸ�� Ż�� ����ϼ̽��ϴ�." << endl;
			}
		}
		break;

	case 3:
		cout << endl << "<��� Ȯ��>" << endl;
		cout << "Bronze		~3	5% ����" << endl
			 << "Silve		~5	8% ����" << endl
			 << "Gold		~9	10% ����" << endl
			 << "Platinum	10�̻�	15% ����" << endl;
		cout << "���� ����� " << curMember->membership << "�Դϴ�." << endl;
		break;

	case 4:
		cout << endl << "<����Ʈ ����>" << endl;
		if (curMember->isNonMember())
		{
			cout << "ȸ���� �ƴմϴ�." << endl;
			break;
		}

		else
		{
			cout << "������ ����Ʈ�� �Է����ּ��� (1000�� ����) : ";
			cin >> input;
			
			if (input % 1000 == 0)
			{
				cout << "������ �Ϸ��Ͽ����ϴ�." << endl;
				cout << "���� �ܿ� ����Ʈ�� " << curMember->point + input << endl;
			}

			else
			{
				cout << "��ȿ���� ���� �ݾ��Դϴ�." << endl;
			}
		}
		break;

	case 5:
		if (curMember->isAdmin())
		{
			for (int i = 1; i <= memberCount; i++)
			{
				cout << members[i].id << " " << members[i].password << endl;
			}
		}

		else
		{
			cout << "�����ڰ� �ƴմϴ�." << endl;
		}
		break;

	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}

//-------------------------------------------------------------------

void Member::login(Member*& curMember, Member members[])
{
	string input1, input2;
	bool approval = false;

	cout << endl << "<�α���>" << endl;
	cout << "���̵� �Է��ϼ��� : ";
	cin >> input1;
	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> input2;

	for (int i = 0; i <= memberCount; i++)
	{
		if (input1 == members[i].id)
		{
			if (input2 == members[i].password)
			{
				cout << "�α��ο� �����Ͽ����ϴ�." << endl;
				curMember = &members[i];
				approval = true;
			}
		}
	}

	if (!approval)
		cout << "�α��ο� �����Ͽ����ϴ�." << endl;

}