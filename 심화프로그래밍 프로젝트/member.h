#pragma once

class Member
{
private:
	// ���̵�� ��й�ȣ
	string id;
	string password;
	// ȸ�� ���
	string membership;
	// ���Ÿ� ���� ����Ʈ
	int point;
	// ȸ�� ����� ���� ����Ʈ
	int memberPoint;
	// �� ȸ�� ��
	static int memberCount;

public:
	// ������
	Member();
	Member(string id, string pw);

	// ȸ������ ��ȸ������ üũ�ϴ� �Լ�
	bool isNonMember();
	// ���������� �ƴ��� üũ�ϴ� �Լ�
	bool isAdmin();
	
	// get �Լ���
	string getId();
	string getPassword();
	string getMembership();
	int getPoint();
	int getMemberPoint();
	int getMemberCount();
	
	// set �Լ���
	void setMemberCount(int n);
	void setPoint(int p);
	void setMS(int count);
};
