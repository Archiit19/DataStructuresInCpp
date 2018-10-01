#include "stdafx.h"
#include "Stack.h"

using namespace std;


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




template<typename T>
void StackUsingArray<T>::Push(T data)
{
	stack_a.push_back(data);
	size++;
}

template<typename T>
T StackUsingArray<T>::Pop()
{
	if (!IsEmptyStack())
	{
		T elem_to_pop = stack_a.back();
		stack_a.pop_back();
		size--;
		return elem_to_pop;
	}
	cout << "\nException in popping element : Stack is Empty..!!" << endl;
	return -1;
}

template<typename T>
T StackUsingArray<T>::Top()
{
	if (!IsEmptyStack())
	{
		T elem_to_pop = stack_a.back();
		return elem_to_pop;
	}
	cout << "\nException in popping element : Stack is Empty..!!" << endl;
	return -1;
}

template<typename T>
void StackUsingArray<T>::PrintStack()
{
	cout << "\nStack is : ";
	for (int i = size - 1; i >= 0; i--)
		cout << stack_a[i] << " ";
	cout << endl;
}

template<typename T>
void StackUsingArray<T>::DeleteStack()
{
	stack_a.clear();
	size = 0;
}