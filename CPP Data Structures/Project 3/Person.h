#pragma once

#include <iostream>
using namespace std;

class Person
{
private:
	string personName;
	Person* employees[5] = { nullptr };
	int n = 0;
	int level = 0;
	
public:
	Person();
	Person(string name);
	Person(string name, int level);

	int getLevel();

	friend class Hierarchy;
};

class Hierarchy
{
private:
	Person* root;

public:
	Hierarchy();

	void reduceLevel(Person*& p);
	void reduceLevelSub(Person*& p);


	void hire(string employer, string employee);
	void hireSub(Person*& p, string employer, string employee);

	void fire(string employee);
	void fireSub(Person*& p, string employee);
	void fireSub2(Person*& p);

	void print();
	void printSub(Person*& p);
};