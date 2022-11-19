#include <iostream>
using namespace std;

#include "member.h"

// �⺻ ������
Member::Member()
{
	id = "";
	password = "";
	membership = "��ȸ��";
	point = 0;
	memberPoint = 0;
}

// string�� ���� 2���� ���̵�, ��й�ȣ�� �Է¹޴� ������
// �� ��, ȸ�� ������ ����Ǹ� ȸ�� ����� Bronze�� ����
Member::Member(string id = "", string pw = "")
{
	this->id = id;
	password = pw;
	membership = "Bronze";
	point = 0;
	memberPoint = 0;
}

//-------------------------------------------------------------------

// ȸ������� ���ؼ� ȸ������ ��ȸ������ �Ǵ�
// ��ȸ���� ��쿡 true ��ȯ
bool Member::isNonMember()
{
	if (this->membership == "��ȸ��")
		return true;

	else
		return false;
}

//-------------------------------------------------------------------

// ���̵� Admin�̸� �����ڷ� �Ǵ�
// Admin�� ��� true ��ȯ
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

