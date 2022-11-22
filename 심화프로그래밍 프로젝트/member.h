#pragma once

class Member
{
private:
	// 아이디와 비밀번호
	string id;
	string password;
	// 회원 등급
	string membership;
	// 구매를 위한 포인트
	int point;
	// 회원 등급을 위한 포인트
	int memberPoint;
	// 총 회원 수
	static int memberCount;

public:
	// 생성자
	Member();
	Member(string id, string pw);

	// 회원인지 비회원인지 체크하는 함수
	bool isNonMember();
	// 관리자인지 아닌지 체크하는 함수
	bool isAdmin();
	
	// get 함수들
	string getId();
	string getPassword();
	string getMembership();
	int getPoint();
	int getMemberPoint();
	int getMemberCount();
	
	// set 함수들
	void setMemberCount(int n);
	void setPoint(int p);
	void setMS(int count);
};
