#pragma once
#include "ListNode.h"

template<typename T>
class SingleLinkedList
{

private:
	ListNode<T> *head;

public:
	SingleLinkedList();
	SingleLinkedList(ListNode<T> * head);
	
	void PrintList();

	void InsertInList(ListNode<T>* node);
	void InsertInList(T data, int pos);
	void InsertInList(T data);
	
	~SingleLinkedList();
};

