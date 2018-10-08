#include "stdafx.h"
#include "Graph.h"


using namespace std;

void Graph::AcceptInput()
{
	int edges, source, destination;
	cout << "\nEnter the number of Edges in Graph : ";
	cin >> edges; 
	for (int i = 0; i < edges; i++)
	{
		cout << "\nEnter the Pair(source , destination) for connected edges : ";
		cin >> source;
		cin >> destination;
		AddEdge(source, destination);
		AddEdge(destination, source);
	}
}

void Graph::AddEdge(int src, int dest)
{
	if(m_graphNode[src] == NULL)
		m_graphNode[src] = new ListNode<int>(dest);
	else
	{
		ListNode<int> * current = m_graphNode[src];
		while (current->next != NULL)
			current = current->next;
		current->next = new ListNode<int>(dest);
	}
}

void Graph::SimpleDisplay()
{
	
	for (int i = 0; i < m_vertices; i++)
	{
		ListNode<int>* temp = m_graphNode[i];
		cout << i<< "->" << "\t" ;
		while (temp)
		{
			cout << temp->data <<"->";
			temp = temp->next;
		}
		cout << "\n";
	}
}

void Graph::DisplayBFSTraversal()
{

}

void Graph::DisplayDFSTraversal()
{
}
