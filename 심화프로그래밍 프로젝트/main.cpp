#include <iostream>
using namespace std;

#include "member.h"
int Member::memberCount = 0;

#include "Food.h"

#include "Cart.h"
int Cart::totalPrice = 0;

void showMemberMenu(Member* curMember, Member members[]);
void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3]);
void login(Member*& curMember, Member members[]);
void showCart(Member* curMember, Cart carts[][3]);

int main()
{
	srand(time(NULL));

	int cmd;
	Member members[20];
	members[0] = Member("Admin", "Admin");
	Member* curMember = new Member();

	Food foods[4][3] = { Food(1000, "�ҹ��Ұ��"), Food(2000, "�ӹ�����"), Food(3000, "��â����"),
		Food(4000, "�����"), Food(5000, "������"), Food(6000, "«��"),
		Food(7000, "�ʹ�����"), Food(8000, "Ƣ��쵿"), Food(9000, "��� ȸ"),
		Food(10000, "���ġŲ"), Food(11000, "����"), Food(12000, "�Ұ�����") };
	Food* curFood = nullptr;

	Cart carts[4][3];

	do {
		cout << endl << "********************************" << endl;
		cout << "<�޴� ����>" << endl;
		cout << "1. ȸ�� ����" << endl;
		cout << "2. ���� �޴�" << endl;
		cout << "3. �α���" << endl;
		cout << "4. ��ٱ���" << endl;
		cout << "0. ���α׷� ����" << endl;
		cout << "�Է� >> ";
		cin >> cmd;

		switch (cmd)
		{
		case 1:
			showMemberMenu(curMember, members);
			break;

		case 2:
			showFoodMenu(curMember, curFood, foods, carts);
			break;

		case 3:
			login(curMember, members);
			break;

		case 4:
			showCart(curMember, carts);

		case 0:
			break;

		default:
			cout << "��ȿ���� ���� �����Դϴ�." << endl;
			break;
		}

	} while (cmd != 0);

	return 0;
}

// ȸ�� ���� �޴� -> 5���� ��� ����
void showMemberMenu(Member* curMember, Member members[])
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
		// ȸ�� ����
	case 1:
		curMember->setMemberCount(curMember->getMemberCount() + 1);
		cout << endl << "<ȸ�� ����>" << endl;
		cout << "���̵� �Է��ϼ���." << endl << ">> ";
		cin >> input1;
		cout << "��й�ȣ�� �Է��ϼ���." << endl << ">> ";
		cin >> input2;
		members[curMember->getMemberCount()] = Member(input1, input2);
		break;

		// ȸ�� Ż��
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
			cout << "������ ���� " << curMember->getId() << "�� �����Ͻðڽ��ϱ� ? " << endl;
			cout << "1) �� 2) �ƴϿ�" << endl;
			cout << ">> ";
			cin >> input;

			if (input == 1)
			{
				for (int i = 1; i < curMember->getMemberCount(); i++)
				{
					// ��ĭ�� ����� �̱���
				}

				curMember->setMemberCount(curMember->getMemberCount() - 1);
			}

			else
			{
				cout << "ȸ�� Ż�� ����ϼ̽��ϴ�." << endl;
			}
		}
		break;

		// ��� Ȯ��
	case 3:
		cout << endl << "<��� Ȯ��>" << endl;
		cout << "Bronze		~3	5% ����" << endl
			<< "Silver		~5	8% ����" << endl
			<< "Gold		~9	10% ����" << endl
			<< "Platinum	10�̻�	15% ����" << endl;
		cout << "���� ����� " << curMember->getMembership() << "�Դϴ�." << endl;
		break;

		// ����Ʈ ���� (ȸ���� ��쿡�� ����)
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
				cout << "���� �ܿ� ����Ʈ�� " << curMember->getPoint() + input << endl;
			}

			else
			{
				cout << "��ȿ���� ���� �ݾ��Դϴ�." << endl;
			}
		}
		break;

		// ȸ�� ��� ���� (Admin�� ��쿡�� ����)
	case 5:
		if (curMember->isAdmin())
		{
			for (int i = 1; i <= curMember->getMemberCount(); i++)
			{
				cout << members[i].getId() << " " << members[i].getPassword() << endl;
			}

			cout << "�� ȸ���� " << curMember->getMemberCount() << "�� �Դϴ�." << endl;
		}

		else
		{
			cout << "�����ڰ� �ƴմϴ�." << endl;
		}
		break;

		// �ٸ� Ŀ�ǵ� �Է½� �޼��� ���
	default:
		cout << "�߸��� �Է��Դϴ�." << endl;
		break;
	}
}

//-------------------------------------------------------------------

// ���� �޴� 
void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3])
{
	int cmd;
	string input1, input2;
	int input3, input4;

	cout << endl << "********************************" << endl;
	cout << "<���� �޴�>" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << (i * 3) + (j + 1) << ". " << foods[i][j].getFoodName() << "	";
		}

		cout << endl;
	}

	cout << "������ �������ּ��� >> ";
	cin >> cmd;

	int a = cmd / 3;
	int b = cmd % 3 - 1;

	curFood = &foods[a][b];

	cout << endl;
	cout << curFood->getFoodName() << "��(��) ���õǾ����ϴ�." << endl;
	cout << "1�� �ֹ��ϱ�(ȸ�� ����) / 2�� ���� ���� ����" << endl;
	cout << ">> ";
	cin >> cmd;

	switch (cmd)
	{
	case 1:
	{
		if (curMember->isNonMember())
		{
			cout << "ȸ���� �ƴմϴ�. �α����� ���ּ���." << endl;
			break;
		}

		cout << "<�ֹ��ϱ�>" << endl;
		cout << "1�� ���� / 2�� ���" << endl << ">> ";
		cin >> input3;

		cout << "�ֹ��� ������ �Է��ϼ��� : ";
		cin >> input4;

		carts[a][b] = Cart(input4, input3, curFood);

		cout << curFood->getFoodName() << "��(��) " << carts[a][b].getNumber() << "���� ��ٱ��Ͽ� �����ϴ�.";
		carts[a][b].setTotalPrice(foods[a][b].getPrice() * carts[a][b].getNumber());

		cout << "��ٱ��Ϸ� �̵��Ͽ� �ֹ��� �����ּ���~" << endl;

		break;
	}

	case 2:
	{
		cout << "<���� ���� ����>" << endl;
		curFood->showFoodDetail();
		break;
	}

	default:
		break;
	}
}

//-------------------------------------------------------------------

// �α��� �޴�
void login(Member*& curMember, Member members[])
{
	// �Է��� ���� string ���� 2���� �α��� ���� ���� Ȯ���� ���� bool ����
	string input1, input2;
	bool approval = false;

	cout << endl << "<�α���>" << endl;
	cout << "���̵� �Է��ϼ��� : ";
	cin >> input1;
	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> input2;

	// ȸ�� ��Ͽ��� ������ id�� ã�� ��쿡 ���ؼ� password ��
	// �� �� ��ġ�ϴ� ��쿡�� ������ true�� ��ȯ�ϰ� ���� ����� ����Ű�� ������ ����
	for (int i = 0; i <= curMember->getMemberCount(); i++)
	{
		if (input1 == members[i].getId())
		{
			if (input2 == members[i].getPassword())
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

//-------------------------------------------------------------------

// ��ٱ��� �޴�
void showCart(Member* curMember, Cart carts[][3])
{
	int input;

	if (carts[0][0].getTotalPrice() == 0)
	{
		cout << "��ٱ��ϰ� ����ֽ��ϴ�." << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (carts[i][j].getNumber() != 0)
			{
				cout << carts[i][j].food->getFoodName() << " : " << carts[i][j].getNumber() << "���� ";

				if (carts[i][j].getState() == 1)
					cout << "���� �ֹ�" << endl;
				else if (carts[i][j].getState() == 2)
					cout << "��� �ֹ�" << endl;
			}
		}
	}

	cout << "1) �ֹ� 2) ������" << endl << ">> ";
	cin >> input;

	int discountedPrice = Cart::discountByMembership(curMember);

	if (input == 1)
	{
		if (curMember->getPoint() >= discountedPrice)
		{
			cout << "�� �ֹ� �ݾ��� " << discountedPrice << "(��)�Դϴ�." << endl;
			cout << "���� �ֹ� �ҿ� �ð��� " << rand() % 50 + 10 << "���Դϴ�." << endl;
			cout << "�ֹ����ּż� �����մϴ�~!" << endl;

			curMember->setMS(discountedPrice);
			curMember->setPoint(curMember->getPoint() - discountedPrice);
			curMember->setMS(discountedPrice);

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
					carts[i][j].emptyCart();

			carts[0][0].setTotalPrice(0);
		}

		else
		{
			cout << "�ܾ��� �����մϴ�!! ���� �� �ֹ����ּ���~" << endl;
		}
	}
}