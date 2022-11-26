#include <iostream>
using namespace std;
#include <vector>

// 오늘의 주제 : vector

int main()
{
	// 컨테이너 (Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size / capacity)
	// - 중간 삽입 / 삭제
	// - 처음 / 끝 삽입 / 삭제
	// - 임의 접근

	// 반복자 (Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		v[i] = i;

	//vector<int>::iterator it;
	//int* ptr;

	//it = v.begin();
	//ptr = &v[0];

	//cout << *it << endl;
	//cout << *ptr << endl;

	//int a = 1;
	//int b = a++; // b = 1, a = 2
	//int c = ++a; // c = 2, a = 2

	//it++;
	//++it;
	//ptr++;
	//++ptr;

	//it--;
	//--it;
	//ptr--;
	//--ptr;

	//it += 2;
	//it = it - 2;
	//ptr += 2;
	//ptr = ptr - 2;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();

	// 미세하게 ++it가 조금 더 성능 좋음
	// ++it하면 증가시키고 바로 리턴 / it++는 복사하고 늘리고 복사한 버젼 리턴
	// 더 복잡해보이는데?
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될수도 있음
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	int* ptrBegin = &v[0]; // v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << *ptr << endl;
	}

	// const int*;
	// vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1 = 100;

	// for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	// {
	//  	cout << *it << endl;
	// }

	return 0;
}