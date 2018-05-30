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
	cout << n << " ";
}

int main()
{
	ifstream infile;
	string line;
    BinarySearchTree<string> t;
	infile.open("Names.txt");
	if (!infile)
	{
		cout << "Error opening file. \n";
	}
	else
	{	
		while (getline(infile,line))
		{
			cout << line << endl;
			t.add(line);
		}
		infile.close();
		
	}
	
	system("pause");
	return 0;
}
