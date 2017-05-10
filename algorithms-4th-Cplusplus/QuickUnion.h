#pragma once
#include <assert.h>
class QuickUnionUF {
public:
	QuickUnionUF(int N);
	~QuickUnionUF();
	int ComponentCount();
	bool IsConnect(int x, int y);
	int Find(int x);
	void Union(int x, int y);
private:
	int* m_pData;
	int m_nCount;
	int m_nMax;
};

QuickUnionUF::QuickUnionUF(int N)
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

QuickUnionUF::~QuickUnionUF()
{
	delete m_pData;
}

int QuickUnionUF::ComponentCount()
{
	return m_nCount;
}

bool QuickUnionUF::IsConnect(int x, int y)
{
	return this->Find(x) == this->Find(y);
}

int QuickUnionUF::Find(int x)
{
	assert(x < m_nMax);
	while (x != m_pData[x])
	{
		x = m_pData[x];
	}
	return x;
}

void QuickUnionUF::Union(int x, int y)
{
	int nXComponent = Find(x);
	int nYComponent = Find(y);
	if (nXComponent == nYComponent)
	{
		return;
	}
	m_pData[nYComponent] = nXComponent;
	m_nCount--;
}
