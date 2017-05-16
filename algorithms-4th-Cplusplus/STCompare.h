#pragma once
#include <string>
#include "SequentialSearchST.h"
#include "BinarySearchST.h"

using namespace std;

class STCompare
{
public:
	static void Compare(string stringAlg1, string stringAlg2, int N, int T);
private:
	static void Run(string stringAlg, int* pData, int N);
	static void ShowElem(string stringAlg, int* pData, int N);
};

void STCompare::Compare(string stringAlg1, string stringAlg2, int N, int T)
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

void STCompare::Run(string stringAlg, int* pData, int N)
{
	if (stringAlg == "SequentialSearchST")
	{
		SequentialSearchST<int, int> ST;
		for (int i = 0; i < N; i++)
		{
			ST.Put(pData[i], pData[i]);
		}
		for (int i = 0; i < N; i++)
		{
			ST.Get(pData[i]);
		}
	}
	if (stringAlg == "BinarySearchST")
	{
		BinarySearchST<int, int> ST(N);
		for (int i = 0; i < N; i++)
		{
			ST.Put(pData[i], pData[i]);
		}
		for (int i = 0; i < N; i++)
		{
			ST.Get(pData[i]);
		}
	}
}

void STCompare::ShowElem(string stringAlg, int* pData, int N)
{
	if (stringAlg == "SequentialSearchST")
	{
		SequentialSearchST<int, int> ST;
		for (int i = 0; i < N; i++)
		{
			ST.Put(pData[i], pData[i]);
		}
		Queue<int> q = ST.Keys();
		for (int i = 0; i < ST.Size(); i++)
		{
			cout << q.Peek(i) << " ";
		}
	}
	if (stringAlg == "BinarySearchST")
	{
		BinarySearchST<int, int> ST(N);
		for (int i = 0; i < N; i++)
		{
			ST.Put(pData[i], pData[i]);
		}
		Queue<int> q = ST.Keys();
		for (int i = 0; i < ST.Size(); i++)
		{
			cout << q.Peek(i) << " ";
		}
	}
	cout << endl << "--------------------------------------------------------" << endl;
}