#pragma once

class Food;

class Cart
{
private:
	// �����Ǵ� ������ ���ŷ�
	int numberOf;
	// �����Ǵ� ������ �������� �ֹ�����, ��޷� �ֹ�����
	int state;

	// ��ٱ��Ͽ� ��� �� �ݾ�
	static int totalPrice;

public:
	// ��ٱ��Ͽ� �����Ǵ� ���� (������)
	Food* food;

	// ������
	Cart();
	Cart(int n, int state, Food* food);

	// get �Լ�
	int getNumber();
	int getState();
	int getTotalPrice();

	// set �Լ�
	void setTotalPrice(int n);

	// �ش� ��ٱ��� ����
	void emptyCart();
	// ���� ����� ����� �Ǵ��Ͽ� totalPrice ����
	static int discountByMembership(Member* curMember);
};

