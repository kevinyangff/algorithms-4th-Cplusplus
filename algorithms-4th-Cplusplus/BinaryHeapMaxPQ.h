#pragma once
#include "InsertionSort.h"
#include <assert.h>
template<typename T>
class BinaryHeapMaxPQ
{
public:
	BinaryHeapMaxPQ();
	BinaryHeapMaxPQ(int N);
	BinaryHeapMaxPQ(T* pData, int nSize);
	~BinaryHeapMaxPQ();
	void Insert(T data);
	T Max();
	T DelMax();
	bool IsEmpty();
	int Size();
private:
	void Sink();
	void Swim();
	void Exch(T* pData, int i, int j);
private:
	T* m_pData;
	int m_nSize;
	int m_nValidLength;
};

template<typename T>
BinaryHeapMaxPQ<T>::BinaryHeapMaxPQ()
{
	m_nSize = 3;
	m_nValidLength = 0;
	m_pData = new T[3];
}

template<typename T>
BinaryHeapMaxPQ<T>::BinaryHeapMaxPQ(int N)
{
	m_nSize = N+1;
	m_nValidLength = 0;
	m_pData = new T[N+1];
}

template<typename T>
BinaryHeapMaxPQ<T>::BinaryHeapMaxPQ(T* pData, int nSize)
{
	m_nSize = nSize+1;
	m_nValidLength = 0;
	m_pData = new T[nSize+1];
	for (int i = 0; i < nSize; i++)
	{
		Insert(pData[i]);
	}
}

template<typename T>
BinaryHeapMaxPQ<T>::~BinaryHeapMaxPQ()
{
	delete[] m_pData;
}

template<typename T>
void BinaryHeapMaxPQ<T>::Insert(T data)
{
	m_pData[++m_nValidLength] = data;
	Swim();
	if (m_nValidLength == m_nSize-1)
	{
		m_nSize *= 2;
		T* pDataTemp = new T[m_nSize];
		for (int i = 1; i <= m_nValidLength; i++)
		{
			pDataTemp[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = pDataTemp;
	}
}

template<typename T>
T BinaryHeapMaxPQ<T>::Max()
{
	assert(m_nValidLength > 0);
	return m_pData[1];
}

template<typename T>
T BinaryHeapMaxPQ<T>::DelMax()
{
	assert(m_nValidLength > 0);
	T temp = m_pData[1];
	Exch(m_pData, 1, m_nValidLength--);
	Sink();
	if (m_nValidLength <= m_nSize / 4)
	{
		m_nSize /= 2;
		T* pDataTemp = new T[m_nSize];
		for (int i = 1; i <= m_nValidLength; i++)
		{
			pDataTemp[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = pDataTemp;
	}
	return temp;
}

template <typename T>
void BinaryHeapMaxPQ<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}


template<typename T>
int BinaryHeapMaxPQ<T>::Size()
{
	return m_nValidLength;
}

template<typename T>
bool BinaryHeapMaxPQ<T>::IsEmpty()
{
	return !m_nValidLength;
}

template<typename T>
void BinaryHeapMaxPQ<T>::Sink()
{
	for (int i = 1; i <= m_nValidLength/2;)
	{
		if(2*i+1<=m_nValidLength)
		{
			if (m_pData[i] < m_pData[2 * i] || m_pData[i] < m_pData[2 * i + 1])
			{
				if (m_pData[2 * i] > m_pData[2 * i + 1])
				{
					Exch(m_pData, i, 2 * i);
					i = 2 * i;
				}
				else
				{
					Exch(m_pData, i, 2 * i+1);
					i = 2 * i+1;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if (m_pData[i] < m_pData[2 * i])
			{
				Exch(m_pData, i, 2*i);
			}
			else
			{
				break;
			}
		}
	}
}

template<typename T>
void BinaryHeapMaxPQ<T>::Swim()
{
	for (int i = m_nValidLength; i/2 >= 1; i/=2)
	{
		if (m_pData[i] > m_pData[i / 2])
		{
			Exch(m_pData, i, i / 2);
		}
		else
		{
			break;
		}
	}
}