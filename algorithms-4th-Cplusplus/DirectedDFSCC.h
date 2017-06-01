#pragma once
#include "DirectedDFOrder.h"
#include "DiGraph.h"
class DirectedDFSCC
{
public:
	DirectedDFSCC(DiGraph& g);
	~DirectedDFSCC();
	int Count();
	int Id(int v);
	bool StronglyConnected(int v, int w);
private:
	void DFSCC(DiGraph& g, int s);
private:
	bool* m_pMarked;
	int m_nCount;
	int* m_pId;
};

DirectedDFSCC::DirectedDFSCC(DiGraph& g):m_nCount(0)
{
	m_pMarked = new bool[g.V()];
	m_pId = new int[g.V()];
	for (int i = 0; i < g.V(); i++)
	{
		m_pMarked[i] = false;
		m_pId[i] = i;
	}
	Stack<int> s = DirectedDFOrder(g.reverse()).ReversePost();
	while (!s.IsEmpty())
	{
		int v = s.Pop();
		if(!m_pMarked[v])
		{
			m_nCount++;
			DFSCC(g, v);
		}
	}
}

DirectedDFSCC::~DirectedDFSCC()
{
	if (m_pId)
	{
		delete [] m_pId;
	}
	if (m_pMarked)
	{
		delete [] m_pMarked;
	}
}

int DirectedDFSCC::Count()
{
	return m_nCount;
}
int DirectedDFSCC::Id(int v)
{
	return m_pId[v];
}
bool DirectedDFSCC::StronglyConnected(int v, int w)
{
	return m_pId[v] == m_pId[w];
}

void DirectedDFSCC::DFSCC(DiGraph& g, int s)
{
	m_pMarked[s] = true;
	m_pId[s] = m_nCount-1;
	Bag<int> b = g.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i);
		if (!m_pMarked[nV])
		{
			DFSCC(g, nV);
		}
	}
}