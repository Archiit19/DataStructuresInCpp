#include "stdafx.h"
#include "Queue.h"

using namespace std;


QueueUsingArray::QueueUsingArray(int c)
{
	this->capacity = c;
	this->queue_a = new int[capacity];
	front = -1;  rear = -1;
}

bool QueueUsingArray::isFullQueue()
{
	if(size == capacity)
		return true;
	return false;
}

void QueueUsingArray::Enqueue(int data)
{
	if (isFullQueue())
		cout << "Queue Overflow " << endl;
	else
	{
		rear = (rear + 1) % capacity;

		queue_a[rear] = data;
		if (front == -1)
			front = rear;
		size++;
	}
}

int QueueUsingArray::DeQueue()
{
	if (IsEmptyQueue())
	{
		cout << "Queue Underflow " << endl;
	}
	else
	{
		int data = queue_a[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % capacity;
		size--;
		cout << "Element removed from Queue is : " << data << endl;
		return data;
	}
	return -1;
}

int QueueUsingArray::Front()
{
	if(!IsEmptyQueue())
		return queue_a[front];
	else
		cout << "Queue Underflow " << endl;
	return -1;
}

void QueueUsingArray::PrintQueue()
{
	if (IsEmptyQueue())
		cout << "Queue is Empty " << endl;
	else
	{
		cout << "Queue is : ";
		for(int i=0; i<size; i++)
		{
			cout << queue_a[ (front + i) % capacity ] << "  " ;
		}
		cout << endl;
	}

}

void QueueUsingArray::DeleteQueue()
{
	if(queue_a)
		delete(queue_a);
}




template<typename T>
void QueueUsingVector<T>::Enqueue(T data)
{
}

template<typename T>
T QueueUsingVector<T>::DeQueue()
{
	return T();
}

template<typename T>
T QueueUsingVector<T>::Front()
{
	return T();
}

template<typename T>
void QueueUsingVector<T>::PrintQueue()
{
}

template<typename T>
void QueueUsingVector<T>::DeleteQueue()
{
}




template<typename T>
inline void QueueUsingList<T>::Enqueue(T data)
{
}

template<typename T>
inline T QueueUsingList<T>::DeQueue()
{
	return T();
}

template<typename T>
inline T QueueUsingList<T>::Front()
{
	return T();
}

template<typename T>
inline void QueueUsingList<T>::PrintQueue()
{
}

template<typename T>
inline void QueueUsingList<T>::DeleteQueue()
{
}
