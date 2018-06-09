#include <iostream>
#include <string>
#include "HashedDictionary.h"
#include <fstream>

using namespace std;

void print(int& n)
{
	cout << n << " " << endl;
}
int main()
{
	fstream infile;
	HashedDictionary<string, int> table;
	string name;
	int input;
	int tempItem;

	table.add("Greg Greed", 30);
	table.add("Sally Smith", 18);
	table.add("James Jones", 44);
	table.add("Samantha Abernathy", 59);
	table.add("George Ivy", 27);
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
		else if (input == 3)
		{
			cout << "Name to delete" << endl;
			getline(cin, name);
			table.remove(name);
		}
		else if (input == 4)
		{
			cout << "Reading names from file" << endl;
			infile.open("data.txt");
			if (!infile)
				cout << "Error opening file" << endl;
			else
			{
				while (infile)
				{
					getline(infile, name);
					cout << name << endl;
				}
				
			}infile.close();
		}
		else if (input == 5)
		{
			cout << "Enter a name to save to the file" << endl;
			getline(cin, name);
			infile.open("data.txt");
			if (!infile)
				cout << "Error opening file" << endl;
			else
			{
			if (table.contains(name))
				{
					infile << name << ", " << table.getItem(name) << endl;
					
				}
			else
			{
				table.contains(name);
			}
			infile.close();
			}
		
		}
		else if (input == 6)
		{
			if (!infile)
				cout << "Error opening file" << endl;
			else
			{
			cout << "Enter name: " << endl;
			getline(cin, name);
			cout << "Emter age: " << endl;
			cin >> tempItem;
			table.add(name, tempItem);
			}
		}
	} while (input != 0);
	cout << "Closing Program" << endl;

		
	system("pause");
	return 0;
}
