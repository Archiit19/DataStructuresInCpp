#include "stdafx.h"
#include "SingleLinkedList.h"
#include "ListNode.h"
#include <memory>

using namespace std;

template<typename T>
SingleLinkedList<T>::SingleLinkedList()
{
	this->head = nullptr;
}

template<typename T>
SingleLinkedList<T>::SingleLinkedList(ListNode<T> * head)
{
	this->head = head;
}

template<typename T>
void SingleLinkedList<T>::PrintList()
{
	ListNode<T>* current = this->head;
	cout << "\n Single Linked List is : ";
	while (current != NULL)
	{
		cout << "  " << current->data;
		current = current->next;
	}
	cout << endl;
}

template<typename T>
void SingleLinkedList<T>::InsertInList(ListNode<T> * node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	ListNode<T> *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = node;
}

template<typename T>
void SingleLinkedList<T>::InsertInList(T data)
{
	ListNode<T> * newNode = new ListNode(data);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	ListNode<T> *current = this->head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
}

template<typename T>
void SingleLinkedList<T>::InsertInList(T val, int pos)
{
	int currentPos = 1;
	ListNode<T> *q = NULL;
	ListNode<T> *newNode = new ListNode(val);
	ListNode<T> * p = head;

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

template<typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	while (head != NULL)
	{
		ListNode<T>* node = head;
		head = head->next;
		free(node);
	}
}

// Independent Function - Not a Class member.
template<typename T>
void FreeSingleLinkedList(ListNode<T>* node)
{
	while (node)
	{
		ListNode<T>* temp = node;
		node = node->next;
		free(temp);
	}
}


