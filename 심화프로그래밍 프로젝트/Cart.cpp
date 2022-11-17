#include <iostream>
using namespace std;

#include "member.h"
#include "Cart.h"
#include "Food.h"

Cart::Cart() : numberOf(0), state(0), food(nullptr) {}

Cart::Cart(int n, int state, Food* food)
{
	this->numberOf = n;
	this->state = state;
	this->food = food;
}

int Cart::getNumber()
{
	return numberOf;
}

int Cart::getState()
{
	return state;
}

int Cart::getTotalPrice()
{
	return totalPrice;
}

void Cart::setTotalPrice(int n)
{
	totalPrice += n;
}

void Cart::addCart()
{

}

void Cart::emptyCart()
{
	numberOf = 0;
	state = 0;
}

void Cart::orderFood()
{

}

void Cart::showCart(Member* curMember, Cart carts[][3])
{
	int input;

	if (totalPrice == 0)
	{
		cout << "장바구니가 비어있습니다." << endl; 
		return;
	}

	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			if (carts[i][j].getNumber() != 0)
			{
				cout << carts[i][j].food->getFoodName() << " : " << carts[i][j].getNumber() << "개를 ";

				if (carts[i][j].state == 1)
					cout << "포장 주문" << endl;
				else if (carts[i][j].state == 2)
					cout << "배달 주문" << endl;
			}
		}

	cout << "1) 주문 2) 나가기" << endl << ">> ";
	cin >> input;

	if (input == 1)
	{
		if (curMember->getPoint() >= totalPrice)
		{
			cout << "총 주문 금액은 " << totalPrice << "(원)입니다." << endl;
			cout << "예상 주문 소요 시간은 " << rand() % 50 + 10 << "분입니다." << endl;
			cout << "주문해주셔서 감사합니다~!" << endl;

			curMember->setMS(totalPrice);
			curMember->setPoint(curMember->getPoint() - totalPrice);
			curMember->setMS(totalPrice);

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
					carts[i][j].emptyCart();

			totalPrice = 0;
		}
	}
}