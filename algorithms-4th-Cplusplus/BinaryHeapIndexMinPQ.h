#pragma once
#include <assert.h>
template<typename T>
class BinaryHeapIndexMinPQ
{
public:
	BinaryHeapIndexMinPQ(int N);
	~BinaryHeapIndexMinPQ();
	void Insert(int nIndex, T data);
	void Change(int nIndex, T data);
	bool Contain(int nIndex);
	void Delete(int nIndex);
	T Min();
	int MinIndex();
	int DelMin();
	bool IsEmpty();
	int Size();
private:
	void Swim(int n);
	void Sink(int n);
	void Exch(T* pData, int i, int j);
private:
	int m_nSize;
	int m_nValidLength;
	T* m_pData;
	T* m_pDataIndex;
	int* m_pMapFromIndexToPQ;
	int* m_pMapFromPQToIndex;
};

template<typename T>
BinaryHeapIndexMinPQ<T>::BinaryHeapIndexMinPQ(int N) :m_nSize(N), m_nValidLength(0)
{
	m_pData = new T[N + 1];
	m_pDataIndex = new T[N];
	m_pMapFromIndexToPQ = new int[N];
	m_pMapFromPQToIndex = new int[N + 1];
	for (int i = 0; i < N; i++)
	{
		m_pMapFromIndexToPQ[i] = 0;
		m_pMapFromPQToIndex[i + 1] = N;
	}
}

template<typename T>
BinaryHeapIndexMinPQ<T>::~BinaryHeapIndexMinPQ()
{
	if (m_pDataIndex)
	{
		delete[] m_pDataIndex;
	}
	if (m_pData)
	{
		delete[] m_pData;
	}
	if (m_pMapFromIndexToPQ)
	{
		delete[] m_pMapFromIndexToPQ;
	}
	if (m_pMapFromPQToIndex)
	{
		delete[] m_pMapFromPQToIndex;
	}
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Insert(int nIndex, T data)
{
	assert(nIndex < m_nSize);
	assert(m_nValidLength < m_nSize);
	assert(!this->Contain(nIndex));
	m_nValidLength++;
	m_pData[m_nValidLength] = data;
	m_pDataIndex[nIndex] = data;
	m_pMapFromIndexToPQ[nIndex] = m_nValidLength;
	m_pMapFromPQToIndex[m_nValidLength] = nIndex;
	Swim(m_nValidLength);
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Change(int nIndex, T data)
{
	assert(this->Contain(nIndex));
	T temp = m_pDataIndex[nIndex];
	int nPQ = m_pMapFromIndexToPQ[nIndex];
	m_pData[nPQ] = data;
	m_pDataIndex[nIndex] = data;
	if (temp > data)
	{
		Swim(nPQ);
	}
	else
	{
		Sink(nPQ);
	}
}

template<typename T>
bool BinaryHeapIndexMinPQ<T>::Contain(int nIndex)
{
	assert(nIndex < m_nSize);
	return m_pMapFromIndexToPQ[nIndex] != 0;
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Delete(int nIndex)
{
	assert(this->Contain(nIndex));
	int nPQ = m_pMapFromIndexToPQ[nIndex];
	Exch(m_pData, nPQ, m_nValidLength);
	m_pMapFromIndexToPQ[nIndex] = 0;
	m_pMapFromPQToIndex[m_nValidLength] = m_nSize;
	m_nValidLength--;
	Sink(nPQ);
}

template<typename T>
T BinaryHeapIndexMinPQ<T>::Min()
{
	assert(!this->IsEmpty());
	return m_pData[1];
}

template<typename T>
int BinaryHeapIndexMinPQ<T>::MinIndex()
{
	assert(!this->IsEmpty());
	return m_pMapFromPQToIndex[1];
}

template<typename T>
int BinaryHeapIndexMinPQ<T>::DelMin()
{
	assert(!this->IsEmpty());
	int n = m_pMapFromPQToIndex[1];
	this->Delete(n);
	return n;
}

template<typename T>
bool BinaryHeapIndexMinPQ<T>::IsEmpty()
{
	return m_nValidLength == 0;
}

template<typename T>
int BinaryHeapIndexMinPQ<T>::Size()
{
	return m_nValidLength;
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Swim(int n)
{
	for (int i = n; i/2 >= 1; i /= 2)
	{
		if (m_pData[i] < m_pData[i / 2])
		{
			Exch(m_pData, i, i / 2);
		}
		else
		{
			break;
		}
	}
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Sink(int n)
{
	for (int i = n; i <= m_nValidLength / 2;)
	{
		if (2 * i + 1 <= m_nValidLength)
		{
			if (m_pData[i] > m_pData[2 * i] || m_pData[i] > m_pData[2 * i + 1])
			{
				if (m_pData[2 * i] < m_pData[2 * i + 1])
				{
					Exch(m_pData, i, 2 * i);
					i = 2 * i;
				}
				else
				{
					Exch(m_pData, i, 2 * i + 1);
					i = 2 * i + 1;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if (m_pData[i] > m_pData[2 * i])
			{
				Exch(m_pData, i, 2 * i);
			}
			else
			{
				break;
			}
		}
	}
}

template<typename T>
void BinaryHeapIndexMinPQ<T>::Exch(T* pData, int i, int j)
{
	int nIndexI = m_pMapFromPQToIndex[i];
	int nIndexJ = m_pMapFromPQToIndex[j];

	int nIndexTemp = m_pMapFromPQToIndex[i];
	m_pMapFromPQToIndex[i] = m_pMapFromPQToIndex[j];
	m_pMapFromPQToIndex[j] = nIndexTemp;
	
	int nPQTemp = m_pMapFromIndexToPQ[nIndexI];
	m_pMapFromIndexToPQ[nIndexI] = m_pMapFromIndexToPQ[nIndexJ];
	m_pMapFromIndexToPQ[nIndexJ] = nPQTemp;
	
	T temp = m_pData[i];
	m_pData[i] = m_pData[j];
	m_pData[j] = temp;
}