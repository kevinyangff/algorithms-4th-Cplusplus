#pragma once
#include "InsertionSort.h"
#include <assert.h>
template<typename T>
class OrderElementaryPQ
{
public:
	OrderElementaryPQ();
	OrderElementaryPQ(int N);
	OrderElementaryPQ(T* pData, int nSize);
	~OrderElementaryPQ();
	void Insert(T data);
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
OrderElementaryPQ<T>::OrderElementaryPQ()
{
	m_nSize = 2;
	m_nValidLength = 0;
	m_pData = new T[2];
}

template<typename T>
OrderElementaryPQ<T>::OrderElementaryPQ(int N)
{
	m_nSize = N;
	m_nValidLength = 0;
	m_pData = new T[N];
}

template<typename T>
OrderElementaryPQ<T>::OrderElementaryPQ(T* pData, int nSize)
{
	m_nSize = nSize;
	m_nValidLength = 0;
	m_pData = new T[nSize];
	for (int i = 0; i < nSize; i++)
	{
		Insert(pData[i]);
	}
}

template<typename T>
OrderElementaryPQ<T>::~OrderElementaryPQ()
{
	delete m_pData;
}

template<typename T>
void OrderElementaryPQ<T>::Insert(T data)
{
	m_pData[m_nValidLength++] = data;
	InsertionSort<T>::Sort2(m_pData, m_nValidLength);
	if (m_nValidLength == m_nSize)
	{
		T* pDataTemp = new T[m_nSize * 2];
		for (int i = 0; i < m_nValidLength; i++)
		{
			pDataTemp[i] = m_pData[i];
		}
		delete m_pData;
		m_pData = pDataTemp;
	}
}

template<typename T>
T OrderElementaryPQ<T>::Max()
{
	assert(m_nValidLength > 0);
	return m_pData[m_nValidLength - 1];
}

template<typename T>
T OrderElementaryPQ<T>::DelMax()
{
	assert(m_nValidLength > 0);
	T temp = m_pData[m_nValidLength-1];
	if (--m_nValidLength <= m_nSize / 4)
	{
		T* pDataTemp = new T[m_nSize / 2];
		for (int i = 0; i < m_nValidLength; i++)
		{
			pDataTemp[i] = m_pData[i];
		}
		delete m_pData;
		m_pData = pDataTemp;
	}
	return temp;
}

template<typename T>
int OrderElementaryPQ<T>::Size()
{
	return m_nValidLength;
}

template<typename T>
bool OrderElementaryPQ<T>::IsEmpty()
{
	return !m_nValidLength;
}