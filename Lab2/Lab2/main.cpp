#include <iostream>
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"
#include <string>

using namespace std;
bool IsOperator(char C);
bool IsOperand(char c);
int Precedence(char op);

int main()
{
	LinkedStack<char> stack;
	string expression;
	string postfixExp = "";
	cout << "Enter an infix experssion:	" << endl;
	cin >> expression;
	for(int i = 0; i < expression.size(); i++)
	{
		if (IsOperand(expression[i]))
		{
			postfixExp += expression[i];
			
		}
		else if (expression[i] == '(')
		{
			stack.push(expression[i]);
			
		}
		else if (IsOperator(expression[i]))
		{
			while (!stack.isEmpty() && stack.peek() != '(' && Precedence(expression[i]) <= Precedence(stack.peek()))
			{

			}
		}
	}
	system("pause");
	return 0;
}

bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

int Precedence(char op1)
{
	int weight;
	
	if (op1 == '+' || op1 == '-')
	{
		weight = 0;
	}
	else if (op1 == '*' || op1 == '/')
	{
		weight = 1;
	}
	return weight;
}

