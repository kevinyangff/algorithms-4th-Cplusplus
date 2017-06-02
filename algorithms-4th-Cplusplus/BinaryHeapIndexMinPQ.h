#pragma once
#include <assert.h>
template<typename T>
class BinaryHeapIndexMinPQ
{
public:
	BinaryHeapIndexMinPQ(int N);
	~BinaryHeapIndexMinPQ()
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
	Swim();
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
	Exch(nPQ, m_nValidLength);
	m_pMapFromIndexToPQ[nIndex] = 0;
	m_pMapFromPQToIndex[nPQ] = m_pMapFromPQToIndex[m_nValidLength];
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
	this->Delete(m_pMapFromPQToIndex(1));
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
void BinaryHeapIndexMinPQ<T>::Swim(int n);

template<typename T>
void BinaryHeapIndexMinPQ<T>::Sink(int n);

template<typename T>
void BinaryHeapIndexMinPQ<T>::Exch(T* pData, int i, int j);