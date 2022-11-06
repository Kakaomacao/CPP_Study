#include <iostream>
using namespace std;

#include "member.h"

int main()
{
	int cmd;
	Member* curMember = new Member();

	do {
		cout << "********************************" << endl;
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
			break;

		case 2:
			break;

		case 3:
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