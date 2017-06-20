#pragma once
#include "bitstream.h"
#include <string>
#include "BinaryHeapMinPQ.h"
#include "HuffmanNode.h"
using std::string;
class Huffman
{
public:
	static string Compress(string s);
	static string Expand(string s);
private:
	static HuffmanNode* BuildTrie(int*const freq);
	static void BuildCode(HuffmanNode* pNode, string*const code, string s);
	static void WriteTrie(HuffmanNode* pNode, ostringbitstream& obits);
	static HuffmanNode* ClearHuffmanTree(HuffmanNode* pNode);

	static HuffmanNode* ReadTrie(istringbitstream& ibits);
private:
	static const int R;
};

const int Huffman::R = 256;
string Huffman::Compress(string s)
{
	string result;
	ostringbitstream obits;
	int freq[R] = { 0 };
	for (int i = 0; i < s.length(); i++)
	{
		freq[s.at(i)]++;
	}
	HuffmanNode* root = BuildTrie(freq);
	string codeTable[R] = { "" };
	BuildCode(root, codeTable, "");
	WriteTrie(root, obits);
	obits << s.length();
	for (int i = 0; i < s.length(); i++)
	{
		string code = codeTable[s.at(i)];
		for (int j = 0; j < code.length(); j++)
		{
			if (code.at(j) == '0')
			{
				obits.writeBit(0);
			}
			else
			{
				obits.writeBit(1);
			}
		}
	}
	result = obits.str();
	ClearHuffmanTree(root);
	return result;
}
string Huffman::Expand(string s)
{
	string result;
	istringbitstream ibits(s);
	HuffmanNode* root = ReadTrie(ibits);
	int N = 0;
	ibits >> N;
	for (int i = 0; i < N; i++)
	{
		HuffmanNode* pNode = root;
		while (!pNode->IsLeaf())
		{
			if (ibits.readBit()) pNode = pNode->m_right;
			else pNode = pNode->m_left;
		}
		result += pNode->m_c;
	}
	ClearHuffmanTree(root);
	return result;
}

HuffmanNode* Huffman::BuildTrie(int*const freq)
{
	BinaryHeapMinPQ<HuffmanNode> pqMin(R);
	for (int i = 0; i < R; i++)
	{
		if (freq[i] != 0)
		{
			pqMin.Insert(HuffmanNode(i, freq[i], 0, 0));
		}
	}
	while (pqMin.Size() > 1)
	{
		HuffmanNode* pNodeLeft = new HuffmanNode(pqMin.DelMin());
		HuffmanNode* pNodeRight = new HuffmanNode(pqMin.DelMin());
		pqMin.Insert(HuffmanNode(0, pNodeLeft->m_freq + pNodeRight->m_freq, pNodeLeft, pNodeRight));
	}
	return new HuffmanNode(pqMin.Min());
}

void Huffman::BuildCode(HuffmanNode* pNode, string*const codeTable, string s)
{
	if (pNode == 0)	return;
	if (pNode->IsLeaf())
	{
		codeTable[pNode->m_c] = s;
	}
	else
	{
		BuildCode(pNode->m_left, codeTable, s + "0");
		BuildCode(pNode->m_right, codeTable, s + "1");
	}
	return;
}

void Huffman::WriteTrie(HuffmanNode* pNode, ostringbitstream& obits)
{
	if (pNode == 0) return;
	if (pNode->IsLeaf())
	{
		obits.writeBit(1);
		obits << pNode->m_c;
	}
	else
	{
		obits.writeBit(0);
		WriteTrie(pNode->m_left, obits);
		WriteTrie(pNode->m_right, obits);
	}
	return;
}

HuffmanNode* Huffman::ClearHuffmanTree(HuffmanNode* pNode)
{
	if (pNode == 0) return 0;
	pNode->m_left = ClearHuffmanTree(pNode->m_left);
	pNode->m_right = ClearHuffmanTree(pNode->m_right);
	delete pNode;
	return 0;
}

HuffmanNode* Huffman::ReadTrie(istringbitstream& ibits)
{
	char c;
	if (ibits.readBit())
	{
		ibits >> c;
		return new HuffmanNode(c, 0, 0, 0);
	}
	else
	{
		HuffmanNode* pNodeLeft = ReadTrie(ibits);
		HuffmanNode* pNodeRight = ReadTrie(ibits);
		return new HuffmanNode(0, 0, pNodeLeft, pNodeRight);
	}
}