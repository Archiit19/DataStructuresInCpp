#include "stdafx.h"
#include "SingleLinkedList.h"
#include "ListNode.h"
#include <memory>

using namespace std;

SingleLinkedList::SingleLinkedList()
{
	this->head = nullptr;
}

SingleLinkedList::SingleLinkedList(ListNode * head)
{
	this->head = head;
}

void SingleLinkedList::PrintList()
{
	ListNode* current = this->head;
	cout << "\n Single Linked List is : ";
	while (current != NULL)
	{
		cout << "  " << current->data;
		current = current->next;
	}
	cout << endl;
}

void SingleLinkedList::InsertInList(ListNode * node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	ListNode *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = node;
}

void SingleLinkedList::InsertInList(int data)
{
	ListNode * newNode = new ListNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	ListNode *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
}

void SingleLinkedList::InsertInList(int val, int pos)
{
	int currentPos = 1;
	ListNode *q = NULL;
	ListNode *newNode = new ListNode(val);
	ListNode* p = head;

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
		ListNode* node = head;
		head = head->next;
		free(node);
	}
}

void FreeSingleLinkedList(ListNode* node)
{
	while (node)
	{
		ListNode* temp = node;
		node = node->next;

		free(temp);
	}
}


