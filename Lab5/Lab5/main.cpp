#include <iostream>
#include "ArrayMaxHeap.h"

using namespace std;


int main()
{
	int array[] = {4,12,8,33,21,56,3,76,81,19,13,5};
	ArrayMaxHeap<int> test(array, 12);
	int index = 11;
	for (int i = 0; i < 12; i++)
	{
		cout <<array[i]<< " ";
	}
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		test.add(array[i]);
	}
	while (!test.isEmpty())
	{
		int temp = test.peekTop();
		array[index] = temp;
		index--;
		test.remove();
	}
	for (int i = 0; i < 12; i++)
	{
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}

