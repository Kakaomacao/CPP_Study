#include <iostream>
using namespace std;

int main()
{
	// 별찍기
	// 유저들이 어떤 정수를 입력하면
	// n * n 개의 별을 찍었으면 좋겠어요!

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// 별찍기 (2)
	// 음,, 그냥 n * n 개의 별을 찍으니까 너무 심심하다.
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 해주세요!

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// 별찍기 (3)
	// 모양이 많이 개선되긴 했는데
	// n개부터 시작해서 줄마다 1개씩 줄어드는 형태로!

	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}


	// 구구단
	// 2 * 1 = 2
	// 2단부터 9단까지 구구단을 출력해주세요

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
}