#pragma once

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

	// get �Լ�
	int getPrice();
	string getFoodName();

	// ������ �̸�, ����, ����, ���� ���
	void showFoodDetail();
};

