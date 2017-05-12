#pragma once
#include <assert.h>
#include <iostream>
#include "InsertionSort.h"
using namespace std;
template <typename T>
class MergeBUSort
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
T* MergeBUSort<T>::m_pAux = 0;

template <typename T>
void MergeBUSort<T>::Sort(T* pData, int nSize)
{
	if (m_pAux == 0)
	{
		m_pAux = new T[nSize];
	}
	for (int i = 2; i < 2*nSize; i = i * 2)
	{
		for (int j = 0; j < nSize; j += i)
		{
			MergeBUSort<T>::Merge(pData, j, j+i/2>=nSize?j+(nSize-j)/2: j+i/2, j+i-1 >= nSize ? nSize-1 : j + i - 1);
		}
	}

// 	for (int i = 1; i < nSize; i *= 2)
// 	{
// 		for (int j = 0; j < nSize - i; j += i*2)
// 		{
// 			MergeBUSort<T>::Merge(pData, j, j + i, j + 2 * i > nSize ? nSize - 1 : j + 2 * i - 1);
// 		}
// 	}
}

template <typename T>
void MergeBUSort<T>::Merge(T* pData, int lo, int mid, int hi)
{
	if (pData[mid] >= pData[mid - 1])
	{
		return;
	}
	for (int i = lo; i <= hi; i++)
	{
		m_pAux[i] = pData[i];
	}
	int i = lo;
	int j = mid;
	for (int x = lo; x <= hi; x++)
	{
		if (i >= mid) pData[x] = m_pAux[j++];
		else if (j > hi) pData[x] = m_pAux[i++];
		else if (Less(m_pAux[i], m_pAux[j])) pData[x] = m_pAux[i++];
		else pData[x] = m_pAux[j++];
	}
}

template <typename T>
void MergeBUSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool MergeBUSort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void MergeBUSort<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool MergeBUSort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!MergeBUSort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}