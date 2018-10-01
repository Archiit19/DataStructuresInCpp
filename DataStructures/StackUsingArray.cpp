/*

#include "stdafx.h"
#include "StackUsingArray.h"

using namespace std;


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
	cout << "\nException in popping element : Stack is Empty..!!"<<endl;
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
void PrintStack()
{
	cout << "\nStack is : ";
	for (int i = size-1; i>=0; i--)
		cout << stack_a[i] << " ";
	cout << endl;
}

template<typename T>
void DeleteStack()
{
	stack_a.clear();
	size = 0;
}





*/