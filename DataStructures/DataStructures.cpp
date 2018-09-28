// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListNode.h"
#include "SingleLinkedList.h"
#include "StackUsingArray.h"
#include "StackUsingList.h"
#include "Stack.h"
#include <string>
#include <stack>

using namespace std;

template <typename T>
void SingleLinkedListOperations(SingleLinkedList<T>* list)
{
	int list_count = 0, data = 0;
	cout << "Enter number of nodes in Single Linked List : ";
	cin >> list_count;
	for (int i = 0; i < list_count; i++)
	{
		cin >> data;
		list->InsertInList(data);
	}
	list->PrintList();
}

// Returns precedence of operators.
int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Using STL Stack - stack and STL string.
void InfixToPostfix()
{
	string infixStr;
	stack<char> operators;
	cout << "Enter the Infix Expression (without spaces) : ";
	cin >> infixStr;
	cout << endl;
	for (int i = 0; i < infixStr.length(); i++)
	{
		if ((infixStr[i]>='a' && infixStr[i]<='z') || (infixStr[i]>='A' && infixStr[i]<='Z'))
		{
			cout << infixStr[i];
		}

		else if (infixStr[i] == '(')
			operators.push(infixStr[i]);

		else if (infixStr[i] == ')')
		{
			while (operators.top() != '(')
			{
				cout << operators.top();
				operators.pop();
			}
			if (operators.empty())
			{
				cout << "\nInvalid Infix Expression." << endl;
				return;
			}
			if (operators.top() == '(')
				operators.pop();
		}
		else if (infixStr[i] == '^' || infixStr[i] == '*' || infixStr[i] == '+' || infixStr[i] == '-' || infixStr[i] == '/')
		{
			if (operators.empty())
				operators.push(infixStr[i]);
			else if (precedence(infixStr[i]) > precedence(operators.top()))
			{
				operators.push(infixStr[i]);
			}
			else
			{
				while (!operators.empty() && precedence(operators.top()) >= precedence(infixStr[i]))
				{
					cout << operators.top();
					operators.pop();
				}
				operators.push(infixStr[i]);
			}
		}
		else
		{
			cout << "\n Not a valid Infix input expression." << endl;
		}
	}
	while (!operators.empty())
	{
		cout<<operators.top();
		operators.pop();
	}
}

// Using defined StackUsingArray and Char *
void InfixToPostfixChar()
{
	char * str = (char *)malloc(100);
	for (int i = 0; i < 100; i++)
	{
		str[i] = '\0';
	}
	StackUsingArray<char> operators;
	cout << "Enter the Infix Expression (without spaces) : ";
	cin >> str;
	cout << "\nPostfix Expression is : " ;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'a' && *str <= 'z'))
		{
			cout << *str;
		}

		else if (*str == '(')
			operators.Push(*str);
		else if (*str == ')')
		{
			while (operators.Top() != '(')
			{
				cout << operators.Pop();
			}
			if (operators.IsEmptyStack())
			{
				cout << "\nInvalid Infix Expression." << endl;
				return;
			}
			if(operators.Top() == '(')
				operators.Pop();
		}

		else if (*str == '^' || *str == '*' || *str == '+' || *str == '-' || *str == '/')
		{
			if (operators.IsEmptyStack())
				operators.Push(*str);
			else if (precedence(*str) > precedence(operators.Top()))
			{
				operators.Push(*str);
			}
			else
			{
				while (!operators.IsEmptyStack() && precedence(operators.Top()) >= precedence(*str))
				{
					cout << operators.Pop();
				}
				operators.Push(*str);
			}
		}
		else
		{
			cout << "\n Not a valid Infix input expression." << endl;
		}
		str++;
	}
	while (!operators.IsEmptyStack())
	{
		cout << operators.Pop();
	}
}

// Using defined StackUsingArray.
void PostfixEvaluation()
{
	cout << "Enter Postfix Expression : ";
	string postfixStr;
	StackUsingArray<int> evalStack;
	cin >> postfixStr;
	int left, right, newVal;

	for (int i = 0; i<postfixStr.length(); i++)
	{
		if (postfixStr[i] >= '0' && postfixStr[i] <= '9')
			evalStack.Push(postfixStr[i] - '0'); // Converting char to int.

		else if (postfixStr[i] == '+' || postfixStr[i] == '-' || postfixStr[i] == '*' || postfixStr[i] == '/')
		{
			right = evalStack.Pop();
			left = evalStack.Pop();
			switch (postfixStr[i])
			{
				case '+': newVal = left + right; break;
				case '-': newVal = left - right; break;
				case '*': newVal = left * right; break;
				case '/': newVal = left / right; break;
			}
			evalStack.Push(newVal);
		}

		else
		{
			cout << "Invalid Postfix Expression." << endl;
			break;
		}
	}
	if (evalStack.Size() == 1)
		cout << evalStack.Pop() << endl;
	else
		cout << "Invalid Stack State." << endl;
}

void StackOperations(Stack * sa)
{
	InfixToPostfix();
	InfixToPostfixChar();
	PostfixEvaluation();
}

int main()
{
	SingleLinkedList<int> * llist = new SingleLinkedList<int>();
	SingleLinkedListOperations(llist);
	
	Stack* stack1 = new StackUsingArray<int>();
	Stack* stack2 = new StackUsingList<int>();
	
	StackOperations(stack1);
	StackOperations(stack2);
	
	getchar();
    return 0;
}





