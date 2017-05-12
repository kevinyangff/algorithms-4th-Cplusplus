#pragma once
#include <assert.h>
#include <iostream>
#include "InsertionSort.h"
using namespace std;
template <typename T>
class MergeSort
{
public:
	static void Sort(T* pData, int nSize);
	static void Show(T* pData, int nSize);
private:
	static bool Less(T t1, T t2);
	static void Exch(T* pData, int i, int j);
	static bool IsSorted(T* pData, int nSize);
	static void Merge(T* pData, int lo, int mid, int hi);
	static T* m_pAux;
};

template <typename T>
T* MergeSort<T>::m_pAux = 0;

template <typename T>
void MergeSort<T>::Sort(T* pData, int nSize)
{
	if (m_pAux == 0)
	{
		m_pAux = new T[nSize];
	}
	if (nSize <= 10) //nSize<=10的情况用插入排序
	{
		InsertionSort<T>::Sort2(pData, nSize);
		return;
	}
	int mid = nSize / 2;
	if (mid == 0) 
		return;
	MergeSort<T>::Sort(pData, mid);
	MergeSort<T>::Sort(pData+mid, nSize - mid);
	MergeSort<T>::Merge(pData, 0, mid, nSize-1);
}

template <typename T>
void MergeSort<T>::Merge(T* pData, int lo, int mid, int hi)
{
	if (pData[mid] >= pData[mid-1])
	{
		return;
	}
	for (int i = lo; i <= hi; i++)
	{
		m_pAux[i] = pData[i];
	}
	int i = lo;
	int j = mid;
	for (int x=lo; x<=hi; x++)
	{
		if (i >= mid) pData[x] = m_pAux[j++];
		else if (j > hi) pData[x] = m_pAux[i++];
		else if (Less(m_pAux[i], m_pAux[j])) pData[x] = m_pAux[i++];
		else pData[x]=m_pAux[j++];
	}
}

template <typename T>
void MergeSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool MergeSort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void MergeSort<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool MergeSort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!MergeSort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}