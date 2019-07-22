//*************************************
//ʱ�䣺2019/7/21
//���ƣ�ǰ׺�����ⷨһ�� unordered_map
//*************************************
#pragma once
#include<iostream>
#include <unordered_map>

using namespace std;

class Trie
{
public:
	/** Initialize your data structure here. */
	Trie(): root_(new TrieNode()) {}

	/** Inserts a word into the trie. */
	void insert(string word) 
	{
		TrieNode* p = root_.get();
		for (const char c : word)
		{
			if (!p->children.count(c))
				p->children[c] = new TrieNode();
			p = p->children[c];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) const
	{
		const TrieNode* p = find(word);
		return p && p->is_word; //��p�ڵ㲻Ϊnullptr��is_word��true����������棬���ڷ���false
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) const
	{
		return find(prefix) != nullptr; //find����ֵ��Ϊnullptr��Ϊ�棬����Ϊfalse
	}

private:
	struct TrieNode
	{
		TrieNode(): is_word(false) {} //�޲ι��캯��
		~TrieNode()//���������
		{
			for (auto& kv : children)
				if (kv.second) delete kv.second;
		}

		bool is_word;
		unordered_map<char, TrieNode*> children;
	};

	//�ҵ�ǰ׺�ڵ㷵�ض�Ӧ�Ľڵ㣬���ڷ���false
	const TrieNode* find(const string& prefix) const
	{
		const TrieNode* p = root_.get();
		for (const char c : prefix)
		{
			if(!p->children.count(c))
				return nullptr;
			p = p->children.at(c);
		}
		return p;
	}

	//ǰ׺����
	unique_ptr<TrieNode> root_;
};