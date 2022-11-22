#include <iostream>
using namespace std;

#include "Member.h"
#include "Cart.h"

//-------------------------------------------------------------------

// ������

// �⺻ ������
Cart::Cart() : numberOf(0), state(0), food(nullptr) {}

// ����, �������� �������, �����Ǵ� ������ �Ű������� �ϴ� ������
Cart::Cart(int n, int state, Food* food)
{
	this->numberOf = n;
	this->state = state;
	this->food = food;
}

//-------------------------------------------------------------------

// get �Լ���

// �����Ǵ� ������ ������ ��ȯ���ִ� �Լ�
int Cart::getNumber()
{
	return numberOf;
}

// �������� ��������� �˷��ִ� �Լ�
int Cart::getState()
{
	return state;
}

// ��ü �ݾ��� �˷��ִ� �Լ�
int Cart::getTotalPrice()
{
	return totalPrice;
}

//-------------------------------------------------------------------

// set �Լ�

// ��ü �ݾ��� �����ϴ� �Լ�
// ���Ÿ� ������ ���� ��ٱ��ϸ� ���鼭 �� �ݾ��� 0���� ����
void Cart::setTotalPrice(int n)
{
	totalPrice = n;
}

//-------------------------------------------------------------------

// �ش� ��ٱ��ϸ� ���� �Լ�
void Cart::emptyCart()
{
	numberOf = 0;
	state = 0;
}

//-------------------------------------------------------------------

// ���� ȸ���� �Ű������� �޾Ƽ� ȸ�� ��޿� ���� ���� �ݾ� ����
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