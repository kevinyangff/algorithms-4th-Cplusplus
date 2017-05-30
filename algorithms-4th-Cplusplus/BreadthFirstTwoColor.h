#pragma once
#include "TwoColor.h"
#include "Queue.h"
class BreadthFirstTwoColor :public TwoColor {
public:
	BreadthFirstTwoColor(Graph& g);
	bool IsTwoColor() override;
private:
	void BFTC(Graph& g, int s);
};

BreadthFirstTwoColor::BreadthFirstTwoColor(Graph& g) :TwoColor(g)
{
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i] && m_bTwoColor)
		{
			BFTC(g, i);
		}
	}
}

bool BreadthFirstTwoColor::IsTwoColor()
{
	return m_bTwoColor;
}

void BreadthFirstTwoColor::BFTC(Graph& g, int s)
{
	Queue<int> q;
	q.Enqueue(s);
	while (!q.IsEmpty() && m_bTwoColor)
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
					m_pColor[b.Peek(i)] = !m_pColor[nV];
					q.Enqueue(b.Peek(i));
				}
			}
		}
		else
		{
			Bag<int> b = g.Adj(nV);
			for (int i = 0; i < b.Size(); i++)
			{
				if (m_pColor[nV] == m_pColor[b.Peek(i)])
				{
					m_bTwoColor = false;
					break;
				}
			}
		}
	}
}