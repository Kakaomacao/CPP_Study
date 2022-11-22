#pragma once

class Food;

class Cart
{
private:
	// 대응되는 음식의 구매량
	int numberOf;
	// 대응되는 음식을 포장으로 주문할지, 배달로 주문할지
	int state;

	// 장바구니에 담긴 총 금액
	static int totalPrice;

public:
	// 장바구니에 대응되는 음식 (포인터)
	Food* food;

	// 생성자
	Cart();
	Cart(int n, int state, Food* food);

	// get 함수
	int getNumber();
	int getState();
	int getTotalPrice();

	// set 함수
	void setTotalPrice(int n);

	// 해당 장바구니 비우기
	void emptyCart();
	// 현재 멤버의 등급을 판단하여 totalPrice 수정
	static int discountByMembership(Member* curMember);
};

