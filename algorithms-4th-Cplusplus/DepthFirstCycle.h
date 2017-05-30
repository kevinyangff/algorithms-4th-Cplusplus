#pragma once
#include "Cycle.h"
class DepthFirstCycle :public Cycle
{
public:
	DepthFirstCycle(Graph& g);
	bool HasCycle() override;
private:
	void DFCY(Graph& g, int s, int f);
};

DepthFirstCycle::DepthFirstCycle(Graph& g):Cycle(g)
{
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i] && !m_bHasCycle)
		{
			DFCY(g, i, i);
		}
	}
}
bool DepthFirstCycle::HasCycle()
{
	return m_bHasCycle;
}
void DepthFirstCycle::DFCY(Graph& g, int s, int f)
{
	m_pMarked[s] = true;
	Bag<int> b = g.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i);
		if (!m_pMarked[nV])
		{
			DFCY(g, nV, s);
		}
		else if (nV != f)
		{
			m_bHasCycle = true;
			break;
		}
	}
}