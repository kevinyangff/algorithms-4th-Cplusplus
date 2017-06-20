#include <iostream>
#include <fstream>
#include <ctime>
#include "Stack.h"
#include "Queue.h"
#include "Bag.h"
#include "QuickFindUF.h"
#include "QuickUnion.h"
#include "WeightQuickUnion.h"
#include "SortCompare.h"
#include "PQCompare.h"
#include "UnorderElementaryMaxPQ.h"
#include "STCompare.h"
#include "Graph.h"
#include "DepthFirstSearch.h"
#include "BreadthFirshSearch.h"
#include "DepthFirstPaths.h"
#include "BreadthFirshPaths.h"
#include "DepthFirstCC.h"
#include "BreadthFirshCC.h"
#include "DepthFirstCycle.h"
#include "BreadthFirstCycle.h"
#include "DepthFirstTwoColor.h"
#include "BreadthFirstTwoColor.h"
#include "DirectedDFSearch.h"
#include "DirectedDFPaths.h"
#include "DirectedBFPaths.h"
#include "DirectedDFCycle.h"
#include "DirectedDFOrder.h"
#include "DirectedDFTopologic.h"
#include "DirectedDFSCC.h"
#include "EdgeWeightedGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"
#include "TopologicSP.h"
#include "BellmanFordSP.h"
#include "LSD.h"
#include "MSD.h"
#include "Quick3String.h"
#include "TrieST.h"
#include "TST.h"
#include "KMP.h"
#include "BoyerMoore.h"
#include "RabinKarp.h"
#include "NFA.h"
#include "Huffman.h"
#include "LZW.h"
using namespace std;

void ShowTime()
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	cout << (now->tm_hour) << ':'
		<< (now->tm_min) << ':'
		<< now->tm_sec
		<< endl;
}
int main()
{
	//test for Stack
// 	Stack<int> s;
// 	s.Push(1);
// 	s.Push(2);
// 	s.Push(4);
// 	s.Push(8);
// 	cout << s.Size() << endl;
// 	cout << s.Peek(1) << endl;
// 	cout << s.Pop()<<endl;
// 	cout << s.Pop() << endl;
// 	s.Push(16);
// 	while (!s.IsEmpty())
// 	{
// 		cout << s.Pop() << endl;
// 	}
	//test for Queue
//	Queue<int> q;
// 	q.Enqueue(1);
// 	q.Enqueue(2);
// 	q.Enqueue(3);
// 	q.Enqueue(4);
// 	cout << q.Size() << endl;
// 	cout << q.Peek(2) << endl;
// 	cout << q.Dequeue() << endl;
// 	cout << q.Size() << endl;
// 	q.Enqueue(8);
// 	while(!q.IsEmpty())
// 	{
// 		cout << q.Dequeue() << endl;
// 	}
	//test for Bag
// 	Bag<double> b;
// 	b.Add(1.0);
// 	b.Add(2.0);
// 	b.Add(8.1);
// 	cout << b.IsEmpty() << endl;
// 	cout << b.Size() << endl;
// 	for (int i = 0; i < b.Size(); i++)
// 	{
// 		cout << b.Peek(i) << endl;
// 	}
	//test UF
// 	ifstream ifs("../data/largeUF.txt");
// 	int nTotal = 0;
// 	ifs >> nTotal;
// 	int x = 0;
// 	int y = 0;
// 	int i = 0;
// 	ShowTime();
// 	QuickUnionUF uf(nTotal);
// 	while (ifs >> x)
// 	{
// 		i++;
// 		ifs >> y;
// 		uf.Union(x, y);
// 	}
// 	ifs.close();
// 	cout << "Compotent count: " << uf.ComponentCount()<<endl;
// 	ShowTime();

	//test SORT
//	SortCompare::CompareTwoSortAlgorithms("MergeSort", "BinaryHeapSort", 1000, 100);

	//test PQ
//	PQCompare<int>::CompareTwoPQ("BinaryHeapMinPQ", "BinaryHeapIndexMinPQ", 10, 1);

	//test ST
//	STCompare::Compare("BST", "RedBlackST", 10000000, 1);

	//test Graph
// 	ifstream ifs("../data/tinyG.txt");
// 	Graph  G(ifs);
// 	G.Show();
// 	ifs.close();
//  	DepthFirstSearch dfs(G, 0);
//  	BreadthFirstSearch bfs(G, 0);
//  	cout << "Search Result Count are " << dfs.Count() << " and " << bfs.Count() << endl;
// 	DepthFirstPaths dfp(G, 0);
// 	BreadthFirstPaths bfp(G, 0);
// 	cout << "0 path to 6 are: " << endl;
// 	Stack<int> s1 = dfp.PathTo(6);
// 	while (!s1.IsEmpty())
// 	{
// 		cout << s1.Pop();
// 		if(!s1.IsEmpty())
// 		{
// 			cout << "-";
// 		}
// 	}
// 	cout << endl;
// 	Stack<int> s2 = bfp.PathTo(6);
// 	while (!s2.IsEmpty())
// 	{
// 		cout << s2.Pop();
// 		if (!s2.IsEmpty())
// 		{
// 			cout << "-";
// 		}
// 	}
// 	cout << endl;
// 	DepthFirstCC dfcc(G);
// 	BreadthFirstCC bfcc(G);
// 	cout << "CC are: " << dfcc.Count() << " and " << bfcc.Count() << endl;
// 
// 	DepthFirstCycle dfcy(G);
// 	BreadthFirstCycle bfcy(G);
// 	cout << "Cycle are " << dfcy.HasCycle() << " and " << bfcy.HasCycle() << endl;
// 
// 	DepthFirstTwoColor dftc(G);
// 	BreadthFirstTwoColor bftc(G);
// 	cout << "TwoColor are " << dftc.IsTwoColor() << " and " << bftc.IsTwoColor() << endl;

	//test DirectedGraph
// 	ifstream ifs("../data/tinyDAG.txt");
// 	DiGraph G(ifs);
// 	ifs.close();
// 	G.Show();
// 	DirectedDFSearch DDFS(G, 0);
// 	cout << "Search result count is " << DDFS.Count() << endl;
// 	DirectedDFPaths DDFP(G, 0);
// 	DirectedBFPaths DBFP(G, 0);
// 	cout << "0 path to 4 are: " << endl;
// 	Stack<int> s1 = DDFP.PathTo(4);
// 	while (!s1.IsEmpty())
// 	{
// 	 	cout << s1.Pop();
// 	 	if(!s1.IsEmpty())
// 	 	{
// 	 		cout << "-";
// 		}
// 	}
// 	cout << endl;
// 	Stack<int> s2 = DBFP.PathTo(4);
// 	while (!s2.IsEmpty())
// 	{
// 		cout << s2.Pop();
// 		if (!s2.IsEmpty())
// 		{
// 			cout << "-";
// 		}
// 	}
// 	cout << endl;
// 	DirectedDFCycle DDFC(G);
// 	cout << "G has cycle: " << DDFC.HasCycle() << endl;
// 	DirectedDFOrder DDFO(G);
// 	Queue<int> pre = DDFO.Pre();
// 	Queue<int> post = DDFO.Post();
// 	Stack<int> reversePost = DDFO.ReversePost();
// 	cout << "Pre:" << endl;
// 	while (!pre.IsEmpty())
// 	{
// 		cout << pre.Dequeue() << " ";
// 	}
// 	cout << endl;
// 	cout << "Post:" << endl;
// 	while (!post.IsEmpty())
// 	{
// 		cout << post.Dequeue() << " ";
// 	}
// 	cout << endl;
// 	cout << "ReversePost:" << endl;
// 	while (!reversePost.IsEmpty())
// 	{
// 		cout << reversePost.Pop() << " ";
// 	}
// 	cout << endl;
// 	DirectedDFTopologic DDFT(G);
// 	cout << "Topologic is :" << endl;
// 	if (DDFT.HasOrder())
// 	{
// 		Stack<int> tp = DDFT.Order();
// 		while (!tp.IsEmpty())
// 		{
// 			cout << tp.Pop() << " ";
// 		}
// 	}
// 	else
// 	{
// 		cout << "has cycle,can't topologic";
// 	}
// 	cout << endl;
// 	DirectedDFSCC DDFSCC(G);
// 	cout << "SCC count is " << DDFSCC.Count() << endl;

// 	ifstream ifs("../data/tinyEWG.txt");
// 	EdgeWeightedGraph G(ifs);
// 	ifs.close();
// 	G.Show();
// 	cout << "Lazy Prim MST:" << endl;
// 	LazyPrimMST lazyPrim(G);
// 	Queue<Edge> qLazyPrim = lazyPrim.Edges();
// 	for (int i = 0; i < qLazyPrim.Size(); i++)
// 	{
// 		Edge e = qLazyPrim.Peek(i);
// 		cout << e.Either() << " -- " << e.Other(e.Either())<<" : "<<e.Weight()<<endl;
// 	}
// 
// 	cout << "Prim MST:" << endl;
// 	PrimMST prim(G);
// 	Queue<Edge> qPrim = prim.Edges();
// 	for (int i = 0; i < qPrim.Size(); i++)
// 	{
// 		Edge e = qPrim.Peek(i);
// 		cout << e.Either() << " -- " << e.Other(e.Either()) << " : " << e.Weight() << endl;
// 	}
// 
// 	cout << "Kruskal MST:" << endl;
// 	KruskalMST kruskal(G);
// 	Queue<Edge> qKruskal = kruskal.Edges();
// 	for (int i = 0; i < qKruskal.Size(); i++)
// 	{
// 		Edge e = qKruskal.Peek(i);
// 		cout << e.Either() << " -- " << e.Other(e.Either()) << " : " << e.Weight() << endl;
// 	}
// 	ifstream ifs("../data/tinyEWDnc.txt");
// 	EdgeWeightedDiGraph EWD(ifs);
// 	ifs.close();
// 	EWD.Show();
// 	cout << "DijkstraSP:" << endl;
// 	DijkstraSP spDijkstra(EWD, 0);
// 	cout << "Has negative weight edges: " << spDijkstra.HasNegativeWeightEdge() << endl;
// 	cout << "Has path to X: " << spDijkstra.HasPathTo(6) << endl;
// 	if(!spDijkstra.HasNegativeWeightEdge() && spDijkstra.HasPathTo(6))
// 	{
// 		Stack<DirectedEdge> s1 = spDijkstra.PathTo(6);
// 		while (!s1.IsEmpty())
// 		{
// 			s1.Pop().Show();
// 		}
// 	}
// 	cout << "TopologicSP:" << endl;
// 	TopologicSP spTopoLogic(EWD, 0);
// 	cout << "Has cycle: " << spTopoLogic.HasCycle() << endl;
// 	cout << "Has path to X: " << spTopoLogic.HasPathTo(3) << endl;
// 	if (!spTopoLogic.HasCycle() && spTopoLogic.HasPathTo(3))
// 	{
// 		Stack<DirectedEdge> s = spTopoLogic.PathTo(3);
// 		while (!s.IsEmpty())
// 		{
// 			s.Pop().Show();
// 		}
// 	}
// 	cout << "BellmanFordSP:" << endl;
// 	BellmanFordSP spBellmanFord(EWD, 0);
// 	cout << "Has negative weight cycle:" << spBellmanFord.HasNegativeWeightCycle() << endl;
// 	cout << "Has path to X: " << spBellmanFord.HasPathTo(4) << endl;
// 	if (!spBellmanFord.HasNegativeWeightCycle())
// 	{
// 		if (spBellmanFord.HasPathTo(4))
// 		{
// 			Stack<DirectedEdge> s = spBellmanFord.PathTo(4);
// 			while (!s.IsEmpty())
// 			{
// 				s.Pop().Show();
// 			}
// 		}
// 	}
// 	else
// 	{
// 		Bag<DirectedEdge> b = spBellmanFord.NegativeWeightCycle(EWD);
// 		cout << "Negative weight cycle:" << endl;
// 		for (int i = 0; i < b.Size(); i++)
// 		{
// 			b.Peek(i).Show();
// 		}
// 	}

	//test String Sort
// 	string sArrayLSD[] = { "4PGC938", "2IYE230", "3CI0720", "1ICK750", "1OHV845", "4JZY524", "1ICK750", "3CI0720", 
// 			"1OHV845", "1OHV845", "2RLA629", "2RLA629", "3ATW723"};
// 	LSD::Sort(sArrayLSD, 13, 7);
// 	cout << "LSD result" << endl;
// 	for (int i = 0; i < 13; i++)
// 	{
// 		cout << sArrayLSD[i] << endl;
// 	}
// 	cout << endl;
// 	string sArrayMSD[] = { "she", "sells", "seashells", "by", "the", "seashore", "the", "shells",
// 		"she", "sells", "are", "surely", "seashells" };
// 	MSD::Sort(sArrayMSD, 13);
// 	cout << "MSD result" << endl;
// 	for (int i = 0; i < 13; i++)
// 	{
// 		cout << sArrayMSD[i] << endl;
// 	}
// 	cout << endl;

	string sArrayQuick3String[] = { "she", "sells", "seashells", "by", "the", "seashore", "the", "shells",
		"she", "sells", "are", "surely", "seashells" };
// 	Quick3String::Sort(sArrayQuick3String, 13);
// 	cout << "Quick3String result" << endl;
// 	for (int i = 0; i < 13; i++)
// 	{
// 		cout << sArrayQuick3String[i] << endl;
// 	}
// 	cout << endl;

	//test string ST
//	TrieST<int> trie(128);
// 	trie.Put("she", 0);
// 	trie.Put("sells", 1);
// 	trie.Put("seashells", 2);
// 	trie.Put("by", 3);
// 	trie.Put("the", 4);
// 	trie.Put("seashore", 5);
// 	trie.Put("the", 6);
// 	trie.Put("she", 7);
// 	trie.Put("are", 8);
// 	trie.Put("surely", 9);
// 	trie.Put("seashells", 10);
// 	trie.Put("sells", 11);
// 	trie.Put("shells", 12);
// 	trie.Put("sae", 13);
// 	trie.Put("thea", 14);
// 	if (trie.Contains("sells"))
// 	{
// 		cout << trie.Get("sells")<<endl;
// 	}
// 	if (!trie.Contains("seasho"))
// 	{
// 		cout << "no seasho" << endl;
// 	}
// 	if (!trie.Contains("seashooo"))
// 	{
// 		cout << "no seashooo" << endl;
// 	}
// 	trie.Delete("sells");
// 	if (trie.Contains("sells"))
// 	{
// 		cout << trie.Get("sells") << endl;
// 	}
// 	cout << "KeysWithPrefix: " << endl;
// 	Queue<string> q = trie.KeysWithPrefix("");
// 	while (!q.IsEmpty())
// 	{
// 		cout << q.Dequeue() << endl;
// 	}
// 	cout << "KeyThatMatch: " << endl;
// 	Queue<string> q1 = trie.KeysThatMatch("s.e");
// 	while (!q1.IsEmpty())
// 	{
// 		cout << q1.Dequeue() << endl;
// 	}
// 	cout << "LongestPrefixOf: " << endl;
// 	string s = trie.LongestPrefixOf("theab");
// 	cout << s << endl;
// 	TST<int> tst;
// 	tst.Put("she", 0);
// 	tst.Put("sells", 1);
// 	tst.Put("seashells", 2);
// 	tst.Put("by", 3);
// 	tst.Put("the", 4);
// 	tst.Put("seashore", 5);
// 	tst.Put("the", 6);
// 	tst.Put("she", 7);
// 	tst.Put("are", 8);
// 	tst.Put("surely", 9);
// 	tst.Put("seashells", 10);
// 	tst.Put("sells", 11);
// 	tst.Put("shells", 12);
// 	tst.Put("sae", 13);
// 	tst.Put("thea", 14);
// 	if (tst.Contains("sells"))
// 	{
// 		cout << tst.Get("sells") << endl;
// 	}
// 	if (!tst.Contains("seasho"))
// 	{
// 		cout << "no seasho" << endl;
// 	}
// 	if (!tst.Contains("seashooo"))
// 	{
// 		cout << "no seashooo" << endl;
// 	}
// 	tst.Delete("sells");
// 	if (tst.Contains("sells"))
// 	{
// 		cout << tst.Get("sells") << endl;
// 	}
// 	cout << "KeysWithPrefix: " << endl;
// 	Queue<string> q = tst.KeysWithPrefix("");
// 	while (!q.IsEmpty())
// 	{
// 		cout << q.Dequeue() << endl;
// 	}
// 	cout << "KeyThatMatch: " << endl;
// 	Queue<string> q1 = tst.KeysThatMatch("s.e");
// 	while (!q1.IsEmpty())
// 	{
// 		cout << q1.Dequeue() << endl;
// 	}
// 	cout << "LongestPrefixOf: " << endl;
// 	string s = tst.LongestPrefixOf("theab");
// 	cout << s << endl;
	
	//test string search
// 	KMP kmp(128, "123456");
// 	int i = kmp.Search("12345543212345468742145612489761211234569874147852369871");
// 	BoyerMoore boyer(128, "123456");
// 	int j = boyer.Search("12345543212345468742145612489761211234569874147852369871");
// 	RabinKarp rabin(128, "123456");
// 	int k = rabin.Search("12345543212345468742145612489761211234569874147852369871");

	//test NFA
// 	NFA nfa("A");
// 	cout << nfa.Recognizes("BAB");

	//test Huffman
//	cout<<Huffman::Expand(Huffman::Compress("abcaaabaaaaacaaaabcaaaaaabbaaaaadefaaaaaaaghaaggz"));
	//test LZW
	cout << LZW::Expand(LZW::Compress("abcaaabaaaaacaaaabcaaaaaabbaaaaadefaaaaaaaghaaggz"));
	return 0;
}