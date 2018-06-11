#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ofstream file("data.txt");

    const int NAME = 21;

	const int AGE = 3;
	file << setw(NAME) << "Mustang Sally" << ","
		 << setw(AGE) << 22 << endl;
	file << setw(NAME) << "George Symthe" << ","
		 << setw(AGE) << 52 << endl;
	file << setw(NAME) << "Harry Harrison" << ","
		 << setw(AGE) << 37 << endl;
	file << setw(NAME) << "Cherise Eddington" << ","
		 << setw(AGE) << 45 << endl;
	file << setw(NAME) << "Antonio Valdez" << ","
		 << setw(AGE) << 61 << endl;
	file << setw(NAME) << "Mary Gomez" << ","
		 << setw(AGE) << 19 << endl;
	file << setw(NAME) << "Antonio Valdez" << ","
		 << setw(AGE) << 61 << endl;
	file << setw(NAME) << "Bruce Bacon" << ","
		 << setw(AGE) << 28 << endl;
	cout << "File people.txt has been created\n";
	system("pause");
	return 0;

}

