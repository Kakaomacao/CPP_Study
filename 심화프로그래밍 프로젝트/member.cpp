#include <iostream>
using namespace std;

#include "member.h"

Member::Member()
{
	id = "";
	password = "";
	membership = "비회원";
	point = 0;
	memberPoint = 0;
}

Member::Member(string id = "", string pw = "")
{
	this->id = id;
	password = pw;
	membership = "Bronze";
	point = 0;
	memberPoint = 0;
}

//-------------------------------------------------------------------

bool Member::isNonMember()
{
	if (this->membership == "비회원")
		return true;

	else
		return false;
}

//-------------------------------------------------------------------

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

int Member::getMemberCount()
{
	return memberCount;
}

//-------------------------------------------------------------------

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
	case 1:
		memberCount++;
		cout << endl << "<회원 가입>" << endl;
		cout << "아이디를 입력하세요." << endl << ">> ";
		cin >> input1;
		cout << "비밀번호를 입력하세요." << endl << ">> ";
		cin >> input2;
		members[memberCount] = Member(input1, input2);
		break;

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

				}

				memberCount--;
			}

			else
			{
				cout << "회원 탈퇴를 취소하셨습니다." << endl;
			}
		}
		break;

	case 3:
		cout << endl << "<등급 확인>" << endl;
		cout << "Bronze		~3	5% 할인" << endl
			 << "Silve		~5	8% 할인" << endl
			 << "Gold		~9	10% 할인" << endl
			 << "Platinum	10이상	15% 할인" << endl;
		cout << "현재 등급은 " << curMember->membership << "입니다." << endl;
		break;

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

	case 5:
		if (curMember->isAdmin())
		{
			for (int i = 1; i <= memberCount; i++)
			{
				cout << members[i].id << " " << members[i].password << endl;
			}
		}

		else
		{
			cout << "관리자가 아닙니다." << endl;
		}
		break;

	default:
		cout << "잘못된 입력입니다." << endl;
		break;
	}
}

//-------------------------------------------------------------------

void Member::login(Member*& curMember, Member members[])
{
	string input1, input2;
	bool approval = false;

	cout << endl << "<로그인>" << endl;
	cout << "아이디를 입력하세요 : ";
	cin >> input1;
	cout << "비밀번호를 입력하세요 : ";
	cin >> input2;

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