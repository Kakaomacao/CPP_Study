#include "Account.h"

Bank::Bank()
{
	acno = 0;
	balance = 0;
}

void Bank::init()
{
	cout << "Enter the Name of the depositor : ";
	cin >> name;
	cout << "Enter the Account Number : ";
	cin >> acno;
	cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
	cin >> actype;
	cout << "Enter the Amount to Deposit : ";
	cin >> balance;
}

void Bank::deposit()
{
	int dep = 0;
	cout << "Enter the amount to deposit : ";
	cin >> dep;
	balance = balance + dep;
}

void Bank::withdraw()
{
	int with = 0;
	cout << "Enter the amount to withdraw : ";
	cin >> with;
	balance = balance - with;
}

void Bank::disp_det()
{
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number : " << acno << endl;
	cout << "Account Type : " << actype << endl;
	cout << "Balance : $" << balance << endl;
}