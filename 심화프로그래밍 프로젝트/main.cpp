#include <iostream>
using namespace std;

#include "member.h"
int Member::memberCount = 0;

#include "Food.h"

int main()
{
	srand(time(NULL));

	int cmd;
	Member members[20];
	members[0] = Member("Admin", "Admin");
	Member* curMember = new Member();

	Food foods[4][3] = { {Food(1000, "불고기뚝배기"), Food(2000, "쌈밥정식"), Food(3000, "곱창전골")},
		{Food(4000, "자장면"), Food(5000, "볶음밥"), Food(6000, "짬뽕")},
		{Food(7000, "초밥정식"), Food(8000, "튀김우동"), Food(9000, "모둠 회")},
		{Food(10000, "양념치킨"), Food(11000, "포테이토 피자"), Food(12000, "불고기버거")} };
	Food* curFood = nullptr;

	do {
		cout << endl << "********************************" << endl;
		cout << "<메뉴 선택>" << endl;
		cout << "1. 회원 관리" << endl;
		cout << "2. 음식 메뉴" << endl;
		cout << "3. 로그인" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "입력 >> ";

		cin >> cmd;

		switch (cmd)
		{
		case 1:
			Member::showMemberMenu(curMember, members);
			break;

		case 2:
			Food::showFoodMenu(curFood, foods);
			break;

		case 3:
			Member::login(curMember, members);
			break;

		case 0:
			break;

		default:
			cout << "유효하지 않은 선택입니다." << endl;
			break;
		}

	} while (cmd != 0);

	return 0;
}
