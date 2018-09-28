// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListNode.h"
#include "SingleLinkedList.h"
#include "StackUsingArray.h"
#include "StackUsingList.h"
#include "Stack.h"
#include<stack>
#include<string>

using namespace std;

SingleLinkedList* SingleLinkedListOperations();
void StackOperations(Stack * sa);

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

void InfixToPostfixChar()
{
	char * str = (char *)malloc(100);
	for (int i = 0; i < 100; i++)
	{
		str[i] = '\0';
	}
	stack<char> operators;
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
			operators.push(*str);
		else if (*str == ')')
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
			if(operators.top() == '(')
				operators.pop();
		}

		else if (*str == '^' || *str == '*' || *str == '+' || *str == '-' || *str == '/')
		{
			if (operators.empty())
				operators.push(*str);
			else if (precedence(*str) > precedence(operators.top()))
			{
				operators.push(*str);
			}
			else
			{
				while (!operators.empty() && precedence(operators.top()) >= precedence(*str))
				{
					cout << operators.top();
					operators.pop();
				}
				operators.push(*str);
			}
		}
		else
		{
			cout << "\n Not a valid Infix input expression." << endl;
		}
		str++;
	}
	while (!operators.empty())
	{
		cout << operators.top();
		operators.pop();
	}
}

int main()
{
	//SingleLinkedList * llist = SingleLinkedListOperations();
	//Stack * stack1 = new StackUsingArray();
	//Stack * stack2 = new StackUsingList();
	//StackOperations(stack1);
	//StackOperations(stack2);
	
	//InfixToPostfix();
	//InfixToPostfixChar();

	getchar();
    return 0;
}


SingleLinkedList* SingleLinkedListOperations()
{
	int list_count = 0, data = 0;
	SingleLinkedList* list = new SingleLinkedList();
	cout << "Enter number of nodes in Single Linked List : ";
	cin >> list_count;
	for (int i = 0; i < list_count; i++)
	{
		cin >> data;
		list->InsertInList(data);
	}
	list->PrintList();
	return list;
}

void StackOperations(Stack * sa)
{
	sa->Push(90); sa->Push(10);

	cout << "Element Popped is : " << sa->Pop() << endl;
	cout << "Element Popped is : " << sa->Pop() << endl;

	sa->Push(20); 	sa->Push(10); 	sa->Push(30);	sa->Push(40);
	sa->Push(50);	sa->Push(60);	sa->Push(10);	sa->Push(90);
	sa->PrintStack();
	cout << "Element Popped is : " << sa->Pop() << endl;
	sa->DeleteStack();
}
