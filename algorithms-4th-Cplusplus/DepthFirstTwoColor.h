#pragma once
#include "TwoColor.h"
class DepthFirstTwoColor:public TwoColor {
public:
	DepthFirstTwoColor(Graph& g);
	bool IsTwoColor() override;
private:
	void DFTC(Graph& g, int s);
};

DepthFirstTwoColor::DepthFirstTwoColor(Graph& g) :TwoColor(g)
{
	int nCount = g.V();
	for (int i = 0; i < nCount; i++)
	{
		if (!m_pMarked[i] && m_bTwoColor)
		{
			DFTC(g, i);
		}
	}
}

bool DepthFirstTwoColor::IsTwoColor()
{
	return m_bTwoColor;
}

void DepthFirstTwoColor::DFTC(Graph& g, int s)
{
	m_pMarked[s] = true;
	Bag<int> b = g.Adj(s);
	for (int i = 0; i < b.Size(); i++)
	{
		int nV = b.Peek(i);
		if (!m_pMarked[nV])
		{
			m_pColor[nV] = !m_pColor[s];
			DFTC(g, nV);
		}
		else if (m_pColor[nV]==m_pColor[s])
		{
			m_bTwoColor = false;
			break;
		}
	}
}