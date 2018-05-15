#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

bool isaNumber(string c);
bool isaLetter(string c);
bool isSpecial(string c);
void Radix();
string generateChar();
int main()
{
	srand((unsigned)time(NULL));
	string queues[10000];
	int letterCount = 0;
	int digitCount = 0;
	int specialCount = 0;
	int letterLimit = 10000 * (8 / 10);
	int digitLimit = 10000 * (1 / 10);
	int specialLimit = 10000 * (1 / 10);
	


	for (int i = 0; i < 10000; i++)
	{
		
		string temp2;
		int stringLength = rand() % 15 + 1;
		for (int j = 0; j < stringLength; j++)
		{
			string temp = "";
			temp = generateChar();
			
			temp2 += temp;
		}
		queues[i] = temp2;
		
	}
	cout << "Printing array" << endl;
	for (int i = 0; i < 10000; i++)
	{
		cout << queues[i] << endl;
	}

	system("pause");
	return 0;


}

string generateChar()
{
	string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!";
	string numbers = "0123456789";
	string special = "@#$%^&*";
	string temp;
	int randomChar = rand() % 10 + 1;
	if (randomChar <= 8)
	{
		temp = characters[rand() % (numbers.length()-1) + 0];
	}
	else if (randomChar == 9)
	{
		temp = numbers[rand() % (numbers.length() - 1) + 0];
	}
	else
	{
		temp = special[rand() % (special.length() - 1) + 0];
	}
	
	return temp;
}
void Radix()
{

}

bool isaLetter(string c)
{
	if (c >= "a" || c <= "z" || c >= "A" || c <= "Z")
	{
		return true;
	}
	else return false;
}

bool isSpecial(string c)
{
	if (c == "!" || c == "@" || c == "#" || c == "$" || c == "%" || c == "^" || c == "&" || c == "*")
	{
		return true;
	}
	else return false;
}
bool isaNumber(string c)
{
	if (c >= "0" || c <= "9")
	{
		return true;
	}
	else return false;
}