#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


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
			temp2 += generateChar();
		}
		randStrings[i] = temp2;
	}
	//Pre Sort
	cout << "Pre Radix Sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << randStrings[i] << endl;
	}
	for (int i = 5000; i < 5010; i++)
	{
		cout << randStrings[i] << endl;
	}
	for (int i = 9990; i < 10000; i++)
	{
		cout << randStrings[i] << endl;
	}
	Radix(randStrings, 10000);
	//Post Sort
	cout << "Post Radix Sort" << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << randStrings[i] << endl;
	}
	for (int i = 5000; i < 5010; i++)
	{
		cout << randStrings[i] << endl;
	}
	for (int i = 9990; i < 10000; i++)
	{
		cout << randStrings[i] << endl;
	}
	
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
	for (int i = 14; i >= 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j].length()>i)
			{
				int temp = arr[j][i];
				queues[temp - 32].enqueue(arr[j]);
			}
			else
			{
				queues[0].enqueue(arr[j]);
			}
		}
		int index = 0;
		for (int k = 0; k < 95; k++)
		{

			while (!queues[k].isEmpty())
			{
				arr[index] = queues[k].peekFront();
				queues[k].dequeue();
				index++;
			}
		}
	}
}

