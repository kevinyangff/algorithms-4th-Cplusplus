#pragma once
#include <assert.h>
class WeightQuickUnionUF {
public:
	WeightQuickUnionUF(int N);
	~WeightQuickUnionUF();
	int ComponentCount();
	bool IsConnect(int x, int y);
	int Find(int x);
	void Union(int x, int y);
private:
	int* m_pData;
	int* m_pWeight;
	int m_nCount;
	int m_nMax;
};

WeightQuickUnionUF::WeightQuickUnionUF(int N)
{
	assert(N > 0);
	m_nCount = N;
	m_nMax = N;
	m_pData = new int[N];
	m_pWeight = new int[N];
	for (int i = 0; i < N; i++)
	{
		m_pData[i] = i;
		m_pWeight[i] = 1;
	}
}

WeightQuickUnionUF::~WeightQuickUnionUF()
{
	delete m_pData;
}

int WeightQuickUnionUF::ComponentCount()
{
	return m_nCount;
}

bool WeightQuickUnionUF::IsConnect(int x, int y)
{
	return this->Find(x) == this->Find(y);
}

int WeightQuickUnionUF::Find(int x)
{
	assert(x < m_nMax);
	while (x != m_pData[x])
	{
		x = m_pData[x];
	}
	return x;
}

void WeightQuickUnionUF::Union(int x, int y)
{
	int nXComponent = Find(x);
	int nYComponent = Find(y);
	if (nXComponent == nYComponent)
	{
		return;
	}
	if(m_pWeight[nYComponent] < m_pWeight[nXComponent])
	{
		m_pData[nYComponent] = nXComponent;
	}
	else
	{
		m_pData[nXComponent] = nYComponent;
		if (m_pWeight[nYComponent] == m_pWeight[nXComponent])
		{
			m_pWeight[nYComponent]++;
		}
	}
	m_nCount--;
}
