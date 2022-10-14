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
		// ���� �а� �� entry ����, �� ���� ���� �ִ��� ���
		case 'R': case 'r':
			info.openFile();
			info.printEntryCount();
			info.countMonth();
			info.printMonth();
			break;

		// ���ο� entry �߰�
		case '+':
			info.addEntry();
			info.printEntryCount();
			info.printMonth();
			break;

		// ���� entry ����
		case '-':
			break;

		case 'W': case 'w':
			break;

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