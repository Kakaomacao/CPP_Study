#include <iostream>
using namespace std;

int a = 3;
int b = 4;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;

int main() 
{
	// ���� �ʿ��Ѱ�?
	// ex) ü���� 0�� �Ǹ� ���
	// ex) ü���� 30% �����̸� �ñر⸦ �ߵ� (100 * hp / maxHp)
	// ex) ����ġ�� 100 �̻��̸� ������

	// a == b : a�� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);

	// a != b : a�� b�� ���� �ٸ���?
	isDifferent = (a != b);

	// a > b : a�� b���� ū��?
	// a >= b : a�� b���� ũ�ų� ������?
	// 1 �ƴϸ� 0
	isGreater = (a > b);

	// a < b : a�� b���� ������?
	// a <= b : a�� b���� �۰ų� ������?
	// 1 �ƴϸ� 0
	isSmaller = (a < b);


	// �� ����
	// ���� �ʿ��Ѱ�? ���ǿ� ���� ���� ��� �ʿ��� ��
	// ex) �α����� �� ���̵� ���� AND ��й�ȣ�� ���ƾ� �Ѵ�.
	// ex) ��� �������̰ų� OR ��� �����̸� ��� �ػ� ����

	// ! nor
	// 0�̸� 1, �� �� 0
	test = !isSame;		// ��ǻ� isDifferent�� �ǹ�

	// && and
	// a && b -> �� �� 1�̸� 1, �� �� 0
	test = (hp <= 0 && isInvincible == false);	// ����

	// || or
	// a || b -> �� �� 0�̸� 0, �� �� 1 (�� �� �ϳ��� 1�̸� 1)
	test = (hp > 0 || isInvincible == true);	// �����
	}