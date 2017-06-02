#pragma once
#include <string>
#include "OrderElementaryPQ.h"
#include "BinaryHeapMaxPQ.h"
#include "BinaryHeapMinPQ.h"
#include "BinaryHeapIndexMinPQ.h"
using namespace std;

template<typename T>
class PQCompare
{
public:
	static void CompareTwoPQ(string stringAlg1, string stringAlg2, int N, int T);
private:
	static void Run(string stringAlg, int* pData, int N);
	static void ShowElem(string stringAlg, int* pData, int N);
};

template<typename T>
void PQCompare<T>::CompareTwoPQ(string stringAlg1, string stringAlg2, int N, int T)
{
	assert(N > 0 && T > 0);
	int* pData1 = new int[N];
	int* pData2 = new int[N];
	time_t start = time(0);

	double seconds1 = 0;
	double seconds2 = 0;
	for (int j = 0; j < T; j++)
	{
		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			pData1[i] = rand();
			pData2[i] = pData1[i];
		}
		clock_t start = clock();
		Run(stringAlg1, pData1, N);
		seconds1 += (double)(clock() - start);

		start = clock();
		Run(stringAlg2, pData2, N);
		seconds2 += (double)(clock() - start);
	}
	ShowElem(stringAlg1, pData1, N);
	ShowElem(stringAlg2, pData2, N);
	cout << stringAlg1 << " total seconds: " << seconds1 / CLOCKS_PER_SEC << endl;
	cout << stringAlg2 << " total seconds: " << seconds2 / CLOCKS_PER_SEC << endl;
	delete pData2;
	delete pData1;
}

template<typename T>
void PQCompare<T>::Run(string stringAlg, int* pData, int N)
{
	if (stringAlg == "OrderElementaryPQ")
	{
		OrderElementaryPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			PQ.DelMax();
		}
	}
	if (stringAlg == "BinaryHeapMaxPQ")
	{
		BinaryHeapMaxPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			PQ.DelMax();
		}
	}
	if (stringAlg == "BinaryHeapMinPQ")
	{
		BinaryHeapMinPQ<int> MinPQ(pData, N);
		while (!MinPQ.IsEmpty())
		{
			MinPQ.DelMin();
		}
	}
	if (stringAlg == "BinaryHeapIndexMinPQ")
	{
		BinaryHeapIndexMinPQ<int> IndexMinPQ(N);
		for (int i = 0; i < N; i++)
		{
			IndexMinPQ.Insert(i, pData[i]);
		}
		while (!IndexMinPQ.IsEmpty())
		{
			IndexMinPQ.DelMin();
		}
	}
}

template<typename T>
void PQCompare<T>::ShowElem(string stringAlg, int* pData, int N)
{
	if (stringAlg == "OrderElementaryPQ")
	{
		OrderElementaryPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			cout << PQ.DelMax() << " ";
		}
	}
	if (stringAlg == "BinaryHeapMaxPQ")
	{
		BinaryHeapMaxPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			cout << PQ.DelMax() << " ";
		}
	}
	if (stringAlg == "BinaryHeapMinPQ")
	{
		BinaryHeapMinPQ<int> MinPQ(pData, N);
		while (!MinPQ.IsEmpty())
		{
			cout << MinPQ.DelMin() << " ";
		}
	}
	if (stringAlg == "BinaryHeapIndexMinPQ")
	{
		cout << "original data:" << endl;
		BinaryHeapIndexMinPQ<int> IndexMinPQ(N);
		for (int i = 0; i < N; i++)
		{
			IndexMinPQ.Insert(i, i);
			cout << pData[i] << " ";
		}
		for (int i = 0; i < N; i++)
		{
			IndexMinPQ.Change(i, pData[i]);
		}
		cout << endl;
		while (!IndexMinPQ.IsEmpty())
		{
			//cout << pData[IndexMinPQ.DelMin()] << " ";
			cout << IndexMinPQ.Min() << " ";
			IndexMinPQ.DelMin();
		}
	}
	cout << endl << "--------------------------------------------------------" << endl;
}