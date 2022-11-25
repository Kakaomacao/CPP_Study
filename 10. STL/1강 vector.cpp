#include <iostream>
using namespace std;
#include <vector>;

// 오늘의 주제 : vector

int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조 / 알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structrue)

	// vector (동적 배열)
	// - vector의 동작 원리 (size, capacity)
	// - 중간 삽입/삭제
	// - 처음과 끝 삽입/삭제
	// - 임의 접근

	// 배열
	// 단점 - 크기를 유동적으로 바꾸기 어려움!!
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	for (int i = 0; i < MAX_SIZE; i++)
		arr[i] = i;

	for (int i = 0; i < MAX_SIZE; i++)
		cout << arr[i] << endl;


	// 동적 배열 
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// Q1. 여유분은 얼만큼이 적당할까?
	// Q2. 증설을 얼만큼 해야 할까?
	// Q3. 기존의 데이터를 어떻게 처리할까?

	// [ 1 2 3 4 5 ][         ]
	// [ 1 2 3 4 5                        ] -> 집을 이사하는 느낌으로 데이터를 옮겨서 새로 만들어줌

	vector<int> v(1000, 0); // 선언하면서 크기 설정도 가능 + 초기값도 설정가능
	vector<int> v2 = v;

	// [                            ]
	// v.resize(1000); // -> 사이즈를 처음부터 1000개로 설정, 따라서 capacity도 저절로 1000부터
	cout << v.size() << " " << v.capacity() << endl;
	// size (실제 사용 데이터 개수)
	// 1 2 3 4 5 6 ...
	
	// v.reserve(1000); // -> 처음부터 1000개짜리로 시작
	// capacity (여유분을 포함한 용량 개수)
	// 1 2 3 4 6 9 13 19 28 42 63 
	// 대략적으로 1.5배 해주고 있음을 알 수 있음 -> 컴파일러마다 차이
	// capacity를 키우며 발생하는 복사 비용 등으로 인해서 reserve를 이용하여 처음부터 설정하여 효율을 높일 수 있음

	for (int i = 0; i < 1001; i++)
	{
		// v[i] = 100;
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.back();	// 마지막 데이터 확인
	v.pop_back(); // 마지막 데이터 꺼내기
	v.front(); // 첫 번째 데이터 확인

	v.clear();
	vector<int>().swap(v);
	cout << v.size() << " " << v.capacity() << endl;

	const int size = v.size();
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}