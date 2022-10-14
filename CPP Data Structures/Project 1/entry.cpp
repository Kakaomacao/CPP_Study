#include "Info.h"

entry::entry()
{
	name = "";
	phoneNum = "";
	birthday = "";
	nameMonth = "";
}

void entry::setName(string name)
{
	this->name = name;
}

string entry::getNameMonth()
{
	return name;
}

void entry::setPhoneNum(string num)
{
	this->phoneNum = num;
}

// 00¿ù / 00ÀÏ / 0000³â
void entry::setBirthday(string date)
{
	string str = date;
	this->birthday = date;

	int a = str.find('/');	
	month = stoi(str.substr(0, a));

	switch (month)
	{
	case 1:
		nameMonth = "January";
		break;
	case 2:
		nameMonth = "February";
		break;
	case 3:
		nameMonth = "March";
		break;
	case 4:
		nameMonth = "April";
		break;
	case 5:
		nameMonth = "May";
		break;
	case 6:
		nameMonth = "June";
		break;
	case 7:
		nameMonth = "July";
		break;
	case 8:
		nameMonth = "August";
		break;
	case 9:
		nameMonth = "Septmeber";
		break;
	case 10:
		nameMonth = "October";
		break;
	case 11:
		nameMonth = "November";
		break;
	case 12:
		nameMonth = "December";
		break;

	}
}

int entry::getMonth()
{
	return this->month;
}

string entry::getNameMonth()
{
	return nameMonth;
}

void entry::printEntry()
{
	cout << name << endl;
	cout << phoneNum << endl;
	cout << birthday << endl;
	cout << endl;
}