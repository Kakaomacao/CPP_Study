#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제1) 문자열 길이를 출력하는 함수
int Strlen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int i = 0;

	while (str[i] != '\0')
		i++;

	return i;
}

// 문제2) 문자열 복사 함수
char* StrCpy(char* dest, char* src)
{
	// 인덱스 이용 버전
	/*int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	
	dest[i] = '\0';

	return dest;*/


	// 포인터 버전
	char* ret = dest; // 초기값

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}

// 문제3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{

}

#pragma warning(disable: 4996)	// strcpy() 쓰게 해줌

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o][\0][][][][][][][]...
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	// int len = sizeof(a);
	// cout << len << endl;	// 100이 출력됨 그냥 a의 크기가 출력

	// int len2 = strlen(a);
	// cout << len2 << endl;	// 5가 출력됨 \0 빼고 계산

	// strcpy(b, a);
	// StrCpy(b, a);

	strcat(a, b);

	return 0;
}