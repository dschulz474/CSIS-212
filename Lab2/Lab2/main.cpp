#include <iostream>
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"
#include <string>

using namespace std;
bool IsOperator(char C);
bool IsOperand(char c);
int Precedence(char op);
bool validEXP(string exp); //checks for duplicates and even number of paranthesis
bool ParanthesisisBalanced(string expr);//Checks if paranthesis are balanced

int main()
{
	LinkedStack<char> stack;
	string expression;
	string postfixExp = "";
	cout << "Enter an infix experssion:	" << endl;
	cin >> expression;

	while (validEXP(expression) != true && ParanthesisisBalanced(expression) != true)
	{
		cout << "Not a valid infix expression" << endl;
		cin >> expression;
	}
	for(int i = 0; i < expression.length(); i++)
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
				postfixExp += stack.peek();
				stack.pop();
			}
			stack.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			while (stack.peek() != '(')
			{
				postfixExp += stack.peek();
				stack.pop();
			}
			stack.pop();
		}
	}

	while (!stack.isEmpty())
	{
		postfixExp += stack.peek();
		stack.pop();
	}

	cout << "Postfix: "<< postfixExp << endl;
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

bool validEXP(string expression)
{
	char prev = ' ';
	int bracketCheck = 0;

	for (int i = 0; i < expression.length(); i++)
	{
		if (i > 0)
		{
			prev = expression[i - 1];
		}
		if (prev == expression[i])
		{
			return false;
		}
		if (expression[i] == '(')
		{
			bracketCheck++;
		}
		if (expression[i] == ')')
		{
			bracketCheck++;
		}
	}
	if (bracketCheck % 2 != 0)
	{
		return false;
	}
	else
		return true;

	
}

bool ParanthesisisBalanced(string expr)
{
	LinkedStack<char> s;
	char a, b, c;

	// Traversing the Expression
	for (int i = 0; i<expr.length(); i++)
	{
		if (expr[i] == '(' )
		{
			// Push the element in the stack
			s.push(expr[i]);
		}
		else
		{
			switch (expr[i])
			{
			case ')':

				// Store the top element in a
				a = s.peek();
				s.pop();
				if (a == '{' || a == '[')
					cout << "Not Balancedn";
				break;
			case '}':

				// Store the top element in b
				b = s.peek();
				s.pop();
				if (b == '(' || b == '[')
					cout << "Not Balancedn";
				break;
			case ']':

				// Store the top element in c
				c = s.peek();
				s.pop();
				if (c == '(' || c == '{')
					cout << "Not Balancedn";
				break;
			}
		}
	}

	// Check Empty Stack
	if (s.isEmpty())
		return true;
	else
		return false;
}