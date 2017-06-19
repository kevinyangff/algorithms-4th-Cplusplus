#pragma once
#include "DiGraph.h"
class DirectedDFSearch
{
public:
	DirectedDFSearch(DiGraph& G, int s);
	DirectedDFSearch(DiGraph& G, Bag<int> b);
	~DirectedDFSearch();
	bool Marked(int v);
	int Count();
private:
	void DFS(DiGraph& G, int s);
private:
	bool* m_pMarked;
	int m_nCount;
};

DirectedDFSearch::DirectedDFSearch(DiGraph& G, int s):m_pMarked(0), m_nCount(0)
{
	m_pMarked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
	}
	DFS(G, s);
}
DirectedDFSearch::DirectedDFSearch(DiGraph& G, Bag<int> b) :m_pMarked(0), m_nCount(0)
{
	m_pMarked = new bool[G.V()];
	for (int i = 0; i < G.V(); i++)
	{
		m_pMarked[i] = false;
	}
	if (b.IsEmpty())
	{
		DFS(G, 0);
	}
	else
	{
		for (int i = 0; i < b.Size(); i++)
		{
			if (!m_pMarked[b.Peek(i)])
			{
				DFS(G, b.Peek(i));
			}
		}
	}
}
DirectedDFSearch::~DirectedDFSearch()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
}
bool DirectedDFSearch::Marked(int v)
{
	return m_pMarked[v];
}

int DirectedDFSearch::Count()
{
	return m_nCount;
}

void DirectedDFSearch::DFS(DiGraph& G, int s)
{
	m_nCount++;
	m_pMarked[s] = true;
	Bag<int> bagTemp = G.Adj(s);
	for (int i = 0; i < bagTemp.Size(); i++)
	{
		if (!m_pMarked[bagTemp.Peek(i)])
		{
			DFS(G, bagTemp.Peek(i));
		}
	}
}