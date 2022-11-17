#include <iostream>
using namespace std;

#include "Food.h"
#include "member.h"

Food::Food(int price, string name)
{
	this->price = price;
	this->name = name;
	rate = rand() % 5;
	detail = "���� ���� ���̷� ������ ��ο��� ����޴� ����";
}

//-------------------------------------------------------------------

string Food::getFoodName()
{
	return name;
}

//-------------------------------------------------------------------

void Food::showFoodDetail()
{
	cout << this->name << endl;
	cout << "���� : " << this->rate << " ";

	if (this->rate == 5)
	{
		cout << "*****" << endl;
	}

	else if (this->rate >= 4 && this->rate < 5)
	{
	cout << "****" << endl;
	}

	else if (this->rate >= 3 && this->rate < 4)
	{
		cout << "***" << endl;
	}

	else if (this->rate >= 2 && this->rate < 3)
	{
		cout << "**" << endl;
	}

	else if (this->rate >= 1 && this->rate < 2)
	{
		cout << "*" << endl;
	}

	else
	{
		cout << endl;
	}

	cout << "���� : " << this->detail << endl;

}


//-------------------------------------------------------------------

void Food::showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3])
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
	cout << curFood->getFoodName() <<"��(��) ���õǾ����ϴ�." << endl;
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

		a = input3 / 3;
		b = input3 % 3 - 1;

		carts[a][b] = Cart(input4, input3, curFood);

		cout << curFood->getFoodName() << "��(��) " << carts[a][b].getNumber() << "���� ��ٱ��Ͽ� �����ϴ�.";
		carts[a][b].setTotalPrice(foods[a][b].price * carts[a][b].getNumber());		

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

	// ������ �������� ���� �� ���� + ��� -> ��ٱ��� ��� -> ����
}
