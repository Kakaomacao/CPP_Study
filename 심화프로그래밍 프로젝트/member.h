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
	
	int getPoint();
	// �� ȸ������ �Ѱ��ִ� �Լ�
	int getMemberCount();
	
	void setPoint(int p);
	// ���� �̱���
	void setMS(int count);
	void showMemberInfo();

	// �� Ŭ�������� �������� �ʾƵ� �ǵ��� static����
	// ȸ�� ���� �޴�
	static void showMemberMenu(Member* curMember, Member members[]);
	// �α��� �Լ�
	static void login(Member*& curMember, Member members[]);
};
