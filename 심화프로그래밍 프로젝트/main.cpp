#include <iostream>
using namespace std;

#include "Member.h"
// static 변수인 총 회원수 초기화
int Member::memberCount = 0;

#include "Food.h"

#include "Cart.h"
// static 변수인 총 금액 초기화
int Cart::totalPrice = 0;

#define MAX_MEMBERS 20

// 메뉴 관련 함수들 선언
void showMemberMenu(Member*& curMember, Member members[]);
void showFoodMenu(Member* curMember, Food* curFood, Food foods[][3], Cart carts[][3]);
void login(Member*& curMember, Member members[]);
void logout(Member*& curMember);
void showCart(Member* curMember, Cart carts[][3]);

int main()
{
	// 별점을 rand로 선언했기 때문에 seed값 설정
	srand(time(NULL));

	// 입력 받기 위한 변수 cmd
	int cmd;
	
	// 총 회원수는 최대 20
	Member members[MAX_MEMBERS + 1];
	// 0번 회원은 관리자로 고정
	members[0] = Member("Admin", "Admin");
	// 로그인하지 않은 상태의 처음 회원은 비회원
	Member* curMember = new Member();

	// 총 음식은 12개로 고정하고 2차원 배열로 구현
	Food foods[4][3] = { Food(1000, "뚝배기불고기"), Food(2000, "쌈밥정식"), Food(3000, "곱창전골"),
		Food(4000, "자장면"), Food(5000, "볶음밥"), Food(6000, "짬뽕"),
		Food(7000, "초밥정식"), Food(8000, "튀김우동"), Food(9000, "모둠 회"),
		Food(10000, "양념치킨"), Food(11000, "피자"), Food(12000, "불고기버거") };
	// 맨 처음에 선택된 음식은 없다
	Food* curFood = nullptr;

	// 12개인 음식에 대응되도록 장바구니도 2차원 배열로 구현
	Cart carts[4][3];

	do {
		cout << endl << "********************************" << endl;
		cout << "<메뉴 선택>" << endl;
		cout << "1. 회원 관리" << endl;
		cout << "2. 음식 메뉴" << endl;
		cout << "3. 로그인" << endl;
		cout << "4. 로그아웃" << endl;
		cout << "5. 장바구니" << endl;
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
			logout(curMember);
			break;

		case 5:
			showCart(curMember, carts);
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

// 메뉴 관련 함수들 구현

// 회원 관리 메뉴 -> 5가지 기능 포함
void showMemberMenu(Member*& curMember, Member members[])
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
			cout << "정말로 계정 " << curMember->getId() << "를 삭제하시겠습니까 ? " << endl;
			cout << "1) 예 2) 아니오" << endl;
			cout << ">> ";
			cin >> input;

			string name = curMember->getId();

			if (input == 1)
			{
				for (int i = 1; i < curMember->getMemberCount(); i++)
				{
					if (members[i].getId() == name)
					{
						delete curMember;

						for (int j = i; j < members[0].getMemberCount() - 1; j++)
						{

							members[j] = members[j + 1];
						}
						
						break;
					}
				}

				curMember = new Member();
				members[0].setMemberCount(members[0].getMemberCount() - 1);
				cout << "회원 탈퇴하였습니다." << endl;
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
		cout << "현재 회원 포인트는 " << curMember->getMemberPoint() << "점입니다. " << endl;
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
			cout << "충전할 포인트를 입력해주세요 (1000원 단위) (잔액 확인은 0 입력) >>";
			cin >> input;

			if (input % 1000 == 0)
			{
				curMember->setPoint(input);
				cout << "충전을 완료하였습니다." << endl;
				cout << "현재 잔여 포인트는 " << curMember->getPoint() << endl;
			}

			else
			{
				cout << "유효하지 않은 금액입니다." << endl;
			}
		}
		break;

		// 회원 목록 보기 (Admin인 경우에만 가능)
	case 5:
		cout << "<회원 목록 보기>" << endl;

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

		cout << curFood->getFoodName() << "가(이) " << carts[a][b].getNumber() << "개가 장바구니에 담겼습니다." << endl;
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

	// memory leak 방지
	if (curMember->isNonMember())
		delete curMember;

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

// 로그아웃 메뉴
void logout(Member*& curMember)
{
	cout << "<로그아웃>" << endl;

	if (curMember->isNonMember())
	{
		cout << "로그인 상태가 아닙니다." << endl;
		return;
	}

	curMember = new Member();

	cout << "정상적으로 로그아웃 되었습니다." << endl;
}

//-------------------------------------------------------------------

// 장바구니 메뉴
void showCart(Member* curMember, Cart carts[][3])
{
	cout << "<장바구니>" << endl;

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

	int discountedPrice = Cart::discountByMembership(curMember);

	cout << "현재 포인트 잔액은 " << curMember->getPoint() << "원입니다." << endl;
	cout << "장바구니에 담긴 금액은 " << discountedPrice << "원입니다." << endl;
	cout << "1) 주문 2) 나가기" << endl << ">> ";
	cin >> input;

	if (input == 1)
	{
		if (curMember->getPoint() >= discountedPrice)
		{
			cout << "총 주문 금액은 " << discountedPrice << "(원)입니다." << endl;
			cout << "예상 주문 소요 시간은 " << rand() % 50 + 10 << "분입니다." << endl;
			cout << "주문해주셔서 감사합니다~!" << endl;

			curMember->setPoint(curMember->getPoint() - discountedPrice);
			curMember->setMS(discountedPrice);

			cout << "구매 후 잔액은 " << curMember->getPoint() << "원입니다." << endl;

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