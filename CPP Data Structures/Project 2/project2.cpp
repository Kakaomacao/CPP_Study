#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Person
{
private:
	string name;

public:
	list<string> personFriend;

	void setName(string n)
	{
		name = n;
	}
};

int main()
{
	char cmd;
	string input1, input2;
	unordered_map <string, Person*> um;
	unordered_map <string, bool> isFriend;

	cout << "P : Create Account" << endl;
	cout << "F : Make two people Friends" << endl;
	cout << "U : Unfriend two people" << endl;
	cout << "L : Show the Friend List" << endl;
	cout << "Q : Check whether two people are friends" << endl;
	cout << "X : Quit" << endl;
	
	do {
		cout << ">> ";
		cin >> cmd;

		switch (cmd)
		{
		
		case 'P': case 'p':
		{
			cin >> input1;

			// 중복 허용 X
			if (um.find(input1) != um.end()) {
				cout << "The name already exists!" << endl;
				break;
			}

			Person* newPerson = new Person();
			newPerson->setName(input1);
			um.insert(make_pair(input1, newPerson));

			break;
		}

		// 만약에 없는 사람이면 작동 X
		case 'F': case 'f':
		{
			cin >> input1;
			cin >> input2;

			if (um.find(input1) != um.end() && um.find(input2) != um.end()) {
				um[input1]->personFriend.push_back(input2);
				um[input2]->personFriend.push_back(input1);

				isFriend.insert({ input1 + input2, true });
				isFriend.insert({ input2 + input1, true });
			}

			else
			{
				cout << "Invalid command!" << endl;
			}

			break;
		}

		case 'U': case 'u':
		{
			cin >> input1;
			cin >> input2;

			// personFriend에서 찾을 때까지 이동 후 삭제

			if (um.find(input1) != um.end() && um.find(input2) != um.end())
			{
				isFriend.erase(input1 + input2);
				isFriend.erase(input2 + input1);
			}

			um[input1]->personFriend.remove(input2);
			um[input2]->personFriend.remove(input1);
			
			break;
		}

		case 'L': case 'l':
		{
			// Person의 personFriend nullptr나올때까지 이동하면서 출력
			cin >> input1;

			if (um.find(input1) != um.end()) 
			{
				for (auto loop : um[input1]->personFriend)
				{
					cout << loop << " ";
				}

				cout << endl;
			}

			break;
		}

		case 'Q': case 'q':
		{
			// isFriend에서 input1 + input2나 input2 + input1 찾아서 있으면 true
			// 없으면 false
			cin >> input1;
			cin >> input2;

			if (isFriend.find(input1 + input2) != isFriend.end())
			{
				cout << "Yes! They are friends." << endl;
				break;
			}

			else
				cout << "No~ They are not friends." << endl;

			break;
		}

		case 'X': case 'x':
		{
			break;
		}

		}
	} while (cmd != 'X' && cmd != 'x');

	return 0;
}