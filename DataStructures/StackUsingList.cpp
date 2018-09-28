#include "stdafx.h"
#include "StackUsingList.h"

using namespace std;

template <typename T>
bool StackUsingList<T>::IsEmptyStack()
{
	if (top == NULL)
		return true;
	return false;
}

template <typename T>
void StackUsingList<T>::Push(T data)
{
	ListNode<T> * newNode = new ListNode(data);
	ListNode<T> * temp = top;
	top = newNode;
	top->next = temp;
	size++;
}

template <typename T>
T StackUsingList<T>::Pop()
{
	if (!IsEmptyStack())
	{
		ListNode<T> * topNode = top;
		T topData = topNode->data;
		top = top->next;
		delete topNode;
		size--;
		return topData;	
	}
	cout << "Exception in Popping element from a Empty Stack..!!" << endl;
	return -1;
}

template<typename T>
T StackUsingList<T>::Top()
{
	if (!IsEmptyStack())
	{
		ListNode<T> * topNode = top;
		T topData = topNode->data;
		return topData;
	}
	cout << "Exception in Popping element from a Empty Stack..!!" << endl;
	return -1;
}

template <typename T>
void StackUsingList<T>::PrintStack()
{
	ListNode<T> * current = top;
	cout << "\nStack is : ";
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template <typename T>
void StackUsingList<T>::DeleteStack()
{
	while (top != NULL)
	{
		ListNode<T> * temp = top;
		top = top->next;
		delete temp;
	}
}


 