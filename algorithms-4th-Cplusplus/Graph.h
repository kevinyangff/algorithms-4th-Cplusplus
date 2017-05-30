#pragma once
#include "Bag.h"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
class Graph
{
public:
	Graph(int V);
	Graph(istream& ist);
	~Graph();
	int V();
	int E();
	void AddEdge(int v, int w);
	Bag<int> Adj(int v);
	void Show();
private:
	Bag<int>* m_pBag;
	int m_nV;
	int m_nE;
};

Graph::Graph(int V):m_pBag(0), m_nV(0), m_nE(0)
{
	assert(V > 0);
	m_pBag = new Bag<int>[V];
	m_nV = V;
}

Graph::Graph(istream& ist) :m_pBag(0), m_nV(0), m_nE(0)
{
	ist >> m_nV >> m_nE;
	assert(m_nV > 0);
	m_pBag = new Bag<int>[m_nV];
	for (int i = 0; i < m_nE; i++)
	{
		int v, w;
		ist >> v;
		ist >> w;
		this->AddEdge(v, w);
		m_nE--;
	}
}

Graph::~Graph()
{
	if (m_pBag != 0)
	{
		delete [] m_pBag;
	}
}

int Graph::V()
{
	return m_nV;
}

int Graph::E()
{
	return m_nE;
}

void Graph::AddEdge(int v, int w)
{
	assert(v < m_nV && w < m_nV);
	m_pBag[v].Add(w);
	m_pBag[w].Add(v);
	m_nE++;
}

Bag<int> Graph::Adj(int v)
{
	assert(v < m_nV);
	return m_pBag[v];
}

void Graph::Show()
{
	cout << m_nV << " vertices, " << m_nE << " edges" << endl;
	for (int i = 0; i < m_nV; i++)
	{
		cout << i << ": ";
		Bag<int> bagTemp = this->Adj(i);
		for (int j = 0; j < bagTemp.Size(); j++)
		{
			cout << bagTemp.Peek(j) << " ";
		}
		cout << endl;
	}
}