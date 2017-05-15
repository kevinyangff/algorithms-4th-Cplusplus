#pragma once
#include <assert.h>
#include <iostream>
#include "InsertionSort.h"
using namespace std;
template <typename T>
class Quick3Sort
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
	static T* m_pAux;
};

template <typename T>
T* Quick3Sort<T>::m_pAux = 0;

template <typename T>
void Quick3Sort<T>::Sort(T* pData, int nSize)
{
	Sort(pData, 0, nSize - 1);
}

template <typename T>
void Quick3Sort<T>::Sort(T* pData, int lo, int hi)
{
	if (lo >= hi)
	{
		return;
	}
	int lt = lo;
	int i = lo + 1;
	int gt = hi;
	T temp = pData[lo];
	while (i <= gt)
	{
		if (pData[i] < temp)
		{
			Exch(pData, lt++, i++);
		}
		else
		{
			if (pData[i] > temp)
			{
				Exch(pData, i, gt--);
			}
			else
			{
				i++;
			}
		}
	}
	Sort(pData, lo, lt-1);
	Sort(pData, gt+1, hi);
}


template <typename T>
void Quick3Sort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
void Quick3Sort<T>::Show(T* pData, int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool Quick3Sort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void Quick3Sort<T>::Exch(T* pData, int i, int j)
{
	if (i == j) return;
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool Quick3Sort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!Quick3Sort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}