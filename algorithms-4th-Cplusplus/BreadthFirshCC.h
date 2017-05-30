#pragma once
#include "CC.h"
#include "Queue.h"
class BreadthFirstCC :public CC
{
public:
	BreadthFirstCC(Graph& g);
	bool Connected(int v, int w) override;
	int Count() override;
	int Id(int v) override;
private:
	void BFCC(Graph& g, int v);
};

BreadthFirstCC::BreadthFirstCC(Graph& g) :CC(g)
{
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i])
		{
			m_nCount++;
			BFCC(g, i);
		}
	}
}

bool BreadthFirstCC::Connected(int v, int w)
{
	return m_pId[v] == m_pId[w];
}

int BreadthFirstCC::Count()
{
	return m_nCount;
}

int BreadthFirstCC::Id(int v)
{
	return m_pId[v];
}

void BreadthFirstCC::BFCC(Graph& g, int v)
{
	Queue<int> q;
	q.Enqueue(v);
	while(!q.IsEmpty())
	{
		int nV = q.Dequeue();
		if (!m_pMarked[nV])
		{
			m_pMarked[nV] = true;
			m_pId[nV] = m_nCount - 1;
			Bag<int> b = g.Adj(nV);
			for (int i = 0; i < b.Size(); i++)
			{
				nV = b.Peek(i);
				if (!m_pMarked[nV])
				{
					q.Enqueue(nV);
				}
			}
		}
	}
}
