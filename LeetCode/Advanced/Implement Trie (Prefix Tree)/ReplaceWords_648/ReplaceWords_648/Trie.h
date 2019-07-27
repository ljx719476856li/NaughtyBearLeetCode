//*************************************
//ʱ�䣺2019/7/23
//���ƣ�648. �����滻
//˼·��
/*
������������һ��ǰ׺�ֵ䣬�ָ���һ�����ӣ������ǽ������нϳ��ĵ��ʻ�����ǰ׺(�����ǰ׺�ֵ��д��ڵĻ�)��
���Ƕ��ھ����е�һ�������������ǰ׺�أ��ǲ��ǿ��Ը��ݵ�һ����ĸ�����ٶ�λ�أ�����cattle������ʵ�����ĸ��c����ô������ǰ׺�ֵ��������п�ͷ��c��ǰ׺
*/
//**********************************

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	class TrieNode {
	public:
		bool isWord;
		TrieNode *child[26];
		TrieNode() : isWord(false) {
			for (auto &a : child) a = NULL;
		}
		~TrieNode() 
		{
			for (TrieNode* children : child)
			{
				if(children) delete children;
			}
		}
	};

	string replaceWords(vector<string>& dict, string sentence) {
		string res = "", t = "";
		istringstream is(sentence);
		TrieNode *root = new TrieNode();
		for (string word : dict) {
			insert(root, word);
		}
		while (is >> t) {
			if (!res.empty()) res += " ";
			res += findPrefix(root, t);
		}
		return res;
	}

	void insert(TrieNode* node, string word) {
		for (char c : word) {
			if (!node->child[c - 'a']) node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->isWord = true;
	}

	string findPrefix(TrieNode* node, string word) {
		string cur = "";
		for (char c : word) {
			if (!node->child[c - 'a']) break;
			cur.push_back(c);
			node = node->child[c - 'a'];
			if (node->isWord) return cur;
		}
		return word;
	}
};