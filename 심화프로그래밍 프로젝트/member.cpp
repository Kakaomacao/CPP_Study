#include <iostream>
using namespace std;

#include "Member.h"

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
Member::Member(string id, string pw)
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

// get �Լ��� -> private�� Ŭ���� ������ ��ȯ

// ȸ���� ID�� ��ȯ���ִ� �Լ�
string Member::getId()
{
	return id;
}

// ȸ���� ��й�ȣ�� ��ȯ���ִ� �Լ�
string Member::getPassword()
{
	return password;
}

// ȸ���� ȸ�� ����� ��ȯ���ִ� �Լ�
string Member::getMembership()
{
	return membership;
}

// ȸ���� ����Ʈ �ܾ��� ��ȯ���ִ� �Լ�
int Member::getPoint()
{
	return point;
}

// ȸ�� ����Ʈ�� ��ȯ���ִ� �Լ�
int Member::getMemberPoint()
{
	return memberPoint;
}

// �� ȸ������ ��ȯ���ִ� �Լ�
int Member::getMemberCount()
{
	return memberCount;
}

//-------------------------------------------------------------------

// set �Լ��� -> private�� Ŭ���� ������ ����

// �� ȸ������ �������ִ� �Լ�
void Member::setMemberCount(int n)
{
	memberCount = n;
}

// �ݾ� ���� or ��� �Ŀ� Point�� �����ϱ� ���� �Լ�
void Member::setPoint(int p)
{
	point = p;
}

// ���� ���� ��������Ʈ�� ��� ��������Ʈ�� �翡 ���� ȸ�� ��� ����
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