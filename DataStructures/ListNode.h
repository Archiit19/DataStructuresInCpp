#pragma once

template <class T>
class ListNode
{
public:
	T data;
	ListNode<T> * next;

	ListNode(T data)
	{
		this->data = data;
		this->next = NULL;
	}
};

