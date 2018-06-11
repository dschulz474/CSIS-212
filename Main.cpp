#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	fstream iofile;
	int input,count;
	
	string name;
	string age, temp1, temp2;
	bool swap;
	int nameLength = 21;
	int ageLength = 3;
	int recordLength = 27;

	iofile.open("data.txt", ios::in | ios::out);
	if (!iofile)
	{
		cout << "Error opening file" << endl;
		system("pause");
		return 0;
	}
	else
	{
		cout << "File has been opened"<< endl;
		iofile.close();
		//remove("data.txt");
	}
	do
	{
		cout << "1) Add record" << endl
			<< "2) Change record" << endl
			<< "3) Print all records" << endl
			<< "4) Sort records by name" << endl
			<< "5) Search records by name" << endl
			<< "6) Delete record" << endl
			<< "0) quit" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
		if (input == 1)
		{
			cout << "Enter a name: " << endl;
			getline(cin, name);
			cout << "Enter an age: " << endl;
			cin >> age;
			
			if (iofile.peek() == EOF)
			{
				iofile.open("data.txt", ios::app);
				iofile << setw(nameLength) << name << ","
				<< setw(ageLength) << age <<endl;
				iofile.close();
			}
			else
			{
				iofile.open("data.txt");
				iofile << setw(nameLength) << name << ","
				<< setw(ageLength) << endl;
				iofile.close();
			}
		}
		else if (input == 2)
		{
			
			cout << "What record do you want to change" << endl;
			cin >> input;
			

			cout << "Enter a name\n";
			cin.ignore();
			getline(cin, name);
			cout << "Enter an age\n";
			cin >> age;
			

			iofile.open("data.txt", ios::in | ios::out);
			iofile.seekp((input - 1)*recordLength, ios::beg);
			iofile << setw(nameLength) << name << ","
			<< setw(ageLength) << age << endl;
			iofile.close();
		}
		else if (input == 3)
		{
			iofile.open("data.txt", ios::in | ios::out);
			count = 1;
			while (!iofile.eof())
			{
				ws(iofile);
				 getline(iofile, name, ',');
				
				iofile >> age;
				cout << count<< " "<< name << ", " << age << endl;
				count++;
			}
			iofile.close();
			cout << endl;
		}
		else if (input == 4)
		{

		}
	} while (input != 0);
	cout << "Closing Program" << endl;
	/*iofile.open("data.txt");
	if (!iofile)
		cout << "Error Opening file" << endl;
	else
	{

	}*/
	system("pause");
	return 0;
}