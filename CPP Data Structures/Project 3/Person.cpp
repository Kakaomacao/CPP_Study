#include "Person.h"

Person::Person()
{
	personName = "";
}

Person::Person(string name)
{
	this->personName = name;
}

Person::Person(string name, int level)
{
	this->personName = name;
	this->level = level;
}

int Person::getLevel()
{
	return level;
}

Hierarchy::Hierarchy()
{
	root = nullptr;
}

// -----------------------------------------------------------------------------

void Hierarchy::reduceLevel(Person*& p)
{
	reduceLevelSub(p);
}

void Hierarchy::reduceLevelSub(Person*& p)
{
	if (p == nullptr)
		return;
	else
	{
		p->level--;

		for (int i = 0; i < p->n; i++)
		{
			reduceLevelSub(p->employees[i]);
		}
	}
}

// -----------------------------------------------------------------------------

// 이름 1개일 때, 이름 2개일 때
void Hierarchy::hire(string employer, string employee)
{
	if (root == nullptr)
	{
		root = new Person(employer);
	}

	else
	{
		hireSub(root, employer, employee);
	}
}

void Hierarchy::hireSub(Person*& p, string employer, string employee)
{
	if (p == nullptr)
		return;

	if (p->personName == employer)
	{
		p->employees[p->n] = new Person(employee, p->level + 1);
		p->n++;
		return;
	}

	else
	{
		for (int i = 0; i < p->n; i++)
		{
			hireSub(p->employees[i], employer, employee);
		}
	}
}

// -----------------------------------------------------------------------------

void Hierarchy::fire(string employee)
{
	fireSub(root, employee);
}

void Hierarchy::fireSub(Person*& p, string employee)
{
	if (p == nullptr)
		return;

	else
	{
		if (p->personName == employee)
			fireSub2(p);

		else 
		{
			for (int i = 0; i < p->n; i++)
			{
				if (p->employees[i]->personName == employee)
					fireSub2(p->employees[i]);

				else
					fireSub(p->employees[i], employee);
			}
		}
	}
}

void Hierarchy::fireSub2(Person*& p)
{
	// employee 없는 경우
	if (p->employees[0] == nullptr)
	{
		delete p;
		p = nullptr;
		return;
	}

	// employee 있는 경우
	if (p->employees[0]->employees[0] == nullptr)
	{
		p->personName = p->employees[0]->personName;

		delete p->employees[0];
		p->employees[0] = nullptr;

		for (int i = 0; i < p->n - 1; i++)
			p->employees[i] = p->employees[i + 1];

		p->n--;

		return;
	}

	else
	{
		p->personName = p->employees[0]->personName;
		fireSub2(p->employees[0]);
	}
}

// -----------------------------------------------------------------------------

void Hierarchy::print()
{
	printSub(root);
}

void Hierarchy::printSub(Person*& p)
{
	if (p == nullptr)
	{
		return;
	}

	// + 개수 판단해서 출력
	else
	{
		for (int i = 0; i < p->level; i++)
			cout << "+";

		cout << p->personName << endl;

		for (int i = 0; i < p->n; i++)
		{
			printSub(p->employees[i]);
		}
	}
}

