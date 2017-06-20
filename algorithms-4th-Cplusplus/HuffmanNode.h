#pragma once


class HuffmanNode
{
public:
	HuffmanNode();
	HuffmanNode(char c, int freq, HuffmanNode* left, HuffmanNode* right);
	HuffmanNode(const HuffmanNode& node);
	bool IsLeaf();
public:
	char m_c;
	int m_freq;
	HuffmanNode* m_left;
	HuffmanNode* m_right;

	friend bool operator>(HuffmanNode& node1, HuffmanNode& node2);
	friend bool operator<(HuffmanNode& node1, HuffmanNode& node2);
	friend bool operator==(HuffmanNode& node1, HuffmanNode& node2);
};
HuffmanNode::HuffmanNode():m_c(0), m_freq(0), m_left(0), m_right(0)
{}

HuffmanNode::HuffmanNode(char c, int freq, HuffmanNode* left, HuffmanNode* right)
	:m_c(c), m_freq(freq), m_left(left), m_right(right)
{}

HuffmanNode::HuffmanNode(const HuffmanNode& node)
{
	this->m_c = node.m_c;
	this->m_freq = node.m_freq;
	this->m_left = node.m_left;
	this->m_right = node.m_right;
}

bool HuffmanNode::IsLeaf()
{
	return this->m_left == 0 && this->m_right == 0;
}

bool operator>(HuffmanNode& node1, HuffmanNode& node2)
{
	return node1.m_freq > node2.m_freq;
}
bool operator<(HuffmanNode& node1, HuffmanNode& node2)
{
	return node1.m_freq < node2.m_freq;
}
bool operator==(HuffmanNode& node1, HuffmanNode& node2)
{
	return node1.m_freq == node2.m_freq;
}
