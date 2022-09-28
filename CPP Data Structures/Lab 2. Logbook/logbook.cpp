#include "logbook.h"

Logbook::Logbook(int month, int year)
{
	logMonth = month;
	logYear = year;

	for (int i = 0; i <= getDaysInMonth(); i++)
	{
		entries[i] = { 0 };
	}
}

void Logbook::putEntry(int day, int value)
{
	entries[day] = value;
}

// const�� �Լ� �ȿ��� Logbook�� ���� �������� �ʴ´�.
int Logbook::getEntry(int day) const
{
	return entries[day];
}

int Logbook::getMonth() const
{
	return logMonth;
}

int Logbook::getYear() const
{
	return logYear;
}

int Logbook::getDaysInMonth() const
{
	if (isLeapYear() == 1)
		switch (logMonth)
		{
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):
			return 31;
		case(4):
		case(6):
		case(9):
		case(11):
			return 30;
		case(2):
			return 29;
		default:
			break;
		}
	else
		switch (logMonth)
		{
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):
			return 31;
		case(4):
		case(6):
		case(9):
		case(11):
			return 30;
		case(2):
			return 28;
		default:
			break;
		}
}

// �����̸� true �ƴϸ� false ��ȯ�ϴ� �Լ�
// 4�� ������ ������ 0�̸� ���� / 100�� ���ٴ� �ƴ� / 400�� ���ٴ� ����
bool Logbook::isLeapYear() const
{
	if (logYear % 4 == 0)
		if (logYear % 100 != 0 || logYear % 400 == 0)
			return 1;
		else
			return 0;
	else
		return 0;
}

// In-lab operations
void Logbook::displayCalendar() const
{	
	cout << "Sun	" << "Mon	" << "Tue	" << "Wed	" << "Thu	" << "Fri	" << "Sat	" << endl;

	for (int i = 1; i <= getDaysInMonth(); i++) {
		if (i == 1)
			switch (getDayOfWeek(i))
			{
			case 0: break;
			case 1: cout << "	"; break;
			case 2: cout << "		"; break;
			case 3: cout << "	 		"; break;
			case 4: cout << "				"; break;
			case 5: cout << "					"; break;
			case 6: cout << "						"; break;
			default:
				break;
			}
		if (getDayOfWeek(i) == 0)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 1)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 2)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 3)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 4)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 5)
			cout << i << " " << entries[i] << "	";
		else if (getDayOfWeek(i) == 6)
			cout << i << " " << entries[i] << endl;
	}
}

// (1 + ���� ��� + ���� ���� + ���ؿ� ���� �������� + ��������) % 7 -> 0(��) ~ 6(��)
int Logbook::getDayOfWeek(int day) const
{
	int numLeapYear = 0;
	for (int i = 1901; i <= logYear; i++) {
		if (i % 4 == 0)
			if (i % 100 != 0 || i % 400 == 0)
				numLeapYear += 1;
	}
	
	int dayPassed = 0;
	for (int i = 1; i < logMonth; i++) {
		if(isLeapYear() == 1)
			switch (i)
			{
			case(1):
			case(3):
			case(5):
			case(7):
			case(8):
			case(10):
			case(12):
				dayPassed += 31; break;
			case(4):
			case(6):
			case(9):
			case(11):
				dayPassed += 30; break;
			case(2):
				dayPassed += 29; break;
			default:
				break;
			}
		else
			switch (i)
			{
			case(1):
			case(3):
			case(5):
			case(7):
			case(8):
			case(10):
			case(12):
				dayPassed += 31; break;
			case(4):
			case(6):
			case(9):
			case(11):
				dayPassed += 30; break;
			case(2):
				dayPassed += 28; break;
			default:
				break;
			}
	}

	return (1 + logYear - 1901 + numLeapYear + dayPassed + day) % 7;
}