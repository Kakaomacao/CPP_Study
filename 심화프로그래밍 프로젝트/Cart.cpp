#include <iostream>
using namespace std;

#include "Member.h"
#include "Cart.h"

//-------------------------------------------------------------------

// 생성자

// 기본 생성자
Cart::Cart() : numberOf(0), state(0), food(nullptr) {}

// 개수, 포장인지 배달인지, 대응되는 음식을 매개변수로 하는 생성자
Cart::Cart(int n, int state, Food* food)
{
	this->numberOf = n;
	this->state = state;
	this->food = food;
}

//-------------------------------------------------------------------

// get 함수들

// 대응되는 음식의 수량을 반환해주는 함수
int Cart::getNumber()
{
	return numberOf;
}

// 포장인지 배달인지를 알려주는 함수
int Cart::getState()
{
	return state;
}

// 전체 금액을 알려주는 함수
int Cart::getTotalPrice()
{
	return totalPrice;
}

//-------------------------------------------------------------------

// set 함수

// 전체 금액을 수정하는 함수
// 구매를 끝내고 나서 장바구니를 비우면서 총 금액을 0으로 수정
void Cart::setTotalPrice(int n)
{
	totalPrice = n;
}

//-------------------------------------------------------------------

// 해당 장바구니를 비우는 함수
void Cart::emptyCart()
{
	numberOf = 0;
	state = 0;
}

//-------------------------------------------------------------------

// 현재 회원을 매개변수로 받아서 회원 등급에 따라서 할인 금액 적용
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