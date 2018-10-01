#pragma once
#include "ListNode.h"
#include <vector>

// Queue Parent Class - All Queue implementations will be derived from this Class.
class Queue {
protected:
	int size;
public:
	Queue() : size(0) {};
	inline int Size() { return size; }
	inline bool IsEmptyQueue()
	{
		if (size == 0)
			return true;
		return false;
	}
};

// Queue implementation using Array.
class QueueUsingArray : public Queue
{
private:
	int* queue_a;
	int capacity, front, rear;
public:
	// Implementation of some functions is nherited from "Queue" Base Class.
	// Capacity - Maximum number of elements in Queue.
	QueueUsingArray(int c);
	bool isFullQueue();
	void Enqueue(int data);
	int DeQueue();
	int Front();
	void PrintQueue();
	void DeleteQueue();
};


// Queue implementation using Vector.
template <typename T>
class QueueUsingVector : public Queue
{
private:
	std::vector<T> queue_a;

public:
	// Implementation of some functions is inherited from "Queue" Base Class.
	void Enqueue(T data);
	T DeQueue();
	T Front();
	void PrintQueue();
	void DeleteQueue();
};


// Queue implementation using Linked list.
template <typename T>
class QueueUsingList : public Queue
{
private:
	ListNode<T> *top;

public:
	// Implementation of some functions is inherited from "Queue" Base Class.
	void Enqueue(T data);
	T DeQueue();
	T Front();
	void PrintQueue();
	void DeleteQueue();
};

