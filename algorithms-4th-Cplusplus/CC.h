#pragma once
#include "Graph.h"
class CC
{
public:
	CC(Graph& g);
	~CC();
	virtual bool Connected(int v, int w) = 0;
	virtual int Count() = 0;
	virtual int Id(int v) = 0;
protected:
	Graph& m_G;
	int m_nCount;
	int* m_pId;
	bool* m_pMarked;
};

CC::CC(Graph& g) :m_G(g), m_pId(0), m_pMarked(0)
{
	m_nCount = g.V();
	m_pId = new int[m_nCount];
	m_pMarked = new bool[m_nCount];
	for (int i = 0; i < m_nCount; i++)
	{
		m_pId[i] = i;
		m_pMarked[i] = false;
	}
	m_nCount = 0;
}

CC::~CC()
{
	if (m_pId)
	{
		delete[] m_pId;
	}
}