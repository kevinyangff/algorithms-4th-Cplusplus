#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
template <typename T>
class InsertionSort
{
public:
	static void Sort(T* pData, int nSize);
	static void Sort2(T* pData, int nSize);
	static void Show(T* pData, int nSize);
private:
	static bool Less(T t1, T t2);
	static void Exch(T* pData, int i, int j);
	static bool IsSorted(T* pData, int nSize);
};

template <typename T>
void InsertionSort<T>::Sort(T* pData, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		for (int j = i; j > 0&& Less(pData[j], pData[j - 1]); j--)
		{
			Exch(pData, j, j - 1);
		}
	}
}

template <typename T>
void InsertionSort<T>::Sort2(T* pData, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		int j = i;
		T temp = pData[i];
		for (j; j > 0 && Less(temp, pData[j - 1]); j--)
		{
			pData[j] = pData[j-1];
		}
		pData[j] = temp;
	}
}

template <typename T>
void InsertionSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool InsertionSort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void InsertionSort<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool InsertionSort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!InsertionSort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}