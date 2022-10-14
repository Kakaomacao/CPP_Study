#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
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
	/*int len = StrLen(dest);

	int i = 0;

	while (src[i] != '\0')
	{
		dest[len + i] = src[i];

		i++;
	}

	dest[len + i] = '\0';

	return dest;*/


	// 포인터 버젼
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

// 문제4) 두 문자열을 비교하는 함수
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

// 문제5) 문자열을 뒤집는 함수
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

#pragma warning(disable: 4996)	// strcpy() 쓰게 해줌

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o][\0][][][][][][][]...
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	int len = sizeof(a);
	cout << len << endl;	// 100이 출력됨 그냥 a의 크기가 출력

	int len2 = StrLen(a);
	cout << len2 << endl;	// 5가 출력됨 \0 빼고 계산

	// strcpy(b, a);
	StrCpy(b, a);

	StrCat(a, b);

	// if (a == b)
	// 다르다고 출력됨 -> 내용물이 같은거지 a와 b는 다른 주소!!
	// a == b는 주소를 비교하는거임
	int value = StrCmp(a, b);
	cout << value << endl;

	ReverseStr(a);
	cout << a << endl;

	return 0;
}