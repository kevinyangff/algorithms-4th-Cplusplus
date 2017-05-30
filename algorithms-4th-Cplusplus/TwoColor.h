#pragma once
#include "Graph.h"
class TwoColor {
public:
	TwoColor(Graph& g);
	~TwoColor();
	virtual bool IsTwoColor() = 0;
protected:
	bool* m_pMarked;
	bool* m_pColor;
	bool m_bTwoColor;
};

TwoColor::TwoColor(Graph& g)
{
	m_bTwoColor = true;
	int nCount = g.V();
	m_pMarked = new bool[nCount];
	m_pColor = new bool[nCount];
	for(int i=0; i<nCount; i++)
	{
		m_pMarked[i] = false;
	}
}

TwoColor::~TwoColor()
{
	if (m_pMarked)
	{
		delete[] m_pMarked;
	}
	if (m_pColor)
	{
		delete[] m_pColor;
	}
}