#pragma once
#include "ListNode.h"

class SingleLinkedList
{

private:
	ListNode *head;

public:
	SingleLinkedList();
	SingleLinkedList(ListNode * head);
	
	void PrintList();

	void InsertInList(ListNode* node);
	void InsertInList(int data, int pos);
	void InsertInList(int data);
	
	~SingleLinkedList();
};

