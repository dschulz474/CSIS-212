//
//  mainTree.cpp
//  x
//
//  Created by Tony Biehl on 11/6/17.
//  Copyright © 2017 Tony Biehl. All rights reserved.
//

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include <fstream>

using namespace std;

void print(string& n){
	for (int i = 0; i < 2; i++)
	{
		cout << n[i];
	}
	cout << " ";
	
}

int main()
{
	ifstream infile;
	string line;
    BinarySearchTree<string> t;
	string input = "Bill Hader";
	string input2 = "Nancy Drew";
	infile.open("Names.txt");
	if (!infile)
	{
		cout << "Error opening file. \n";
	}
	else
	{	
		while (getline(infile,line))
		{
			t.add(line);
		}
		infile.close();
	}
	if (t.contains(input))
		cout << input << " exists" << endl;
	else cout << input << " does not exist" << endl;

	if (t.contains(input))
		cout << input2 << " exists" << endl;
	else cout << input2 << " does not exist" << endl;
	t.remove("Xena II");
	t.inorderTraverse(print);
	t.printMap(t.getRootData(), 0);
	system("pause");
	return 0;
}
