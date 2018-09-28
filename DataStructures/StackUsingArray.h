#pragma once
#include "stdafx.h"
#include "Stack.h"
#include <vector>

//Stack implementation using Vector.
template <typename T>
class StackUsingArray : public Stack
{
private:
	std::vector<T> stack_a;

public:
	// Implementation of these functions inherited from "Stack" Base Class.
	bool IsEmptyStack();
	void Push(T data);
	T Pop();
	void PrintStack();
	void DeleteStack();
	T Top();
};