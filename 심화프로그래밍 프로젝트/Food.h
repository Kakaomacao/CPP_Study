#pragma once

class Member;

class Food
{
private:
	// ����, ����, ����, ���� �̸��� ���� ����
	int price;
	double rate;
	string detail;
	string name;

public:
	// ����, �̸��� �Ű������� �޴� ������
	Food(int price, string name);

	int getPrice();
	// ������ �̸� ��ȯ
	string getFoodName();

	void showFoodDetail();
};

