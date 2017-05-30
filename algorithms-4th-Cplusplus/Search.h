#pragma once
#include "Graph.h"
class Search
{
public:
	Search(Graph& g, int s);
	~Search();
	virtual bool Marked(int v) = 0;
	virtual int Count() = 0;
protected:
	Graph& m_G;
	int m_s;
	bool* m_bMarked;
	int m_nCount;
};

Search::Search(Graph& g, int s):m_G(g), m_s(s), m_nCount(0)
{
	m_bMarked = new bool[g.V()];
	for (int i = 0; i < g.V(); i++)
	{
		m_bMarked[i] = false;
	}
}

Search::~Search()
{
	if (m_bMarked)
	{
		delete[] m_bMarked;
	}
}