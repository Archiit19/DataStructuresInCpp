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




void QueueUsingVector::Enqueue(int data)
{
	queue_a.push_back(data);
}

int QueueUsingVector::DeQueue()
{
	return 0;
}

int QueueUsingVector::Front()
{
	return 0;
}

void QueueUsingVector::PrintQueue()
{
}

void QueueUsingVector::DeleteQueue()
{
}




void QueueUsingList::EnQueue(int data)
{
	ListNode<int> * newNode = new ListNode<int>(data);
	if (rear == NULL)
		rear = newNode;
	else
	{
		rear->next = newNode;
		rear = rear->next;
	}
	if (front == NULL)
		front = rear;
	size++;
}

int QueueUsingList::DeQueue()
{
	if (IsEmptyQueue())
	{
		cout << "Queue Underflow " << endl;
	}
	else
	{
		ListNode<int>* temp = front;
		int temp_data = temp->data;
		front = front->next;
		size--;
		cout << "Element removed from Queue is : " << temp_data << endl;
		delete(temp);
		return temp_data;
	}
	return -1;
}


int QueueUsingList::Front()
{
	if (IsEmptyQueue())
	{
		cout << "Queue is Empty. " << endl;
	}
	else
	{
		cout << "Element removed from Queue is : " << front->data << endl;
		return front->data;
	}
	return -1;
}


void QueueUsingList::PrintQueue()
{
	if (!IsEmptyQueue())
	{
		cout << "The Queue is : ";
		ListNode<int>* temp = front;
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != NULL);
	}
	else
		cout << "Queue is Empty.";
	cout << endl;
}


void QueueUsingList::DeleteQueue()
{
	while (front != NULL)
	{
		ListNode<int> * temp = front;
		front = front->next;
		delete(temp);
	}
}
