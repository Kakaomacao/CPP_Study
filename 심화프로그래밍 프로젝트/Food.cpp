#include <iostream>
using namespace std;

#include "Food.h"
#include "member.h"

Food::Food(int price, string name)
{
	this->price = price;
	this->name = name;
	rate = rand() % 5;
	detail = "별미 중의 별미로 남녀노소 모두에게 사랑받는 음식";
}

//-------------------------------------------------------------------

string Food::getFoodName()
{
	return name;
}

//-------------------------------------------------------------------

void Food::showFoodDetail()
{
	cout << this->name << endl;
	cout << "별점 : " << this->rate << " ";

	if (this->rate == 5)
	{
		cout << "*****" << endl;
	}

	else if (this->rate >= 4 && this->rate < 5)
	{
	cout << "****" << endl;
	}

	else if (this->rate >= 3 && this->rate < 4)
	{
		cout << "***" << endl;
	}

	else if (this->rate >= 2 && this->rate < 3)
	{
		cout << "**" << endl;
	}

	else if (this->rate >= 1 && this->rate < 2)
	{
		cout << "*" << endl;
	}

	else
	{
		cout << endl;
	}

	cout << "설명 : " << this->detail << endl;

}


//-------------------------------------------------------------------

void Food::showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3])
{
	int cmd;
	string input1, input2;
	int input3, input4;

	cout << endl << "********************************" << endl;
	cout << "<음식 메뉴>" << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << (i * 3) + (j + 1) << ". " << foods[i][j].getFoodName() << "	";
		}

		cout << endl;
	}

	cout << "음식을 선택해주세요 >> ";
	cin >> cmd;
	
	int a = cmd / 3;
	int b = cmd % 3 - 1;

	curFood = &foods[a][b];

	cout << endl;
	cout << curFood->getFoodName() <<"가(이) 선택되었습니다." << endl;
	cout << "1번 주문하기(회원 전용) / 2번 음식 설명 보기" << endl;
	cout << ">> ";
	cin >> cmd;

	switch (cmd)
	{
	case 1:
	{
		if (curMember->isNonMember())
		{
			cout << "회원이 아닙니다. 로그인을 해주세요." << endl;
			break;
		}

		cout << "<주문하기>" << endl;
		cout << "1번 포장 / 2번 배달" << endl << ">> ";
		cin >> input3;

		cout << "주문할 수량을 입력하세요 : ";
		cin >> input4;

		a = input3 / 3;
		b = input3 % 3 - 1;

		carts[a][b] = Cart(input4, input3, curFood);

		cout << curFood->getFoodName() << "가(이) " << carts[a][b].getNumber() << "개가 장바구니에 담겼습니다.";
		carts[a][b].setTotalPrice(foods[a][b].price * carts[a][b].getNumber());		

		break;
	}

	case 2:
	{
		cout << "<음식 설명 보기>" << endl;
		curFood->showFoodDetail();
		break;
	}

	default:
		break;
	}

	// 선택한 음식으로 설정 후 포장 + 배달 -> 장바구니 담기 -> 결제
}
