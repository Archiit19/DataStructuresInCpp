#include "stdafx.h"
#include "SingleLinkedList.h"
#include "SingleLinkedListNode.h"
#include <memory>

using namespace std;

SingleLinkedList::SingleLinkedList()
{
	this->head = nullptr;
}

SingleLinkedList::SingleLinkedList(SingleLinkedListNode * head)
{
	this->head = head;
}

void SingleLinkedList::PrintList()
{
	SingleLinkedListNode* current = this->head;
	cout << "\n Single Linked List is : ";
	while (current != NULL)
	{
		cout << "  " << current->data;
		current = current->next;
	}
	cout << endl;
}

void SingleLinkedList::InsertInList(SingleLinkedListNode * node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	SingleLinkedListNode *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = node;
}

void SingleLinkedList::InsertInList(int data)
{
	SingleLinkedListNode * newNode = new SingleLinkedListNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	SingleLinkedListNode *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
}

void SingleLinkedList::InsertInList(int val, int pos)
{
	int currentPos = 1;
	SingleLinkedListNode *q = NULL;
	SingleLinkedListNode *newNode = new SingleLinkedListNode(val);
	SingleLinkedListNode* p = head;

	if (pos == 1)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		while ( p!=NULL && currentPos < pos)
		{
				currentPos++;
				q = p;
				p = p->next;
		}
		q->next = newNode;
		(newNode)->next = q;
	}
}

SingleLinkedList::~SingleLinkedList()
{
	while (head != NULL)
	{
		SingleLinkedListNode* node = head;
		head = head->next;
		free(node);
	}
}

void FreeSingleLinkedList(SingleLinkedListNode* node)
{
	while (node)
	{
		SingleLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}


