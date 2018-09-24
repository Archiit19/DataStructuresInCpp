// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListNode.h"
#include "SingleLinkedList.h"
#include "StackUsingArray.h"
#include "StackUsingList.h"
#include "Stack.h"

using namespace std;

SingleLinkedList* SingleLinkedListOperations();
void StackOperations(Stack * sa);

int main()
{
	//SingleLinkedList * llist = SingleLinkedListOperations();
	Stack * stack1 = new StackUsingArray();
	Stack * stack2 = new StackUsingList();
	StackOperations(stack1);
	StackOperations(stack2);

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
