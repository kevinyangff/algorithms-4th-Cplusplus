#pragma once
#include <assert.h>
#include <iostream>
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
};

template <typename T>
void MergeBUSort<T>::Sort(T* pData, int nSize)
{

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