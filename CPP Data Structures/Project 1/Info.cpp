#include "Info.h"

void info::openFile()

// ���ϸ��� �Է��Ͽ� ������ ���� entry �����ϴ� �Լ�

{
	string txtName;
	string line;
	int n = 0;

	cout << "Enter the name of the file : ";
	cin >> txtName;

	// .txt���� �ٿ��־�� �Ѵ�
	ifstream file(txtName + ".txt");

	// ������ ��� ���پ��� string �迭�� ����
	if (file.is_open()) {
		while (getline(file, line)) {
			// 4�پ� ���� 1���� �̸�, 2���� ��ȭ��ȣ, 3���� ����, 4���� ����X
			if (n % 4 == 0)
				entries[n / 4].setName(line);
			else if (n % 4 == 1)
				entries[n / 4].setPhoneNum(line);
			else if (n % 4 == 2)
				entries[n / 4].setBirthday(line);
			n++;
		}

		file.close(); // ������ ������ �ݴ´�. 
	}

	else {
		cout << "Unable to open file";
	}

	entryCount = (n / 4) + 1;
}

// ----------------------------------------------------------------

void info::exportEntries()

// ���ڿ��� �Է� �޾� txt�� �����Ͽ� entry�� ���� �Լ�

{
	string input;

	cout << "Enter the name of the file : ";
	cin >> input;
	
	ofstream outfile(input + ".txt");

	for (int i = 0; i < entryCount; i++)
	{
		outfile << entries[i].getName() << endl;
		outfile << entries[i].getPhoneNum() << endl;
		outfile << entries[i].getBirthday() << endl;
		outfile << endl;
	}

	cout << "The list is written into " << input;
	cout << endl;
}

// ----------------------------------------------------------------

void info::addEntry()

// ���ο� entry�� �߰��ϴ� �Լ�

{
	string str;

	cin.ignore(); // �����ִ� ���� ���۸� ����
	cout << "Name : ";
	getline(cin, str);
	entries[entryCount].setName(str);

	cout << "Phone : ";
	getline(cin, str);
	entries[entryCount].setPhoneNum(str);

	cout << "Birthday : ";
	getline(cin, str);
	entries[entryCount].setBirthday(str);

	entryCount++;
}

// ----------------------------------------------------------------

void info::deleteEntry()

// ������ entry�� �������ִ� �Լ�

{
	string input;

	cin.ignore(); // �����ִ� ���� ���۸� ����
	cout << "Remove an entry" << endl;
	cout << "Name : ";
	getline(cin, input);

	for (int i = 0; i < entryCount; i++)
	{
		if (strcmp(input.c_str(), entries[i].getName().c_str()) == 0)
		{
			for (int j = 0; j < entryCount - i - 1; j++)
			{
				// entries[j] = entries[j + 1] ���� (���� �� �Ű�)
				entries[j].setName(entries[j + 1].getName());
				entries[j].setPhoneNum(entries[j + 1].getPhoneNum());
				entries[j].setBirthday(entries[j + 1].getBirthday());
			}

			entryCount--;
		}
	}

}

// ----------------------------------------------------------------

void info::countMonth()

// ���� entry���� ������ Ȯ���Ͽ� ���� �޿� �� ���� �ִ��� ���ִ� �Լ�

{
	for (int i = 0; i < 12; i++)
	{
		month[i].number = 0;
	}

	for (int i = 0; i < entryCount; i++)
	{
		switch (entries[i].getMonth())
		{
		case 1:
			month[0].number++;
			break;
		case 2:
			month[1].number++;
			break;
		case 3:
			month[2].number++;
			break;
		case 4:
			month[3].number++;
			break;
		case 5:
			month[4].number++;
			break;
		case 6:
			month[5].number++;
			break;
		case 7:
			month[6].number++;
			break;
		case 8:
			month[7].number++;
			break;
		case 9:
			month[8].number++;
			break;
		case 10:
			month[9].number++;
			break;
		case 11:
			month[10].number++;
			break;
		case 12:
			month[11].number++;
			break;
		}
	}
}

// ----------------------------------------------------------------

void info::printCountAndMonth()

// ���� entry ���� entry �� ������� ���� �޿� �� ���� �ִ��� ����ϴ� �Լ�

{
	cout << "Total number of entries in the list : " << entryCount << endl;

	countMonth();

	cout << "Number of birthdays in" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (month[i].number != 0)
			cout << "	" << month[i].getName() << " : " << month[i].number << endl;
	}
}

// ----------------------------------------------------------------

void info::printSelectedMonth()

// �Է��� �޿� �� ���� �ִ��� ����ϰ� �� ������� entry�� ����ϴ� �Լ�

{
	char input[15];

	countMonth();

	cout << "Enter the selected month : ";
	cin >> input;

	for (int i = 0; i < 12; i++)
	{
		if (strcmp(input, month[i].getName().c_str()) == 0)
		{
			cout << "Total number of birthdays in " << month[i].getName() 
				<< " : " << month[i].number << endl;

			for (int j = 0; j < entryCount; j++)
			{
				if (strcmp(input, entries[j].getNameMonth().c_str()) == 0)
					entries[j].printEntry();
			}
		}
	}
}