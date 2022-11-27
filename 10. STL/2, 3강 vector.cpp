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

	v.reserve(1000);

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

	// - 중간 삽입 / 삭제 (비효율적) -> 전부 밀거나 땡겨야함
	// - 처음 / 끝 삽입 / 삭제 (BAD / GOOD)
	// - 임의 접근 (Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다!!!

	// [                         ]
	// [0] [1] [2] [3] [4] [ ] [ ]

	// v.push_back(1);
	// v.pop_back();

	// vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5);
	// vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	// vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);

	// 쭉~ 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = *it;
		if (data == 3)
			it = v.erase(it); // 그냥 지워버리면 data외의 다른 정보들도 전부 날라가버려서 오류 발생
							  // 지우고나서 다음으로 넘어가기 때문에 else문에 ++it 작성
		else
			++it;
	}

	return 0;
}