#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
template <typename T>
class HillSort
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
void HillSort<T>::Sort(T* pData, int nSize)
{
	int h = 1;
	while (h < nSize / 3)
	{
		h = h * 3 + 1;
	}
	while(h > 0)
	{
		for (int i = h; i < nSize; i++)
		{
			for (int j = i; j > h && Less(pData[j], pData[j - h]); j-=h)
			{
				Exch(pData, j, j - h);
			}
		}
		h /= 3;
	}
}

template <typename T>
void HillSort<T>::Sort2(T* pData, int nSize)
{
	int h = 1;
	while (h < nSize / 3)
	{
		h = h * 3 + 1;
	}
	while(h>0)
	{
		for (int i = h; i < nSize; i++)
		{
			int j = i;
			T temp = pData[i];
			for (j; j > h && Less(temp, pData[j - h]); j-=h)
			{
				pData[j] = pData[j - h];
			}
			pData[j] = temp;
		}
		h /= 3;
	}
}

template <typename T>
void HillSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool HillSort<T>::Less(T t1, T t2)
{
	return t1 < t2;
}

template <typename T>
void HillSort<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}

template <typename T>
bool HillSort<T>::IsSorted(T* pData, int nSize)
{
	for (int i = 0; i < nSize - 1; i++)
	{
		if (!HillSort<T>::Less(pData[i], pData[i + 1]))
		{
			return false;
		}
	}
	return true;
}