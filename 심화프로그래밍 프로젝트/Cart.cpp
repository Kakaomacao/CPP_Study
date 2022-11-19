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

int Cart::discountByMembership(Member* curMember)
{
	if (curMember->getMembership() == "Bronze")
		return totalPrice * 0.95 / 10 * 10;
	else if (curMember->getMembership() == "Silver")
		return totalPrice * 0.92 / 10 * 10;
	else if (curMember->getMembership() == "Gold")
		return totalPrice * 0.90 / 10 * 10;
	else if (curMember->getMembership() == "Platinum")
		return totalPrice * 0.85 / 10 * 10;
}

