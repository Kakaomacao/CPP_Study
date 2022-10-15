#include <iostream>
#include <fstream>
using namespace std;

#include "Info.h"

int main()
{
	info info;


	char cmd;
	cout << endl << "Commands:" << endl;
	cout << "  R : read from a file" << endl;
	cout << "  + : add a new entry" << endl;
	cout << "  - : remove an entry" << endl;
	cout << "  W : write to a file" << endl;
	cout << "  M : select a month" << endl;
	cout << "  Q : quit the program" << endl;
	
	
	do
	{
		cout << endl << "Command: ";
		cin >> cmd;

		switch (cmd)
		{
		// 파일 읽어들여 총 entry 갯수, 몇 월에 생일 있는지 출력
		case 'R': case 'r':
			info.openFile();
			info.printCountAndMonth();
			break;

		// 새로운 entry 추가
		case '+':
			info.addEntry();
			info.printCountAndMonth();
			break;

		// 기존 entry 제거
		case '-':
			info.deleteEntry();
			info.printCountAndMonth();
			break;

		// 지금 entry들을 파일로 저장
		case 'W': case 'w':
			info.exportEntries();
			break;

		// 특정 달에 대한 entry 출력
		case 'M': case 'm':
			info.printSelectedMonth();
			break;

		case 'Q': case 'q':
			break;

		default:
			cout << "Error::It is a wrong command." << endl;
			break;
		}

	} while (cmd != 'Q' && cmd != 'q');
}