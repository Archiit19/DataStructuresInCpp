#pragma once
#include "ListNode.h"

//Stacks parent Class - All Stack implementations will be derived from this file.
class Stack {

protected:
	int size;

public:
	Stack() : size(0) {};
	virtual bool IsEmptyStack() = 0;
	virtual void PrintStack() = 0;
	virtual void DeleteStack() = 0;
	inline int Size()
	{
		return size;
	}

};