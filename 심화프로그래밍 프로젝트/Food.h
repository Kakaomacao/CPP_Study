#pragma once

class Member;
#include "Cart.h"

class Food
{
private:
	// ����, ����, ����, ���� �̸��� ���� ����
	int price;
	double rate;
	string detail;
	string name;

public:
	// ����, �̸��� �Ű������� �޴� ������
	Food(int price, string name);

	// ������ �̸� ��ȯ
	string getFoodName();

	void showFoodDetail();

	static void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3]);
};

