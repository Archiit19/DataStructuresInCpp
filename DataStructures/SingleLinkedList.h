#pragma once
#include "stdafx.h"
#include <memory>
#include "ListNode.h"

using namespace std;

template<class T>
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
	
	// Problem Statement - Functions.
	void SwapPairNodes();

	~SingleLinkedList();
};

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
	this->head = NULL;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(ListNode<T> * head)
{
	this->head = head;
}

template<class T>
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

template<class T>
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

template<class T>
void SingleLinkedList<T>::InsertInList(T data)
{
	ListNode<T> * newNode = new ListNode<T>(data);
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

template<class T>
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
		while (p != NULL && currentPos < pos)
		{
			currentPos++;
			q = p;
			p = p->next;
		}
		q->next = newNode;
		(newNode)->next = q;
	}
}

template<class T>
void SingleLinkedList<T>::SwapPairNodes()
{
	if (head == NULL || head->next == NULL)
		return;

	ListNode<T> *current = head;
	ListNode<T> *prev = NULL;
	ListNode<T> *next = current->next;

	head = next;
	/*
	while (current != NULL)
	{
		
		prev = current;

		if (current->next == NULL)
		break;
		else
		next = current->next;

		current = next->next;

		next->next = prev;
		prev->next = current;
	*/
	while (current != NULL && next != NULL)
	{
		/*Swapping links of nodes*/
		current->next = next->next;
		next->next = current;
		if (prev != NULL)
			prev->next = next;

		/*Updating pointers to next positions*/
		prev = current;
		current = current->next;
		if (current != NULL)
			next = current->next;
	}
}

template<class T>
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