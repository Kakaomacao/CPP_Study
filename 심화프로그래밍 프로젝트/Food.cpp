#include <iostream>
using namespace std;

#include "Food.h"

Food::Food(int price, string name)
{
	this->price = price;
	this->name = name;
	rate = rand() % 6;
	detail = " ";
}

//-------------------------------------------------------------------

string Food::getFoodName()
{
	return name;
}

void showFoodList()
{
	
}

//-------------------------------------------------------------------

void showFoodDetail()
{

}

//-------------------------------------------------------------------

void selectFood()
{

}

//-------------------------------------------------------------------

static void showFoodMenu(Food* curFood, Food foods[4][3])
{
	int cmd;
	int input;
	string input1, input2;

	cout << endl << "********************************" << endl;
	cout << "<음식 메뉴>" << endl;

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << i * j << ". " << foods[i][j].getFoodName() << "	";
		}

		cout << endl;
	}

	cout << "음식을 선택해주세요 >> ";
	cin >> cmd;
}
