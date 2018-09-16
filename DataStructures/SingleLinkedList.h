#pragma once
#include "SingleLinkedListNode.h"

class SingleLinkedList
{

public:
	SingleLinkedListNode *head;

	SingleLinkedList();
	SingleLinkedList(SingleLinkedListNode * head);
	
	void PrintList();

	void InsertInList(SingleLinkedListNode* node);
	void InsertInList(int data, int pos);
	void InsertInList(int data);
	
	~SingleLinkedList();
};

