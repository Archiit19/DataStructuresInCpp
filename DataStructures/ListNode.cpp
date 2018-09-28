#include "stdafx.h"
#include "ListNode.h"

using namespace std;

template <typename T>
ListNode<T>::ListNode(T data)
{
	this->data = data;
	this->next = NULL;
}

