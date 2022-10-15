#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// month 클래스 : 달에 대한 정보를 저장
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

// entry 클래스 : 전화번호부에 대한 정보를 저장
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


// info : entry와 month를 종합적으로 처리
class info {

public:
	// month와 entry의 정보들이 private으로 선언
	// 따라서 info의 변수들은 public으로 선언
	month month[12];
	entry entries[5];

	int entryCount = 0; // entry가 현재 몇 개인지 세줄 변수

	// info의 month[12]에 달의 이름을 붙여주어 초기화
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
