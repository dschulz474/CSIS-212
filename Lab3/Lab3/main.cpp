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
void Radix(string arr[], int size);
string generateChar();

int main()
{
	srand((unsigned)time(NULL));
	string randStrings[10000];
	
	for (int i = 0; i < 10000; i++)
	{
		
		string temp2;
		int stringLength = rand() % 15 + 1;
		for (int j = 0; j <= stringLength-1; j++)
		{
			/*string temp = "";
			temp = generateChar();*/
			
			temp2 += generateChar();
		}
		randStrings[i] = temp2;
	}
	for (int i = 0; i < 15; i++)
	{
		cout << randStrings[i] << endl;
	}
	Radix(randStrings, 10000);
	system("pause");
	return 0;
}

string generateChar()
{
	string characters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string numbers = "0123456789";
	string special = "!@#$%^&*[]{};:<>'\"_-+=()\\|~`";
	string temp;
	int randomChar = rand() % 10 + 1;

	if (randomChar <= 8)
	{
		temp = characters[rand() % (characters.length()-1)];
	}
	else if (randomChar == 9)
	{
		temp = numbers[rand() % (numbers.length() - 1) ];
	}
	else
	{
		temp = special[rand() % (special.length() - 1) ];
	}
	
	return temp;
}

void Radix(string arr[], int size)
{
	LinkedQueue<string> queues[95];
	for (int i = 14; i < 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j].length()>i) 
			{
				int temp = arr[j][i];
				queues[temp-32].enqueue(arr[j]);
			}
			else
			{
				queues[0].enqueue(arr[j]);
			}
		}
	}
	
}

