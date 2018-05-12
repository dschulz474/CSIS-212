#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

bool isaNumber(char c);
bool isaLetter(char c);
bool isSpecial(char c);
void Radix();
string GenerateString(string cha,string arr[]);
int main()
{
	srand(time(NULL));
	int digitCount, specialCount, charCount;
	string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
	string queues[10000];
	cout << queues->size() << endl;
	for (int i = 0; i < queues->size(); i++)
	{
		GenerateString(characters, queues);
	}
	for (int i = 0; i < queues->size(); i++)
	{
		cout << "Printing Array" << endl;
		cout << queues[i] << endl;
	}

	system("pause");
}

string GenerateString(string characters, string arr[])
{
	string temp = "";
	int stringlength = rand() % 14 + 0;
	int randomCharacter = rand() % (characters.length()-1) + 0;
	for (int i = 0; i < stringlength; i++)
	{
		temp += characters[randomCharacter];
	}
	return temp;
}

void Radix()
{
	
	
	LinkedQueue<char> queues[95];
}

bool isaLetter(char c)
{
	if (c >= 'a' || c <= 'z' || c >= 'A' || c<= 'Z')
	{
		return true;
	}
	else return false;
}

bool isSpecial(char c)
{
	if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*')
	{
		return true;
	}
	else return false;
}
bool isaNumber(char c)
{
	if (c >= '0' || c <= '9')
	{
		return true;
	}
	else return false;
}