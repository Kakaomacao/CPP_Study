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

string Member::getId()
{
	return id;
}

string Member::getPassword()
{
	return password;
}

int Member::getPoint()
{
	return point;
}

int Member::getMemberCount()
{
	return memberCount;
}

void Member::setMemberCount(int n)
{
	memberCount = n;
}

void Member::setPoint(int p)
{
	point = p;
}

string Member::getMembership()
{
	return membership;
}

void Member::setMS(int n)
{
	memberPoint += n / 1000;

	if (memberPoint >= 4 && memberPoint < 6)
		membership = "Silver";

	else if (memberPoint >= 5 && memberPoint < 9)
		membership = "Gold";

	else if (memberPoint >= 10)
		membership = "Platinum";
}


//-------------------------------------------------------------------

