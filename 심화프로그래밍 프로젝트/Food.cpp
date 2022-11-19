#include <iostream>
using namespace std;

#include "Food.h"

Food::Food(int price, string name)
{
	this->price = price;
	this->name = name;
	rate = rand() % 5;
	detail = "별미 중의 별미로 남녀노소 모두에게 사랑받는 음식";
}

//-------------------------------------------------------------------

int Food::getPrice()
{
	return price;
}

string Food::getFoodName()
{
	return name;
}

//-------------------------------------------------------------------

void Food::showFoodDetail()
{
	cout << this->name << endl;
	cout << "별점 : " << this->rate << " ";

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

	cout << "설명 : " << this->detail << endl;

}


//-------------------------------------------------------------------
