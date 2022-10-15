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
		// ���� �о�鿩 �� entry ����, �� ���� ���� �ִ��� ���
		case 'R': case 'r':
			info.openFile();
			info.printCountAndMonth();
			break;

		// ���ο� entry �߰�
		case '+':
			info.addEntry();
			info.printCountAndMonth();
			break;

		// ���� entry ����
		case '-':
			info.deleteEntry();
			info.printCountAndMonth();
			break;

		// ���� entry���� ���Ϸ� ����
		case 'W': case 'w':
			info.exportEntries();
			break;

		// Ư�� �޿� ���� entry ���
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