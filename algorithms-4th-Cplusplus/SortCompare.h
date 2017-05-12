#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <string>
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HillSort.h"
#include "MergeSort.h"
#include "MergeBUSort.h"
#include "QuickSort.h"

using namespace std;

class SortCompare
{
public:
	static void CompareTwoSortAlgorithms(string stringAlg1, string stringAlg2, int N, int T);
private:
	static void Run(string stringAlg, int* pData, int N);
	static void ShowElem(int* pData, int N);
};


void SortCompare::CompareTwoSortAlgorithms(string stringAlg1, string stringAlg2, int N, int T)
{
	assert(N > 0 && T > 0);
	int* pData1 = new int[N];
	int* pData2 = new int[N];
	time_t start = time(0);

	double seconds1 = 0;
	double seconds2 = 0;
	for(int j=0; j<T; j++)
	{
		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			pData1[i] = rand();
			pData2[i] = pData1[i];
		}
		clock_t start = clock();
		Run(stringAlg1, pData1, N);
		seconds1 += (double)(clock()-start);

		start = clock();
		Run(stringAlg2, pData2, N);
		seconds2 += (double)(clock() - start);
	}
	ShowElem(pData1, N);
	ShowElem(pData2, N);
	cout << stringAlg1 << " total seconds: " << seconds1/CLOCKS_PER_SEC <<endl;
	cout << stringAlg2 << " total seconds: " << seconds2/CLOCKS_PER_SEC <<endl;
	delete pData2;
	delete pData1;
}

void SortCompare::Run(string stringAlg, int* pData, int N)
{
	if (stringAlg == "SelectionSort") SelectionSort<int>::Sort(pData, N);
	if (stringAlg == "InsertionSort") InsertionSort<int>::Sort2(pData, N);
	if (stringAlg == "HillSort") HillSort<int>::Sort2(pData, N);
	if (stringAlg == "MergeSort") MergeSort<int>::Sort(pData, N);
	if (stringAlg == "MergeBUSort") MergeBUSort<int>::Sort(pData, N);
	if (stringAlg == "QuickSort") QuickSort<int>::Sort(pData, N);
}

void SortCompare::ShowElem(int* pData, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << pData[i] << " ";
	}
	cout << endl<<"--------------------------------------------------------" << endl;
}