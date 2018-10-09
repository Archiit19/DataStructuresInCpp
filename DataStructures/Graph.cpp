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
		bool insertFlag = true;
		ListNode<int> * current = m_graphNode[src];
		while (current->next != NULL )
		{
			if (current->data == dest)
			{
				insertFlag = false;
				break;
			}
			current = current->next;
		}
		if(insertFlag && current->data != dest)
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
	int v;
	queue<int> q;

	cout << "\nEnter the starting vertex for BFS Traversal : ";
	cin >> v;
	bool * visited = new bool[m_vertices];
	for (int i = 0; i < m_vertices; i++)
		visited[i] = 0;

	q.push(v);
	while (!q.empty())
	{
		int top = q.front(); q.pop();

		if (!visited[top])
		{
			cout << top << "->";
			visited[top] = 1;
		}

		ListNode<int>* temp = m_graphNode[top];
		while (temp)
		{
			if (!visited[temp->data])
				q.push(temp->data);
			temp = temp->next;
		}
	}
}

void Graph::DisplayDFSTraversal()
{
	int v;
	stack<int> s;

	cout << "\nEnter the starting vertex for DFS Traversal : ";
	cin >> v;
	bool * visited = new bool[m_vertices];
	for (int i = 0; i < m_vertices; i++)
		visited[i] = 0;

	s.push(v);
	while (!s.empty())
	{
		int top = s.top(); s.pop();

		if(!visited[top])
		{
			cout << top << "->";
			visited[top] = 1;
		}

		ListNode<int>* temp = m_graphNode[top];
		while (temp)
		{
			if (!visited[temp->data])
				s.push(temp->data);
			temp = temp->next;
		}
	}
}

void Graph::DFSRecursiveHelper(int vertex, bool * visited)
{
	if (!visited[vertex])
	{
		cout << vertex << "->";
		visited[vertex] = true;
		ListNode<int>* temp = m_graphNode[vertex];
		while (temp)
		{
			if (!visited[temp->data])
				DFSRecursiveHelper(temp->data, visited);
			temp = temp->next;
		}
	}
}

void Graph::DFSTraversalRecursive()
{
	int v;
	cout << "\nEnter the starting vertex for DFS Recursive Traversal : ";
	cin >> v;
	bool * visited = new bool[m_vertices];
	for (int i = 0; i < m_vertices; i++)
		visited[i] = false;
	cout << "The Recursive DFS Traversal is : ";
    DFSRecursiveHelper(v, visited);
}

void Graph::ShortestPathUnWeightedPath()
{
	int sourceVertex;
	cout << "\nEnter the source vertex to find shortest path : ";
	cin >> sourceVertex;
	cout << "\nShortest distance of Vertices from "<<endl;
	int * distance = new int[m_vertices];
	for (int i = 0; i < m_vertices; i++)
	{
		if (sourceVertex == i)
			distance[i] = 0;
		else
			distance[i] = -1;
	}
	ListNode<int>* temp = m_graphNode[sourceVertex];
	while (temp != NULL)
		distance[temp->data] = 1;

	for (int i = 0; i < m_vertices; i++)
	{
		if (distance[i] < 0)
		{

		}
	}
	
}
