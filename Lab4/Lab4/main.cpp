#include "LinkedQueue.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	srand((time(NULL)));
	int fastpay = 1;
	int cashpay = 3;

	int numofCars = rand() % 50 +100;

	cout << numofCars;

	system("pause");
	return 0;
}