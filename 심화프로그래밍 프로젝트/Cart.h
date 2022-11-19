#pragma once

class Food;

class Cart
{
private:
	int numberOf;
	int state;

	static int totalPrice;

public:
	Food* food;

	Cart();
	Cart(int n, int state, Food* food);

	int getNumber();
	int getState();
	int getTotalPrice();
	void setTotalPrice(int n);

	void addCart();
	void emptyCart();
	void orderFood();
	static int discountByMembership(Member* curMember);

};

