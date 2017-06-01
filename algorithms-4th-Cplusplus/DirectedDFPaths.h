#pragma once
#include "DiGraph.h"
#include "Stack.h"
class DirectedDFPaths
{
public:
	DirectedDFPaths(DiGraph& G, int s);
	~DirectedDFPaths();
	bool Marked(int v);
	int Count();
	Stack<int> PathTo(int v);
private:
	void DFS(DiGraph& G, int s);
private:
	bool* m_pMarked;
	int* m_edgeTo;
	int m_nCount;
};

DirectedDFPaths::DirectedDFPaths(DiGraph& G, int s):m_pMarked(0), m_edgeTo(0), m_nCount(0)
{
	m_pMarked = new bool[G.V()];
	m_edgeTo = new int[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
		m_edgeTo[i] = i;
	}
	DFS(G, s);
}

DirectedDFPaths::~DirectedDFPaths()
{
	if (m_pMarked)
	{
		delete [] m_pMarked;
	}
	if (m_edgeTo)
	{
		delete [] m_edgeTo;
	}
}

bool DirectedDFPaths::Marked(int v)
{
	return m_pMarked[v];
}

int DirectedDFPaths::Count()
{
	return m_nCount;
}

Stack<int> DirectedDFPaths::PathTo(int v)
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

void DirectedDFPaths::DFS(DiGraph& G, int s)
{
	m_nCount++;
	m_pMarked[s] = true;
	Bag<int> bagTemp = G.Adj(s);
	for (int i = 0; i < bagTemp.Size(); i++)
	{
		int v = bagTemp.Peek(i);
		if (!m_pMarked[v])
		{
			m_edgeTo[v] = s;
			DFS(G, v);
		}
	}
}