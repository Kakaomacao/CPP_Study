#include <iostream>
using namespace std;

// ������ ���� : ���� ����

// ����1) ���ڿ� ���̸� ����ϴ� �Լ�
int StrLen(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int i = 0;

	while (str[i] != '\0')
		i++;

	return i;
}

// ����2) ���ڿ� ���� �Լ�
char* StrCpy(char* dest, char* src)
{
	// �ε��� �̿� ����
	/*int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	
	dest[i] = '\0';

	return dest;*/


	// ������ ����
	char* ret = dest; // �ʱⰪ

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}

// ����3) ���ڿ� �����̴� �Լ�
char* StrCat(char* dest, char* src)
{
	/*int len = StrLen(dest);

	int i = 0;

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];

		i++;
	}

	dest[len + i] = '\0';

	return dest;*/


	// ������ ����
	char* ret = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

// ����4) �� ���ڿ��� ���ϴ� �Լ�
int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;

		if (a[i] < b[i])
			return -1;

		i++;
	}

	return 0;
}

// ����5) ���ڿ��� ������ �Լ�
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

#pragma warning(disable: 4996)	// strcpy() ���� ����

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o][\0][][][][][][][]...
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = sizeof(a);
	cout << len << endl;	// 100�� ��µ� �׳� a�� ũ�Ⱑ ���

	int len2 = StrLen(a);
	cout << len2 << endl;	// 5�� ��µ� \0 ���� ���

	// strcpy(b, a);
	StrCpy(b, a);

	StrCat(a, b);

	// if (a == b)
	// �ٸ��ٰ� ��µ� -> ���빰�� �������� a�� b�� �ٸ� �ּ�!!
	// a == b�� �ּҸ� ���ϴ°���
	int value = StrCmp(a, b);
	cout << value << endl;

	ReverseStr(a);
	cout << a << endl;

	return 0;
}