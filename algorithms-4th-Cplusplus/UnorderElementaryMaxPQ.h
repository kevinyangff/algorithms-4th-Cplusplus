#pragma once
#include "InsertionSort.h"
#include <assert.h>
template<typename T>
class UnorderElementaryMaxPQ
{
public:
	UnorderElementaryMaxPQ();
	UnorderElementaryMaxPQ(int N);
	UnorderElementaryMaxPQ(T* pData, int nSize);
	void Insert(T);
	T Max();
	T DelMax();
	bool IsEmpty();
	int Size();
private:
	T* m_pData;
	int m_nSize;
	int m_nValidLength;
};

template<typename T>
UnorderElementaryMaxPQ<T>::UnorderElementaryMaxPQ()
{
	m_pData = new T[4];
	m_nSize = 4;
	m_nValidLength = 0;
}

template<typename T>
UnorderElementaryMaxPQ<T>::UnorderElementaryMaxPQ(int N)
{
	m_pData = new T[N];
	m_nSize = N;
	m_nValidLength = 0;
}

template<typename T>
UnorderElementaryMaxPQ<T>::UnorderElementaryMaxPQ(T* pData, int nSize)
{
	m_pData = new T[nSize];
	for (int i = 0; i < nSize; i++)
	{
		m_pData[i] = pData[i];
	}
	m_nSize = nSize;
	m_nValidLength = m_nSize;
}

template<typename T>
void UnorderElementaryMaxPQ<T>::Insert(T t)
{
	if (m_nValidLength >= m_nSize)
	{
		T* pTempData = new T[2 * m_nSize];
		for (int i = 0; i < m_nSize; i++)
		{
			pTempData[i] = m_pData[i];
		}
		delete m_pData;
		m_pData = pTempData;
		m_nSize *= 2;
	}
	m_pData[m_nValidLength++] = t;
}

template<typename T>
T UnorderElementaryMaxPQ<T>::Max()
{
	assert(!IsEmpty())
	InsertionSort<T>::Sort2(m_pData, m_nValidLength);
	return m_pData[m_nValidLength - 1];
}

template<typename T>
T UnorderElementaryMaxPQ<T>::DelMax()
{
	assert(!IsEmpty());
	InsertionSort<T>::Sort2(m_pData, m_nValidLength);
	if (m_nValidLength - 1 <= m_nSize / 4)
	{
		T* pTempData = new T[m_nSize / 2];
		for (int i = 0; i < m_nValidLength; i++)
		{
			pTempData[i] = m_pData[i];
		}
		delete m_pData;
		m_pData = pTempData;
		m_nSize /= 2;
	}
	return m_pData[--m_nValidLength];
}

template<typename T>
bool UnorderElementaryMaxPQ<T>::IsEmpty()
{
	return !m_nValidLength;
}

template<typename T>
int UnorderElementaryMaxPQ<T>::Size()
{
	return m_nValidLength;
}