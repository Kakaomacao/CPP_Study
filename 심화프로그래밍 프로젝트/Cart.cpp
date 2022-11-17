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
		cout << "��ٱ��ϰ� ����ֽ��ϴ�." << endl; 
		return;
	}

	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			if (carts[i][j].getNumber() != 0)
			{
				cout << carts[i][j].food->getFoodName() << " : " << carts[i][j].getNumber() << "���� ";

				if (carts[i][j].state == 1)
					cout << "���� �ֹ�" << endl;
				else if (carts[i][j].state == 2)
					cout << "��� �ֹ�" << endl;
			}
		}

	cout << "1) �ֹ� 2) ������" << endl << ">> ";
	cin >> input;

	if (input == 1)
	{
		if (curMember->getPoint() >= totalPrice)
		{
			cout << "�� �ֹ� �ݾ��� " << totalPrice << "(��)�Դϴ�." << endl;
			cout << "���� �ֹ� �ҿ� �ð��� " << rand() % 50 + 10 << "���Դϴ�." << endl;
			cout << "�ֹ����ּż� �����մϴ�~!" << endl;

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