#include "Info.h"

void info::openFile()
{
	string txtName;
	string line;
	int n = 0;

	cout << "Enter the name of the file : ";
	cin >> txtName;

	ifstream file(txtName + ".txt");

	// 파일을 열어서 한줄씩을 string 배열에 저장
	if (file.is_open()) {
		while (getline(file, line)) {
			// 4줄씩 끊기 1줄은 이름, 2줄은 전화번호, 3줄은 생일, 4줄은 빈줄
			if (n % 4 == 0)
				entries[n / 4].setName(line);
			else if (n % 4 == 1)
				entries[n / 4].setPhoneNum(line);
			else if (n % 4 == 2)
				entries[n / 4].setBirthday(line);
			n++;
		}

		file.close(); // 열었던 파일을 닫는다. 
	}

	else {
		cout << "Unable to open file";
	}

	entryCount = (n / 4) + 1;
}

void info::addEntry()
{
	string str;

	cout << "Name : ";
	cin >> str;
	entries[entryCount].setName(str);

	cout << "PhoneNumber : ";
	cin >> str;
	entries[entryCount].setPhoneNum(str);

	cout << "Birthday : ";
	cin >> str;
	entries[entryCount].setBirthday(str);

	entryCount++;
}

void info::deleteEntry()
{
	string input;

	cout << "Remove an entry" << endl;
	cout << "Name : ";
	cin >> input;

	for (int i = 0; i < entryCount; i++)
	{
		if (strcmp(input.c_str(), entries[i].getName().c_str()) == 0)
		{
			for (int j = 0; j < entryCount - i - 1; j++)
			{
				// entries[j] = entries[j + 1] 구현 (정보 다 옮겨)
			}

			entryCount--;
		}
	}

}

void info::printEntryCount()
{
	cout << "Total number of entries in the list : " << entryCount << endl;
}

void info::countMonth()
{
	for (int i = 0; i < 12; i++)
	{
		month[i].number = 0;
	}

	for (int i = 0; i < 5; i++)
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

void info::printMonth()
{
	cout << "Number of birthdays in" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (month[i].number != 0)
			cout << "	" << month[i].getName() << " : " << month[i].number << endl;
	}
}

void info::printSelectedMonth()
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