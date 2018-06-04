#include <iostream>
#include <string>
#include "HashedDictionary.h"

using namespace std;
void print(int& n)
{
	cout << n << " ";
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
	
	table.traverse(print);

	
	/*do
	{
		cout << "1) Print Hash table" << endl
			<< "2) Retrieve Has item" << endl
			<< "3) delete Item" << endl
			<< "4) Read names from file" << endl
			<< "5) Save names to file" << endl
			<< "6) add item" << endl
			<< "0) quit" << endl;
		cin >> input;
		if (input == 1)
		{

		}
	} while (input != 0);*/
	cout << "Closing Program" << endl;

		
	system("pause");
	return 0;
}