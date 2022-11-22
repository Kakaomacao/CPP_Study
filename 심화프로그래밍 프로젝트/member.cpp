#include <iostream>
using namespace std;

#include "Member.h"

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
Member::Member(string id, string pw)
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

// get 함수들 -> private인 클래스 변수들 반환

// 회원의 ID를 반환해주는 함수
string Member::getId()
{
	return id;
}

// 회원의 비밀번호를 반환해주는 함수
string Member::getPassword()
{
	return password;
}

// 회원의 회원 등급을 반환해주는 함수
string Member::getMembership()
{
	return membership;
}

// 회원의 포인트 잔액을 반환해주는 함수
int Member::getPoint()
{
	return point;
}

// 회원 포인트를 반환해주는 함수
int Member::getMemberPoint()
{
	return memberPoint;
}

// 총 회원수를 반환해주는 함수
int Member::getMemberCount()
{
	return memberCount;
}

//-------------------------------------------------------------------

// set 함수들 -> private인 클래스 변수들 수정

// 총 회원수를 수정해주는 함수
void Member::setMemberCount(int n)
{
	memberCount = n;
}

// 금액 충전 or 사용 후에 Point를 수정하기 위한 함수
void Member::setPoint(int p)
{
	point = p;
}

// 구매 이후 구매포인트를 얻고 구매포인트의 양에 따라서 회원 등급 수정
void Member::setMS(int n)
{
	memberPoint += n / 10000;

	if (memberPoint >= 4 && memberPoint < 6)
		membership = "Silver";

	else if (memberPoint >= 5 && memberPoint < 9)
		membership = "Gold";

	else if (memberPoint >= 10)
		membership = "Platinum";
}