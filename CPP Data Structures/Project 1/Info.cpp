#include "Info.h"

void info::openFile()

// 파일명을 입력하여 파일을 열어 entry 저장하는 함수

{
	string txtName;
	string line;
	int n = 0;

	cout << "Enter the name of the file : ";
	cin >> txtName;

	// .txt까지 붙여주어야 한다
	ifstream file(txtName + ".txt");

	// 파일을 열어서 한줄씩을 string 배열에 저장
	if (file.is_open()) {
		while (getline(file, line)) {
			// 4줄씩 끊기 1줄은 이름, 2줄은 전화번호, 3줄은 생일, 4줄은 저장X
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

// ----------------------------------------------------------------

void info::exportEntries()

// 문자열을 입력 받아 txt를 생성하여 entry를 적는 함수

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

// 새로운 entry를 추가하는 함수

{
	string str;

	cin.ignore(); // 남아있는 엔터 버퍼를 제거
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

// 기존의 entry를 제거해주는 함수

{
	string input;

	cin.ignore(); // 남아있는 엔터 버퍼를 제거
	cout << "Remove an entry" << endl;
	cout << "Name : ";
	getline(cin, input);

	for (int i = 0; i < entryCount; i++)
	{
		if (strcmp(input.c_str(), entries[i].getName().c_str()) == 0)
		{
			for (int j = 0; j < entryCount - i - 1; j++)
			{
				// entries[j] = entries[j + 1] 구현 (정보 다 옮겨)
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

// 현재 entry들의 생일을 확인하여 무슨 달에 몇 명이 있는지 세주는 함수

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

// 현재 entry 수와 entry 속 사람들이 무슨 달에 몇 명이 있는지 출력하는 함수

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

// 입력한 달에 몇 명이 있는지 출력하고 그 사람들의 entry를 출력하는 함수

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