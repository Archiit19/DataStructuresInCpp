// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ListNode.h"
#include "SingleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "GraphUsingAdjacencyList.h"
#include "GraphUsingAdjacencyMatrix.h"
#include "Heap.h"
#include "DisjointSet.h"

using namespace std;

void SingleLinkedListOperations()
{
	SingleLinkedList<int> list;
	int list_count = 0, data = 0;
	cout << "Enter number of nodes in Single Linked List : ";
	cin >> list_count;
	for (int i = 0; i < list_count; i++)
	{
		cin >> data;
		list.InsertInList(data);
	}
	list.PrintList();
	list.SwapPairNodes();
	list.PrintList();

}

// Returns precedence of operators.
int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Using STL Stack - stack and STL string.
void InfixToPostfix()
{
	string infixStr;
	stack<char> operators;
	cout << "Enter the Infix Expression (without spaces) : ";
	cin >> infixStr;
	cout << endl;
	for (unsigned int i = 0; i < infixStr.length(); i++)
	{
		if ((infixStr[i]>='a' && infixStr[i]<='z') || (infixStr[i]>='A' && infixStr[i]<='Z'))
		{
			cout << infixStr[i];
		}

		else if (infixStr[i] == '(')
			operators.push(infixStr[i]);

		else if (infixStr[i] == ')')
		{
			while (operators.top() != '(')
			{
				cout << operators.top();
				operators.pop();
			}
			if (operators.empty())
			{
				cout << "\nInvalid Infix Expression." << endl;
				return;
			}
			if (operators.top() == '(')
				operators.pop();
		}
		else if (infixStr[i] == '^' || infixStr[i] == '*' || infixStr[i] == '+' || infixStr[i] == '-' || infixStr[i] == '/')
		{
			if (operators.empty())
				operators.push(infixStr[i]);
			else if (precedence(infixStr[i]) > precedence(operators.top()))
			{
				operators.push(infixStr[i]);
			}
			else
			{
				while (!operators.empty() && precedence(operators.top()) >= precedence(infixStr[i]))
				{
					cout << operators.top();
					operators.pop();
				}
				operators.push(infixStr[i]);
			}
		}
		else
		{
			cout << "\n Not a valid Infix input expression." << endl;
		}
	}
	while (!operators.empty())
	{
		cout<<operators.top();
		operators.pop();
	}
}

// Using defined StackUsingArray and Char *
/*
void InfixToPostfixChar()
{
	char * str = (char *)malloc(100);
	for (int i = 0; i < 100; i++)
	{
		str[i] = '\0';
	}
	StackUsingArray<char> operators;
	cout << "Enter the Infix Expression (without spaces) : ";
	cin >> str;
	cout << "\nPostfix Expression is : " ;
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'a' && *str <= 'z'))
		{
			cout << *str;
		}

		else if (*str == '(')
			operators.Push(*str);
		else if (*str == ')')
		{
			while (operators.Top() != '(')
			{
				cout << operators.Pop();
			}
			if (operators.IsEmptyStack())
			{
				cout << "\nInvalid Infix Expression." << endl;
				return;
			}
			if(operators.Top() == '(')
				operators.Pop();
		}

		else if (*str == '^' || *str == '*' || *str == '+' || *str == '-' || *str == '/')
		{
			if (operators.IsEmptyStack())
				operators.Push(*str);
			else if (precedence(*str) > precedence(operators.Top()))
			{
				operators.Push(*str);
			}
			else
			{
				while (!operators.IsEmptyStack() && precedence(operators.Top()) >= precedence(*str))
				{
					cout << operators.Pop();
				}
				operators.Push(*str);
			}
		}
		else
		{
			cout << "\n Not a valid Infix input expression." << endl;
		}
		str++;
	}
	while (!operators.IsEmptyStack())
	{
		cout << operators.Pop();
	}
}
*/

// Using defined StackUsingArray.
/*
void PostfixEvaluation()
{
	cout << "Enter Postfix Expression : ";
	string postfixStr;
	StackUsingArray<int> evalStack;
	cin >> postfixStr;
	int left, right, newVal;

	for (unsigned int i = 0; i<postfixStr.length(); i++)
	{
		if (postfixStr[i] >= '0' && postfixStr[i] <= '9')
			evalStack.Push(postfixStr[i] - '0'); // Converting char to int.

		else if (postfixStr[i] == '+' || postfixStr[i] == '-' || postfixStr[i] == '*' || postfixStr[i] == '/')
		{
			right = evalStack.Pop();
			left = evalStack.Pop();
			switch (postfixStr[i])
			{
				case '+': newVal = left + right; break;
				case '-': newVal = left - right; break;
				case '*': newVal = left * right; break;
				case '/': newVal = left / right; break;
			}
			evalStack.Push(newVal);
		}

		else
		{
			cout << "Invalid Postfix Expression." << endl;
			break;
		}
	}
	if (evalStack.Size() == 1)
		cout << evalStack.Pop() << endl;
	else
		cout << "Invalid Stack State." << endl;
}
*/
void StackOperations(Stack * sa)
{
	InfixToPostfix();
	//InfixToPostfixChar();
	//PostfixEvaluation();
}

void QueueOperations()
{
	QueueUsingArray qa(10);
	qa.Enqueue(10);	qa.Enqueue(20);	qa.Enqueue(30);	qa.Enqueue(40);	qa.Enqueue(50);	qa.Enqueue(60);	qa.Enqueue(70);	qa.Enqueue(80);
	qa.PrintQueue();
	qa.DeQueue(); qa.DeQueue();	qa.DeQueue();	qa.DeQueue();	qa.DeQueue();
	qa.PrintQueue();
	qa.Enqueue(10);	qa.Enqueue(20);	qa.Enqueue(30);	qa.Enqueue(40);	qa.Enqueue(50);	qa.Enqueue(60);	qa.Enqueue(70);	qa.Enqueue(80);
	qa.PrintQueue();
	qa.DeQueue();	qa.DeQueue();	qa.DeQueue();	qa.DeQueue();	qa.DeQueue(); qa.DeQueue(); qa.DeQueue(); qa.DeQueue();
	qa.PrintQueue();
	qa.Enqueue(10);	qa.Enqueue(20);	qa.Enqueue(30);	qa.Enqueue(40);	qa.Enqueue(50);	qa.Enqueue(60);	qa.Enqueue(70);	qa.Enqueue(80);
	qa.PrintQueue();
	
	QueueUsingList qL;
	qL.EnQueue(10);	qL.EnQueue(20);	qL.EnQueue(30);	qL.EnQueue(40);	qL.EnQueue(50);	qL.EnQueue(60);	qL.EnQueue(70);	qL.EnQueue(80);
	qL.PrintQueue();
	qL.DeQueue(); qL.DeQueue();	qL.DeQueue();	qL.DeQueue();	qL.DeQueue();
	qL.PrintQueue();
	qL.EnQueue(10);	qL.EnQueue(20);	qL.EnQueue(30);	qL.EnQueue(40);	qL.EnQueue(50);	qL.EnQueue(60);	qL.EnQueue(70);	qL.EnQueue(80);
	qL.PrintQueue();
	qL.DeQueue();	qL.DeQueue();	qL.DeQueue();	qL.DeQueue();	qL.DeQueue(); qL.DeQueue(); qL.DeQueue(); qL.DeQueue(); qL.DeQueue(); qL.DeQueue(); qL.DeQueue();
	qL.PrintQueue();
	qL.EnQueue(10);	qL.EnQueue(20);	qL.EnQueue(30);	qL.EnQueue(40);	qL.EnQueue(50);	qL.EnQueue(60);	qL.EnQueue(70);	qL.EnQueue(80);
	qL.PrintQueue();
	
}

bool AreMirrors(TreeNode * A, TreeNode *B)
{
	if (A == NULL && B == NULL)
		return 1;
	else if (A == NULL || B == NULL)
		return 0;
	else if (A->data != B->data)
		return 0;
	else
		return AreMirrors(A->left, B->right) && AreMirrors(A->right, B->left);
}

TreeNode* MakeMirrorTree(TreeNode * root)
{
	if (root)
	{
		MakeMirrorTree(root->left);
		MakeMirrorTree(root->right);

		TreeNode * temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

void BinaryTreeOperations()
{

	BinaryTree aTree;
	BinaryTree bTree;
	aTree.Insert(1);	aTree.Insert(2);	aTree.Insert(3); 	aTree.Insert(4);	aTree.Insert(5);  	aTree.Insert(6);  	aTree.Insert(7);
	bTree.Insert(1);	bTree.Insert(2);	bTree.Insert(3);	bTree.Insert(4);	bTree.Insert(5);	bTree.Insert(6);	bTree.Insert(7);

	aTree.InOrderTraversal(); cout << endl;
	aTree.InOrderTraversalIterative(); cout << endl;
	aTree.PreOrderTraversal(); cout << endl;
	aTree.PreOrderTraversalIterative(); cout << endl;
	aTree.PostOrderTraversal(); cout << endl;
	aTree.PostOrderTraversalIterativeDSBook(); cout << endl;
	aTree.PostOrderTraversalIterativeGFGOneStsack(); cout << endl;
	aTree.PostOrderTraversalIterativeGFGTwoStsacks(); cout << endl;
	
	aTree.LevelOrderTraversal(); cout << endl;
	aTree.ReverseLevelOrderTraversal(); cout << endl;

	aTree.FindMaxElementIterative(); cout << endl;
	aTree.FindMaxElementRecursive(); cout << endl;
	
	aTree.Size(); cout << endl;
	aTree.SizeUsingRecursion(); cout << endl;

	if (AreMirrors(aTree.root, bTree.root))
		cout << "\n Mirror Trees";
	else
		cout << "\nNot Mirror Trees. ";

	TreeNode * newMirroredRootNode = MakeMirrorTree(aTree.root);
	BinaryTree newTree(newMirroredRootNode);

	newTree.InOrderTraversal(); cout << endl;
	newTree.LevelOrderTraversal(); cout << endl;
	newTree.ReverseLevelOrderTraversal(); cout << endl;
}

void BinarySearchTreeOperations()
{
	BinarySearchTree aTree;
	BinarySearchTree bTree;
	aTree.Insert(1);	aTree.Insert(2);	aTree.Insert(3); 	aTree.Insert(4);	aTree.Insert(5);  	aTree.Insert(6);  	aTree.Insert(7);
	bTree.Insert(1);	bTree.Insert(2);	bTree.Insert(3);	bTree.Insert(4);	bTree.Insert(5);	bTree.Insert(6);	bTree.Insert(7);

	aTree.InOrderTraversal(); cout << endl;
	aTree.InOrderTraversalIterative(); cout << endl;
	aTree.PreOrderTraversal(); cout << endl;
	aTree.PreOrderTraversalIterative(); cout << endl;
	aTree.PostOrderTraversal(); cout << endl;
	aTree.PostOrderTraversalIterativeDSBook(); cout << endl;
	aTree.PostOrderTraversalIterativeGFGOneStsack(); cout << endl;
	aTree.PostOrderTraversalIterativeGFGTwoStsacks(); cout << endl;

	aTree.LevelOrderTraversal(); cout << endl;
	aTree.ReverseLevelOrderTraversal(); cout << endl;

	aTree.FindMaxElementIterative(); cout << endl;
	aTree.FindMaxElementRecursive(); cout << endl;

	aTree.Size(); cout << endl;
	aTree.SizeUsingRecursion(); cout << endl;
	
	aTree.FindMaxElementIterative(); cout << endl;
	aTree.Delete(6);
	aTree.InOrderTraversal(); cout << endl;
	aTree.Delete(2);
	aTree.InOrderTraversal(); cout << endl;

}

void GraphUsingAdjacencyListOperations()
{
	int n;
	cout << "Enter the number of vertices in Graph : ";
	cin >> n;
	GraphUsingAdjancencyList g(n);
	g.AcceptInput();
	g.SimpleDisplay();
	g.DisplayDFSTraversal();
	g.DisplayBFSTraversal();
	g.DFSTraversalRecursive();
	g.ShortestPathUnWeightedPath();
}

void GraphUsingAdjacencyMatrixOperations()
{
	int n;
	cout << "Enter the number of vertices in Graph : ";
	cin >> n;
	GraphUsingAdjancencyMatrix g(n);
	g.AcceptInput();
	g.SimpleDisplay();
	g.ShortestPathWeighted();
}

void HeapOperations()
{

	Heap h1(MaxHeap);  // Use "MinHeap" to create MinHeap ins place of MaxHeap. 
	h1.Insert(20);
	h1.Insert(50);
	h1.Insert(10);
	h1.Insert(15);
	h1.Insert(18);
	h1.Insert(80);
	h1.Insert(100);
	h1.Insert(5);
	h1.PrintHeap();
	cout << h1.Delete() << endl;
	h1.PrintHeap();
	h1.Insert(2);
	h1.PrintHeap();
	cout << h1.Delete() << endl;
	h1.PrintHeap();
}

void DisjointSetOperations()
{
	DisjointSetQuickUnionSlowFind dsQF(10);
	dsQF.Union(1, 6);
	dsQF.Union(2, 7);
	dsQF.Union(3, 5);
	dsQF.Union(1, 2);
	dsQF.Union(0, 9);
	dsQF.Union(0, 3);
	cout << dsQF.Find(0, 6);
	cout << dsQF.Find(0, 1);
	cout << dsQF.Find(1, 7);
	cout << dsQF.Find(1, 8);
	cout << dsQF.Find(3, 9);


}


int main()
{
	SingleLinkedListOperations();

	//Stack* stack1 = new StackUsingArray<int>();
	//Stack* stack2 = new StackUsingList<int>();
	
	//StackOperations(stack1);
	//StackOperations(stack2);
	
	//QueueOperations();
	
	//BinaryTreeOperations();
	//BinarySearchTreeOperations();

	//GraphUsingAdjacencyListOperations();
	//GraphUsingAdjacencyMatrixOperations();
	
	//Heap Operations();

	//DisjointSetOperations();

	getchar();
	return 0;

}




