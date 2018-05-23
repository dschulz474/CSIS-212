#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
int tollSim(int numberofBooths);
int tollKind();

int main()
{
	srand((time(NULL)));
	cout << "Time: "<<tollSim(2);
	/*tollSim(3);
	tollSim(4);
	tollSim(5);*/
	system("pause");
	return 0;
}

int tollSim(int numberofBooths)
{
	
	int numofCars = rand() % 50 + 50;
	int time = 0;
	cout << "Total Cars: "<< numofCars << endl;
	if (numberofBooths == 2)
	{
		LinkedQueue<int> booth1;
		LinkedQueue<int> booth2;
		while (numofCars != 0)
		{
			booth1.enqueue(tollKind());
			numofCars--;
			if (numofCars != 0)
			{
				booth2.enqueue(tollKind());
				numofCars--;
			}
		}
		while (!booth1.isEmpty())
		{
			time += booth1.peekFront();
			booth1.dequeue();
		}
		while (!booth2.isEmpty())
		{
			time += booth2.peekFront();
			booth2.dequeue();
		}
		return time;
	}
	else if (numberofBooths == 3)
	{
		LinkedQueue<int> booth1;
		LinkedQueue<int> booth2;
		LinkedQueue<int> booth3;
	}
	else if (numberofBooths == 4)
	{
		LinkedQueue<int> booth1;
		LinkedQueue<int> booth2;
		LinkedQueue<int> booth3;
		LinkedQueue<int> booth4;
	}
	else
	{
		LinkedQueue<int> booth1;
		LinkedQueue<int> booth2;
		LinkedQueue<int> booth3;
		LinkedQueue<int> booth4;
		LinkedQueue<int> booth5;
	}
}

int tollKind()
{
	int fastpassTime = 1;
	int cashpayTime = 3;
	int cashOrpass = rand() % 1+2;
	if (cashOrpass = 1)
		return fastpassTime;
	else
		return cashpayTime;
}