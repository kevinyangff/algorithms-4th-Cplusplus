#pragma once
#include <assert.h>
#include <iostream>
using namespace std;
template <typename T>
class BinaryHeapSort
{
public:
	static void Sort(T* pData, int nSize);
	static void Show(T* pData, int nSize);
private:
	static bool Less(T t1, T t2);
	static void Exch(T* pData, int i, int j);
	static void Sink(T* pData, int i, int nSize);
};

template <typename T>
void BinaryHeapSort<T>::Sort(T* pData, int nSize)
{
	int nSizeTemp = nSize;
	//move to temp
	T* pTemp = new T[nSize + 1];
	for (int i = 0; i < nSize; i++)
	{
		pTemp[i + 1] = pData[i];
	}
	//Generate
	for (int i = nSize / 2; i >= 1; i--)
	{
		Sink(pTemp, i, nSize);
	}
	//Sort
	while (nSize > 1)
	{
		Exch(pTemp, 1, nSize);
		Sink(pTemp, 1, --nSize);
	}
	//move back
	for (int i = 1; i < nSizeTemp + 1; i++)
	{
		pData[i - 1] = pTemp[i];
	}
}

template<typename T>
void BinaryHeapSort<T>::Sink(T* pData, int i, int nSize)
{
	for (int k = i; k <= nSize / 2;)
	{
		if (nSize >= 2 * k + 1)
		{
			T left = pData[2 * k];
			T right = pData[2 * k + 1];
			if (pData[k] < left || pData[k] < right)
			{
				if (left < right)
				{
					Exch(pData, k, 2 * k + 1);
					k = 2 * k + 1;
				}
				else
				{
					Exch(pData, k, 2 * k);
					k = 2 * k;
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			T left = pData[2 * k];
			if (pData[k] < left)
			{
				Exch(pData, k, 2 * k);
				k *= 2;
			}
			else
			{
				break;
			}
		}
	}
}

template <typename T>
void BinaryHeapSort<T>::Show(T* pData, int nSize)
{
	cout << "print elements from small to big." << endl;
	for (int i = 0; i < nSize; i++)
	{
		cout << pData[i] << "	";
	}
	cout << endl;
}

template <typename T>
bool BinaryHeapSort<T>::Less(T t1, T t2)
{
	return t1 <= t2;
}

template <typename T>
void BinaryHeapSort<T>::Exch(T* pData, int i, int j)
{
	T temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}
