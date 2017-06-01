#pragma once
#include "DiGraph.h"
#include "Stack.h"
#include "Queue.h"

class DirectedBFPaths
{
public:
	DirectedBFPaths(DiGraph& G, int s);
	~DirectedBFPaths();
	bool Marked(int v);
	int Count();
	Stack<int> PathTo(int v);
private:
	void BFS(DiGraph& G, int s);
private:
	bool* m_pMarked;
	int* m_edgeTo;
	int m_nCount;
};

DirectedBFPaths::DirectedBFPaths(DiGraph& G, int s):m_pMarked(0), m_edgeTo(0), m_nCount(0)
{
	m_pMarked = new bool[G.V()];
	m_edgeTo = new int[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
		m_edgeTo[i] = i;
	}
	BFS(G, s);
}
DirectedBFPaths::~DirectedBFPaths()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
	if (m_edgeTo)
	{
		delete[] m_edgeTo;
	}
}
bool DirectedBFPaths::Marked(int v)
{
	return m_pMarked[v];
}

int DirectedBFPaths::Count()
{
	return m_nCount;
}

Stack<int> DirectedBFPaths::PathTo(int v)
{
	assert(m_pMarked[v]);
	Stack<int> s;
	while (v != m_edgeTo[v])
	{
		s.Push(v);
		v = m_edgeTo[v];
	}
	s.Push(v);
	return s;
}

void DirectedBFPaths::BFS(DiGraph& G, int s)
{
	Queue<int> q;
	q.Enqueue(s);
	while (!q.IsEmpty())
	{
		int s = q.Dequeue();
		if (!m_pMarked[s])
		{
			m_pMarked[s] = true;
			m_nCount++;
			Bag<int> bagTemp = G.Adj(s);
			for (int i = 0; i < bagTemp.Size(); i++)
			{
				int v = bagTemp.Peek(i);
				if (!m_pMarked[v])
				{
					m_edgeTo[v] = s;
					q.Enqueue(v);
				}
			}
		}
	}
}