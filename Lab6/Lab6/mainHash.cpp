#include <iostream>
#include <string>
#include "HashedDictionary.h"

using namespace std;

void print(int& n)
{
	cout << n << " " << endl;
}
int main()
{
	/*int input;*/
	HashedDictionary<string, int> table;
	table.add("Greg Greed", 30);
	table.add("Sally Smath", 18);
	table.add("James Jones", 44);
	table.add("Samantha Abernathy", 59);
	table.add("George Ivy", 27);
	

	string name;
	int input;
	do
	{
		cout << "1) Print Hash table" << endl
			<< "2) Retrieve Hash item" << endl
			<< "3) delete Item" << endl
			<< "4) Read names from file" << endl
			<< "5) Save names to file" << endl
			<< "6) add item" << endl
			<< "0) quit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		if (input == 1)
		{
			table.traverse(print);
			cout << endl;
		}
		else if (input == 2)
		{
			cout << "Search for a name" << endl;
			getline(cin, name);
			cout << table.getItem(name) << endl;
		}
		else if (input == 3)
		{
			cout << "Enter a name to delete" << endl;
			getline(cin, name);
			if (table.contains(name))
			{
				table.remove(name);
			}
			else
			{
				cout << "Cannot delete entry" << endl;
			}
		}
	} while (input != 0);
	cout << "Closing Program" << endl;

		
	system("pause");
	return 0;
}
