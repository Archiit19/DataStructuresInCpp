#include "stdafx.h"
#include "StackUsingArray.h"

using namespace std;

bool StackUsingArray::IsEmptyStack()
{
	if(size == 0)
		return true;
	return false;
}

void StackUsingArray::Push(int data)
{
	stack_a.push_back(data);
	size++;
}

int StackUsingArray::Pop()
{
	if (!IsEmptyStack())
	{
		int elem_to_pop = stack_a.back();
		stack_a.pop_back();
		size--;
		return elem_to_pop;
	}
	cout << "\nException in popping element : Stack is Empty..!!"<<endl;
	return -1;
}

void StackUsingArray::PrintStack()
{
	cout << "\nStack is : ";
	for (int i = size-1; i>=0; i--)
		cout << stack_a[i] << " ";
	cout << endl;
}

void StackUsingArray::DeleteStack()
{
	stack_a.clear();
	size = 0;
}