#include "stdafx.h"
#include "StackUsingList.h"

using namespace std;

bool StackUsingList::IsEmptyStack()
{
	if (top == NULL)
		return true;
	return false;
}

void StackUsingList::Push(int data)
{
	ListNode * newNode = new ListNode(data);
	ListNode * temp = top;
	top = newNode;
	top->next = temp;
	size++;
}

int StackUsingList::Pop()
{
	if (!IsEmptyStack())
	{
		ListNode * topNode = top;
		int topData = topNode->data;
		top = top->next;
		delete topNode;
		size--;
		return topData;
		
	}
	cout << "Exception in Popping element from a Empty Stack..!!" << endl;
	return -1;
}

void StackUsingList::PrintStack()
{
	ListNode * current = top;
	cout << "\nStack is : ";
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void StackUsingList::DeleteStack()
{
	while (top != NULL)
	{
		ListNode * temp = top;
		top = top->next;
		delete temp;
	}
}
 