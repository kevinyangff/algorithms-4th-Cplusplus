#pragma once
#include <string>
#include "OrderElementaryPQ.h"
#include "BinaryHeapPQ.h"
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
	if (stringAlg == "BinaryHeapPQ")
	{
		BinaryHeapPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			PQ.DelMax();
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
	if (stringAlg == "BinaryHeapPQ")
	{
		BinaryHeapPQ<int> PQ(pData, N);
		while (!PQ.IsEmpty())
		{
			cout << PQ.DelMax() << " ";
		}
	}
	cout << endl << "--------------------------------------------------------" << endl;
}