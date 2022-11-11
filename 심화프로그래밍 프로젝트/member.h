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
	Member(string id, string pw);

	bool isNonMember();
	bool isAdmin();
	
	int getMemberCount();
	void setMS(int count);
	void showMemberInfo();

	static void showMemberMenu(Member* curMember, Member members[]);
	static void login(Member*& curMember, Member members[]);
};
