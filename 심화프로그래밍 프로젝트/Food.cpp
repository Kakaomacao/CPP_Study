#include <iostream>
using namespace std;

#include "Food.h"

Food::Food(int price, string name)
{
	this->price = price;
	this->name = name;
	rate = rand() % 5;
	detail = "���� ���� ���̷� ������ ��ο��� ����޴� ����";
}

//-------------------------------------------------------------------

// get �Լ���

// ������ ������ ��ȯ���ִ� �Լ�
int Food::getPrice()
{
	return price;
}

// ������ �̸��� ��ȯ���ִ� �Լ�
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

	cout << "���� : " << this->price << endl;
	cout << "���� : " << this->detail << endl;
}