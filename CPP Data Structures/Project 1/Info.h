#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// month Ŭ���� : �޿� ���� ������ ����
class month {

private:
	string name;

public:
	int number = 0;

	month() {
		name = "";
	}

	month(string n) {
		name = n;
	}

	string getName() {
		return name;
	}
};

// entry Ŭ���� : ��ȭ��ȣ�ο� ���� ������ ����
class entry {

private:
	string name;
	string phoneNum;
	string birthday;
	string nameMonth;
	int month;

public:
	entry();

	void setName(string name);
	string getName();

	void setPhoneNum(string num);
	string getPhoneNum();

	void setBirthday(string date);
	string getBirthday();
	int getMonth();
	string getNameMonth();

	void printEntry();
};


// info : entry�� month�� ���������� ó��
class info {

public:
	// month�� entry�� �������� private���� ����
	// ���� info�� �������� public���� ����
	month month[12];
	entry entries[5];

	int entryCount = 0; // entry�� ���� �� ������ ���� ����

	// info�� month[12]�� ���� �̸��� �ٿ��־� �ʱ�ȭ
	info() {
		month[0] = month::month("January");		month[1] = month::month("February");
		month[2] = month::month("March"); 		month[3] = month::month("April");
		month[4] = month::month("May");			month[5] = month::month("June");
		month[6] = month::month("July");		month[7] = month::month("August");
		month[8] = month::month("Septmeber");	month[9] = month::month("October");
		month[10] = month::month("November");	month[11] = month::month("December");
	}

	void openFile();

	void exportEntries();

	void addEntry();

	void deleteEntry();

	void printCountAndMonth();

	void countMonth();
	void printSelectedMonth();
};
