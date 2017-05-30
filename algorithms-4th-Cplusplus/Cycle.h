#pragma once
#include "Graph.h"
class Cycle {
public:
	Cycle(Graph& g);
	~Cycle();
	virtual bool HasCycle() = 0;
protected:
	Graph& m_G;
	bool* m_pMarked;
	bool m_bHasCycle;
};

Cycle::Cycle(Graph& g) :m_G(g), m_pMarked(0), m_bHasCycle(false)
{
	m_bHasCycle = false;
	m_pMarked = new bool[g.V()];
	for (int i = 0; i < g.V(); i++)
	{
		m_pMarked[i] = false;
	}
}

Cycle::~Cycle()
{
	if(m_pMarked)
	{
		delete[] m_pMarked;
	}
}