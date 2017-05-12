#pragma once
#include <assert.h>
#include <iostream>
#include "InsertionSort.h"
using namespace std;
template <typename T>
class QuickSort
{
public:
	static void Sort(T* pData, int nSize);
	static void Show(T* pData, int nSize);
	static void Show(T* pData, int lo, int hi);
private:
	static bool Less(T t1, T t2);
	static void Exch(T* pData, int i, int j);
	static bool IsSorted(T* pData, int nSize);
	static void Sort(T* pData, int lo, int hi);
	static int Partition(T* pData, int lo, int hi);
	static T* m_pAux;
};

template <typename T>
T* QuickSort<T>::m_pAux = 0;

template <typename T>
void QuickSort<T>::Sort(T* pData, int nSize)
{
	Sort(pData, 0, nSize - 1);
}

template <typename T>
void QuickSort<T>::Sort(T* pData, int lo, int hi)
{
	if(lo>=hi)
	{
		return;
	}
	int i = Partition(pData, lo, hi);
	if(i > lo) Sort(pData, lo, i-1);
	if(i < hi) Sort(pData, i + 1, hi);
}

template <typename T>
int QuickSort<T>::Partition(T* pData, int lo, int hi)
{
	int i = lo+1;
	int j = hi;
	T temp = pData[lo];
	while(true)
	{
		while (pData[i] <= temp)
		{
			i++;
			if (i == hi + 1) break;
		}
		while (pData[j] >= temp)
		{
			j--;
			if (j == lo) break;
		}
		if (i >= j)
		{
			break;
		}
		else
		{
			Exch(pData, i, j);
			i++;
			j--;
		}
		if (i >= j)
		{
			break;
		}
	}
	Exch(pData, lo, j);
	//Show(pData, lo, hi);
	return j;
}

template <typename T>
void QuickSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
void QuickSort<T>::Show(T* pData, int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool QuickSort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void QuickSort<T>::Exch(T* pData, int i, int j)
{
	if (i == j) return;
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool QuickSort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!QuickSort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}