#include <iostream>
using namespace std;

// ������ ���� : ���� ����

// ����1) ���ڿ� ���̸� ����ϴ� �Լ�
int Strlen(const char* str)
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

}

#pragma warning(disable: 4996)	// strcpy() ���� ����

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o][\0][][][][][][][]...
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	// int len = sizeof(a);
	// cout << len << endl;	// 100�� ��µ� �׳� a�� ũ�Ⱑ ���

	// int len2 = strlen(a);
	// cout << len2 << endl;	// 5�� ��µ� \0 ���� ���

	// strcpy(b, a);
	// StrCpy(b, a);

	strcat(a, b);

	return 0;
}