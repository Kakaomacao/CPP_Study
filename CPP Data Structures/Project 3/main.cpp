#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

#include "Person.h"

int main()
{
	Hierarchy h;

	string arr[3];
	string input;

	while (true)
	{
		int cnt = 0;

		getline(cin, input);

		char* str_buff = new char[1000];

		strcpy(str_buff, input.c_str());

		char* tok = strtok(str_buff, " ");

		while (tok != nullptr)
		{
			arr[cnt++] = string(tok);
			tok = strtok(nullptr, " ");
		}

		// print 입력시 트리 출력
		if (arr[0] == "Print" || arr[0] == "print")
		{
			h.print();
		}

		else if(arr[0] == "Fire" || arr[0] == "fire")
		{
			h.fire(arr[1]);
		}

		else
		{
			if (arr[1] == "hires")
			{
				h.hire(arr[0], arr[2]);
			}

			else
			{
				h.hire(arr[0], "");
			}
		}
	}

	return 0;
}