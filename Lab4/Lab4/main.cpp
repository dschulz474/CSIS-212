#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;
int tollSim(int numberofBooths,int numofCars);
int tollKind();

int main()
{
	srand((time(NULL)));
	int numofCars = rand() % 100 + 1;
	cout << "Time: " << tollSim(2,numofCars) << endl;
	cout << "Time: " << tollSim(3,numofCars) << endl;
	cout << "Time: " << tollSim(4,numofCars) << endl;
	cout << "Time: " << tollSim(5,numofCars) << endl;
	system("pause");
	return 0;
}

int tollSim(int numberofBooths, int numofCars)
{
	LinkedQueue<int> booth1;
	LinkedQueue<int> booth2;
	LinkedQueue<int> booth3;
	LinkedQueue<int> booth4;
	LinkedQueue<int> booth5;

	
	int time = 0;
	cout << "Total Cars: "<< numofCars << endl;
	if (numberofBooths == 2)
	{
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
		while (numofCars != 0)
		{
			booth1.enqueue(tollKind());
			numofCars--;
			if (numofCars != 0)
			{
				booth2.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth3.enqueue(tollKind());
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
		while (!booth3.isEmpty())
		{
			time += booth3.peekFront();
			booth3.dequeue();
		}
		return time;
	}
	else if (numberofBooths == 4)
	{
		while (numofCars != 0)
		{
			booth1.enqueue(tollKind());
			numofCars--;
			if (numofCars != 0)
			{
				booth2.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth3.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth4.enqueue(tollKind());
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
		while (!booth3.isEmpty())
		{
			time += booth3.peekFront();
			booth3.dequeue();
		}
		while (!booth4.isEmpty())
		{
			time += booth4.peekFront();
			booth4.dequeue();
		}
		return time;
	}
	else
	{
		while (numofCars != 0)
		{
			booth1.enqueue(tollKind());
			numofCars--;
			if (numofCars != 0)
			{
				booth2.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth3.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth4.enqueue(tollKind());
				numofCars--;
			}
			if (numofCars != 0)
			{
				booth5.enqueue(tollKind());
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
		while (!booth3.isEmpty())
		{
			time += booth3.peekFront();
			booth3.dequeue();
		}
		while (!booth4.isEmpty())
		{
			time += booth4.peekFront();
			booth4.dequeue();
		}
		while (!booth5.isEmpty())
		{
			time += booth5.peekFront();
			booth5.dequeue();
		}
		return time;
	}
}

int tollKind()
{
	int fastpassTime = 1;
	int cashpayTime = 3;
	int cashOrpass = rand() % 2;
	if (cashOrpass == 1)
		return fastpassTime;
	else
		return cashpayTime;
}