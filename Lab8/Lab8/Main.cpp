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
				iofile.open("data.txt", ios::in | ios::out);
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
		else if (input == 4)//Grabs entire line and uses .compare to determine which line bubbles to the top
		{
			
			int temp = 1;
			while (temp != count-1)
			{
				while (!iofile.eof())
				{
					iofile.open("data.txt", ios::in | ios::out);
					if (temp == 1)
					{
						iofile.seekp((temp)*recordLength, ios::beg);
						getline(iofile, temp1);
						iofile.seekp((temp+1)*recordLength, ios::beg);
						getline(iofile, temp2);
						if (temp1.compare(temp2))
						{
							iofile.seekp((0)*recordLength, ios::beg);
							iofile << temp2 << endl;
							iofile.seekp((temp + 1)*recordLength, ios::beg);
							iofile << temp1 << endl;
						}
					}
					else
					{
						iofile.seekp((temp)*recordLength, ios::beg);
						getline(iofile, temp1);
						iofile.seekp((temp + 1)*recordLength, ios::beg);
						getline(iofile, temp2);
						if (temp1.compare(temp2) > 0)
						{
							iofile.seekp((temp)*recordLength, ios::beg);
							iofile << temp1 << endl;
							iofile.seekp((temp+1)*recordLength, ios::beg);
							iofile << temp2 << endl;
						}
					}
				}
				temp++;
			}iofile.close();
		}
	} while (input != 0);
	cout << "Closing Program" << endl;
	
	system("pause");
	return 0;
}