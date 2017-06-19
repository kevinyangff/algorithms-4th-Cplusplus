#pragma once
#include <string>
#include <assert.h>
#include "Stack.h"
#include "Bag.h"
#include "DirectedDFSearch.h"
using std::string;
class NFA
{
public:
	NFA(string reg);
	~NFA();
	bool Recognizes(string txt);
private:
	int m_M;
	string m_reg;
	DiGraph* m_G;
	DirectedDFSearch* m_pDirectedDFS;
	Bag<int>* m_pBag;
};

NFA::NFA(string reg):m_G(0), m_pDirectedDFS(0), m_pBag(0)
{
	m_M = reg.length();
	m_reg = reg;
	m_G = new DiGraph(m_M + 1);
	Stack<int> s;
	for (int i = 0; i < m_M; i++)
	{
		if (m_reg.at(i) == '(' || m_reg.at(i) == ')' || m_reg.at(i) == '*')
		{
			m_G->AddEdge(i, i + 1);
		}
		int nLeftParentheses = i;
		if (m_reg.at(i) == '(' || m_reg.at(i) == '|')
		{
			s.Push(i);
		}
		else if (m_reg.at(i) == ')')
		{
			int n = s.Pop();
			if (m_reg.at(n) == '|')
			{
				m_G->AddEdge(n, i);
				nLeftParentheses = s.Pop();
				m_G->AddEdge(nLeftParentheses, n + 1);
			}
			else if (m_reg.at(n) == '(')
			{
				nLeftParentheses = n;
			}
			else assert(false);
		}
		if (i < m_M - 1 && m_reg[i + 1] == '*')
		{
			m_G->AddEdge(nLeftParentheses, i + 1);
			m_G->AddEdge(i + 1, nLeftParentheses);
		}
	}
	if (!s.IsEmpty()) assert(false);
}

NFA::~NFA()
{
	if (m_pBag)
	{
		delete m_pBag;
		m_pBag = 0;
	}
	if (m_pDirectedDFS)
	{
		delete m_pDirectedDFS;
		m_pDirectedDFS = 0;
	}
	if (m_G)
	{
		delete m_G;
		m_G = 0;
	}
}
bool NFA::Recognizes(string txt)
{
	if (m_pDirectedDFS)
	{
		delete m_pDirectedDFS;
		m_pDirectedDFS = 0;
	}
	m_pDirectedDFS = new DirectedDFSearch(*m_G, 0);
	if (m_pBag)
	{
		delete m_pBag;
		m_pBag = 0;
	}
	m_pBag = new Bag<int>();
	for (int i = 0; i <= m_M; i++)
	{
		if (m_pDirectedDFS->Marked(i))
		{
			m_pBag->Add(i);
		}
	}
	for (int i = 0; i < txt.length(); i++)
	{
		Bag<int> temp;
		for (int j = 0; j < m_pBag->Size(); j++)
		{
			int v = m_pBag->Peek(j);
			if (v < m_M)
			{
				if (m_reg.at(v) == txt.at(i) || m_reg.at(v) == '.')
				{
					temp.Add(v + 1);
				}
			}
			else
			{
				return true;
			}
		}
		Bag<int> bagNew;
		delete m_pDirectedDFS;
		m_pDirectedDFS = new DirectedDFSearch(*m_G, temp);
		for (int i = 0; i <= m_M; i++)
		{
			if (m_pDirectedDFS->Marked(i))
			{
				bagNew.Add(i);
			}
		}
		delete m_pBag;
		m_pBag = new Bag<int>(bagNew);
		if (m_pBag->Size() == 0)	return false;
	}
	for (int i = 0; i < m_pBag->Size(); i++)
	{
		if (m_pBag->Peek(i) == m_M)
		{
			return true;
		}
	}
	return false;
}