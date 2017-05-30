#pragma once
#include "Graph.h"
#include "Stack.h"
class Paths
{
public:
	Paths(Graph& g, int s);
	~Paths();
	virtual bool Marked(int v) = 0;
	virtual int Count() = 0;
	virtual Stack<int> PathTo(int v) = 0;
protected:
	Graph& m_G;
	int m_s;
	bool* m_bMarked;
	int* m_edgeTo;
	int m_nCount;
};

Paths::Paths(Graph& g, int s) :m_G(g), m_s(s), m_nCount(0), m_edgeTo(0)
{
	m_bMarked = new bool[g.V()];
	m_edgeTo = new int[g.V()];
	for (int i = 0; i < g.V(); i++)
	{
		m_bMarked[i] = false;
		m_edgeTo[i] = i;
	}
}

Paths::~Paths()
{
	if (m_bMarked)
	{
		delete[] m_bMarked;
	}
	if (m_edgeTo)
	{
		delete[] m_edgeTo;
	}
}