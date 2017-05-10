#pragma once
#include <assert.h>
class QuickFindUF {
public:
	QuickFindUF(int N);
	~QuickFindUF();
	int ComponentCount();
	bool IsConnect(int x, int y);
	int Find(int x);
	void Union(int x, int y);
private:
	int* m_pData;
	int m_nCount;
	int m_nMax;
};

QuickFindUF::QuickFindUF(int N)
{
	assert(N > 0);
	m_nCount = N;
	m_nMax = N;
	m_pData = new int[N];
	for (int i = 0; i < N; i++)
	{
		m_pData[i] = i;
	}
}

QuickFindUF::~QuickFindUF()
{
	delete m_pData;
}

int QuickFindUF::ComponentCount()
{
	return m_nCount;
}

bool QuickFindUF::IsConnect(int x, int y)
{
	return this->Find(x) == this->Find(y);
}

int QuickFindUF::Find(int x)
{
	assert(x < m_nMax);
	return m_pData[x];
}

void QuickFindUF::Union(int x, int y)
{
	int nXComponent = m_pData[x];
	int nYComponent = m_pData[y];
	if (nXComponent == nYComponent)
	{
		return;
	}
	for (int i = 0; i < m_nMax; i++)
	{
		if (m_pData[i] == nYComponent)
		{
			m_pData[i] = nXComponent;
		}
	}
	m_nCount--;
}