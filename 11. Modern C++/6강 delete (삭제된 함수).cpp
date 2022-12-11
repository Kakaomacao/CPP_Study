#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 오늘의 주제 : delete (삭제된 함수)

class Knight
{
public:
	
public:
	void operator=(const Knight& k) = delete;
	// 사용하려하면 빌드부터 에러 메세지 출력

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKight(const Knight& k)
	{
		Knight k1;

		// 복사 연산
		// k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// 복사 연산자
	// k1 = k2;

	// Admin admin;
	// admin.CopyKight(k1);

	return 0;
}