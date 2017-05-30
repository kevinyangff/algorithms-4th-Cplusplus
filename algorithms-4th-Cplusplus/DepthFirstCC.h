#pragma once
#include "CC.h"
class DepthFirstCC:public CC
{
public:
	DepthFirstCC(Graph& g);
	bool Connected(int v, int w) override;
	int Count() override;
	int Id(int v) override;
private:
	void DFCC(Graph& g, int v);
};

DepthFirstCC::DepthFirstCC(Graph& g):CC(g)
{
	int nCount = g.V();
	for (int i= 0; i < nCount; i++)
	{
		if (!m_pMarked[i])
		{
			m_nCount++;
			DFCC(g, i);
		}
	}
}

bool DepthFirstCC::Connected(int v, int w)
{
	return m_pId[v] == m_pId[w];
}

int DepthFirstCC::Count()
{
	return m_nCount;
}

int DepthFirstCC::Id(int v)
{
	return m_pId[v];
}

void DepthFirstCC::DFCC(Graph& g, int i)
{
	m_pMarked[i] = true;
	m_pId[i] = m_nCount - 1;
	Bag<int> b = g.Adj(i);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i);
		if (!m_pMarked[nV])
		{
			DFCC(g, nV);
		}
	}
}
