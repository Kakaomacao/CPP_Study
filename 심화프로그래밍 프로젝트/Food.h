#pragma once

class Food
{
private:
	int price;
	double rate;
	string detail;
	string name;

public:
	Food(int price, string name);

	string getFoodName();

	void showFoodList();
	void showFoodDetail();
	void selectFood();

	static void showFoodMenu(Food* curMember, Food members[][3]);
};

