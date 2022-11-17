#pragma once

class Food;

class Cart
{
private:
	int numberOf;
	int state;
	Food* food;

	static int totalPrice;

public:
	Cart();
	Cart(int n, int state, Food* food);

	int getNumber();
	int getState();
	int getTotalPrice();
	void setTotalPrice(int n);

	void addCart();
	void emptyCart();
	void orderFood();

	static void showCart(Member* curMember, Cart carts[][3]);
};

