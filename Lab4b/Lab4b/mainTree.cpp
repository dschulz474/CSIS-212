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

using namespace std;

void print(string& n){
	cout << n << " ";
}

int main()
{
    BinarySearchTree<string> t;
    
	t.add("Jose"); 
	t.add("Deepak");
	t.add("Anton");
	t.add("Elisa");
	t.add("Quiang");
	t.add("Mia");
	t.add("Zoe");

	t.inorderTraverse(print);
	cout << endl;
	system("pause");
}
