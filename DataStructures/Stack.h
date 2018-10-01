#pragma once
#include "ListNode.h"
#include <vector>

//Stacks parent Class - All Stack implementations will be derived from this Class.
class Stack {
protected:
	int size;
public:
	Stack() : size(0) {};
	inline int Size() {	return size; }
	inline bool IsEmptyStack()
	{
		if (size == 0)
			return true;
		return false;
	}
};

//Stack implementation using Vector.
template <typename T>
class StackUsingArray : public Stack
{
private:
	std::vector<T> stack_a;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	void Push(T data);
	T Pop();
	T Top();
	void PrintStack();
	void DeleteStack();
};


//Stack implementation using Linked list.
template <typename T>
class StackUsingList : public Stack
{
private:
	ListNode<T> *top;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	void Push(T data);
	T Pop();
	T Top();
	void PrintStack();
	void DeleteStack();
};
