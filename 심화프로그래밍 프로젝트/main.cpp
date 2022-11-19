#include <iostream>
using namespace std;

#include "member.h"
int Member::memberCount = 0;

#include "Food.h"

#include "Cart.h"
int Cart::totalPrice = 0;

void showMemberMenu(Member* curMember, Member members[]);
void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3]);
void login(Member*& curMember, Member members[]);
void showCart(Member* curMember, Cart carts[][3]);

int main()
{
	srand(time(NULL));

	int cmd;
	Member members[20];
	members[0] = Member("Admin", "Admin");
	Member* curMember = new Member();

	Food foods[4][3] = { Food(1000, "뚝배기불고기"), Food(2000, "쌈밥정식"), Food(3000, "곱창전골"),
		Food(4000, "자장면"), Food(5000, "볶음밥"), Food(6000, "짬뽕"),
		Food(7000, "초밥정식"), Food(8000, "튀김우동"), Food(9000, "모둠 회"),
		Food(10000, "양념치킨"), Food(11000, "피자"), Food(12000, "불고기버거") };
	Food* curFood = nullptr;

	Cart carts[4][3];

	do {
		cout << endl << "********************************" << endl;
		cout << "<메뉴 선택>" << endl;
		cout << "1. 회원 관리" << endl;
		cout << "2. 음식 메뉴" << endl;
		cout << "3. 로그인" << endl;
		cout << "4. 장바구니" << endl;
		cout << "0. 프로그램 종료" << endl;
		cout << "입력 >> ";
		cin >> cmd;

		switch (cmd)
		{
		case 1:
			showMemberMenu(curMember, members);
			break;

		case 2:
			showFoodMenu(curMember, curFood, foods, carts);
			break;

		case 3:
			login(curMember, members);
			break;

		case 4:
			showCart(curMember, carts);

		case 0:
			break;

		default:
			cout << "유효하지 않은 선택입니다." << endl;
			break;
		}

	} while (cmd != 0);

	return 0;
}

// 회원 관리 메뉴 -> 5가지 기능 포함
void showMemberMenu(Member* curMember, Member members[])
{
	int cmd;
	int input;
	string input1, input2;

	cout << endl << "********************************" << endl;
	cout << "<회원 관리>" << endl;
	cout << "1. 회원 가입" << endl;
	cout << "2. 회원 탈퇴" << endl;
	cout << "3. 등급 확인" << endl;
	cout << "4. 포인트충전" << endl;
	cout << "5. 회원 목록 (관리자 전용)" << endl;
	cout << "입력 >> ";
	cin >> cmd;

	switch (cmd)
	{
		// 회원 가입
	case 1:
		curMember->setMemberCount(curMember->getMemberCount() + 1);
		cout << endl << "<회원 가입>" << endl;
		cout << "아이디를 입력하세요." << endl << ">> ";
		cin >> input1;
		cout << "비밀번호를 입력하세요." << endl << ">> ";
		cin >> input2;
		members[curMember->getMemberCount()] = Member(input1, input2);
		break;

		// 회원 탈퇴
	case 2:
		cout << endl << "<회원 탈퇴>" << endl;
		if (curMember->isNonMember())
		{
			cout << "회원이 아닙니다." << endl;
			break;
		}

		else
		{
			// 아이디 삭제 && 멤버 땡기기
			cout << endl << "<회원 탈퇴>" << endl;
			cout << "정말로 계정 " << curMember->getId() << "를 삭제하시겠습니까 ? " << endl;
			cout << "1) 예 2) 아니오" << endl;
			cout << ">> ";
			cin >> input;

			if (input == 1)
			{
				for (int i = 1; i < curMember->getMemberCount(); i++)
				{
					// 한칸씩 땡기기 미구현
				}

				curMember->setMemberCount(curMember->getMemberCount() - 1);
			}

			else
			{
				cout << "회원 탈퇴를 취소하셨습니다." << endl;
			}
		}
		break;

		// 등급 확인
	case 3:
		cout << endl << "<등급 확인>" << endl;
		cout << "Bronze		~3	5% 할인" << endl
			<< "Silver		~5	8% 할인" << endl
			<< "Gold		~9	10% 할인" << endl
			<< "Platinum	10이상	15% 할인" << endl;
		cout << "현재 등급은 " << curMember->getMembership() << "입니다." << endl;
		break;

		// 포인트 충전 (회원인 경우에만 가능)
	case 4:
		cout << endl << "<포인트 충전>" << endl;
		if (curMember->isNonMember())
		{
			cout << "회원이 아닙니다." << endl;
			break;
		}

		else
		{
			cout << "충전할 포인트를 입력해주세요 (1000원 단위) : ";
			cin >> input;

			if (input % 1000 == 0)
			{
				cout << "충전을 완료하였습니다." << endl;
				cout << "현재 잔여 포인트는 " << curMember->getPoint() + input << endl;
			}

			else
			{
				cout << "유효하지 않은 금액입니다." << endl;
			}
		}
		break;

		// 회원 목록 보기 (Admin인 경우에만 가능)
	case 5:
		if (curMember->isAdmin())
		{
			for (int i = 1; i <= curMember->getMemberCount(); i++)
			{
				cout << members[i].getId() << " " << members[i].getPassword() << endl;
			}

			cout << "총 회원은 " << curMember->getMemberCount() << "명 입니다." << endl;
		}

		else
		{
			cout << "관리자가 아닙니다." << endl;
		}
		break;

		// 다른 커맨드 입력시 메세지 출력
	default:
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}

//-------------------------------------------------------------------

// 음식 메뉴 
void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3])
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
	cout << curFood->getFoodName() << "가(이) 선택되었습니다." << endl;
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

		carts[a][b] = Cart(input4, input3, curFood);

		cout << curFood->getFoodName() << "가(이) " << carts[a][b].getNumber() << "개가 장바구니에 담겼습니다.";
		carts[a][b].setTotalPrice(foods[a][b].getPrice() * carts[a][b].getNumber());

		cout << "장바구니로 이동하여 주문을 마쳐주세요~" << endl;

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
}

//-------------------------------------------------------------------

// 로그인 메뉴
void login(Member*& curMember, Member members[])
{
	// 입력을 위한 string 변수 2개와 로그인 성공 여부 확인을 위한 bool 변수
	string input1, input2;
	bool approval = false;

	cout << endl << "<로그인>" << endl;
	cout << "아이디를 입력하세요 : ";
	cin >> input1;
	cout << "비밀번호를 입력하세요 : ";
	cin >> input2;

	// 회원 목록에서 동일한 id를 찾은 경우에 한해서 password 비교
	// 둘 다 일치하는 경우에만 승인을 true로 전환하고 현재 멤버를 가리키는 포인터 변경
	for (int i = 0; i <= curMember->getMemberCount(); i++)
	{
		if (input1 == members[i].getId())
		{
			if (input2 == members[i].getPassword())
			{
				cout << "로그인에 성공하였습니다." << endl;
				curMember = &members[i];
				approval = true;
			}
		}
	}

	if (!approval)
		cout << "로그인에 실패하였습니다." << endl;

}

//-------------------------------------------------------------------

// 장바구니 메뉴
void showCart(Member* curMember, Cart carts[][3])
{
	int input;

	if (carts[0][0].getTotalPrice() == 0)
	{
		cout << "장바구니가 비어있습니다." << endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (carts[i][j].getNumber() != 0)
			{
				cout << carts[i][j].food->getFoodName() << " : " << carts[i][j].getNumber() << "개를 ";

				if (carts[i][j].getState() == 1)
					cout << "포장 주문" << endl;
				else if (carts[i][j].getState() == 2)
					cout << "배달 주문" << endl;
			}
		}
	}

	cout << "1) 주문 2) 나가기" << endl << ">> ";
	cin >> input;

	int discountedPrice = Cart::discountByMembership(curMember);

	if (input == 1)
	{
		if (curMember->getPoint() >= discountedPrice)
		{
			cout << "총 주문 금액은 " << discountedPrice << "(원)입니다." << endl;
			cout << "예상 주문 소요 시간은 " << rand() % 50 + 10 << "분입니다." << endl;
			cout << "주문해주셔서 감사합니다~!" << endl;

			curMember->setMS(discountedPrice);
			curMember->setPoint(curMember->getPoint() - discountedPrice);
			curMember->setMS(discountedPrice);

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 3; j++)
					carts[i][j].emptyCart();

			carts[0][0].setTotalPrice(0);
		}

		else
		{
			cout << "잔액이 부족합니다!! 충전 후 주문해주세요~" << endl;
		}
	}
}