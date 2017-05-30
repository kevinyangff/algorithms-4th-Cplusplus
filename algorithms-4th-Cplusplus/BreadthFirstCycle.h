#pragma once
#include "Cycle.h"
#include "Queue.h"
class BreadthFirstCycle :public Cycle
{
public:
	BreadthFirstCycle(Graph& g);
	bool HasCycle() override;
private:
	void DFCY(Graph& g, int s);
};

BreadthFirstCycle::BreadthFirstCycle(Graph& g) :Cycle(g)
{
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i] && !m_bHasCycle)
		{
			DFCY(g, i);
		}
	}
}
bool BreadthFirstCycle::HasCycle()
{
	return m_bHasCycle;
}
void BreadthFirstCycle::DFCY(Graph& g, int s)
{
	Queue<int> q;
	q.Enqueue(s);
	while (!q.IsEmpty() && !m_bHasCycle)
	{
		int nV = q.Dequeue();
		if (!m_pMarked[nV])
		{
			m_pMarked[nV] = true;
			Bag<int> b = g.Adj(nV);
			for (int i = 0; i < b.Size(); i++)
			{
				if (!m_pMarked[b.Peek(i)])
				{
					q.Enqueue(b.Peek(i));
				}
			}
		}
		else
		{
			m_bHasCycle = true;
			break;
		}
	}
}