#pragma once

class Food
{
private:
	// 가격, 평점, 설명, 음식 이름에 대한 변순
	int price;
	double rate;
	string detail;
	string name;

public:
	// 가격, 이름을 매개변수로 받는 생성자
	Food(int price, string name);

	// get 함수
	int getPrice();
	string getFoodName();

	// 음식의 이름, 별점, 가격, 설명 출력
	void showFoodDetail();
};

