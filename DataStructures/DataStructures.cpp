// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SingleLinkedListNode.h"
#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

void SingleLinkedListFunctions();


int main()
{
	SingleLinkedListFunctions();


	getchar();
    return 0;
}


void SingleLinkedListFunctions()
{
	int list_count = 0, data = 0;
	{
	SingleLinkedList* list = new SingleLinkedList();
	cout << "Enter number of nodes in Single Linked List : ";
	cin >> list_count;
	for (int i = 0; i < list_count; i++)
	{
		cin >> data;
		list->InsertInList(data);
	}
	list->PrintList();
	}
}