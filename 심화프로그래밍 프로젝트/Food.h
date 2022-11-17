#pragma once

class Member;
#include "Cart.h"

class Food
{
private:
	// 가격, 평점, 설명, 음식 이름에 대한 변순
	int price;
	double rate;
	string detail;
	string name;

public:
	// 가격, 이름을 매개변수로 받는 생성자
	Food(int price, string name);

	// 음식의 이름 반환
	string getFoodName();

	void showFoodDetail();

	static void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3]);
};

