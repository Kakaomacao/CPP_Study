#pragma once


class Member
{
private:
	string id;
	string password;
	string membership;
	int point;
	int memberPoint;
	static int memberCount;

public:
	Member();
	bool isAdmin();
	void setMS(int count);
	void showMemberInfo();
};

int Member::memberCount = 0;