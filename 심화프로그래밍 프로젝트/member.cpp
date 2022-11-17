#include <iostream>
using namespace std;

#include "member.h"

// 기본 생성자
Member::Member()
{
	id = "";
	password = "";
	membership = "비회원";
	point = 0;
	memberPoint = 0;
}

// string형 변수 2개를 아이디, 비밀번호로 입력받는 생성자
// 이 때, 회원 가입이 진행되며 회원 등급을 Bronze로 설정
Member::Member(string id = "", string pw = "")
{
	this->id = id;
	password = pw;
	membership = "Bronze";
	point = 0;
	memberPoint = 0;
}

//-------------------------------------------------------------------

// 회원등급을 통해서 회원인지 비회원인지 판단
// 비회원인 경우에 true 반환
bool Member::isNonMember()
{
	if (this->membership == "비회원")
		return true;

	else
		return false;
}

//-------------------------------------------------------------------

// 아이디가 Admin이면 관리자로 판단
// Admin인 경우 true 반환
bool Member::isAdmin()
{
	if (this->id == "Admin")
	{
		return true;
	}

	else
		return false;
}

//-------------------------------------------------------------------

int Member::getPoint()
{
	return point;
}

int Member::getMemberCount()
{
	return memberCount;
}

void Member::setPoint(int p)
{
	point = p;
}

//-------------------------------------------------------------------

// 회원 관리 메뉴 -> 5가지 기능 포함
// 매개변수로 현재 회원을 가리키는 Member*와 회원 목록인 members[] 배열
void Member::showMemberMenu(Member* curMember, Member members[])
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
		memberCount++;
		cout << endl << "<회원 가입>" << endl;
		cout << "아이디를 입력하세요." << endl << ">> ";
		cin >> input1;
		cout << "비밀번호를 입력하세요." << endl << ">> ";
		cin >> input2;
		members[memberCount] = Member(input1, input2);
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
			cout << "정말로 계정 " << curMember->id <<"를 삭제하시겠습니까 ? " << endl;
			cout << "1) 예 2) 아니오" << endl;
			cout << ">> ";
			cin >> input;

			if (input == 1)
			{
				for (int i = 1; i < memberCount; i++)
				{
					// 한칸씩 땡기기 미구현
				}

				memberCount--;
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
			 << "Silve		~5	8% 할인" << endl
			 << "Gold		~9	10% 할인" << endl
			 << "Platinum	10이상	15% 할인" << endl;
		cout << "현재 등급은 " << curMember->membership << "입니다." << endl;
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
				cout << "현재 잔여 포인트는 " << curMember->point + input << endl;
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
			for (int i = 1; i <= memberCount; i++)
			{
				cout << members[i].id << " " << members[i].password << endl;
			}

			cout << "총 회원은 " << memberCount << "명 입니다." << endl;
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

// 로그인 메뉴
void Member::login(Member*& curMember, Member members[])
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
	for (int i = 0; i <= memberCount; i++)
	{
		if (input1 == members[i].id)
		{
			if (input2 == members[i].password)
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