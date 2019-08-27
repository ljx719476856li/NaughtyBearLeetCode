#include <iostream>
#include<vector>
using namespace std;

/*
��Ŀ���������ǰ׺��
	(1) ���insert����
	(2) �����ַ���
		i). �����ַ��������˼���
		ii). �����ַ����Ƿ����
	(3) ɾ���ֵ����д��ڵ��ַ���
		i). ��β������ɾ��
		ii). ����Ƶ�Ѿ�ֻ��һ����(����·��path�Լ�Ϊ0��)��ֱ�ӽ�next��������Ϊnullptr
	 (4) ǰ׺����
*/

struct TrieNode
{
	int path;
	int end;
	vector<TrieNode*> nexts;

	TrieNode() :path(0), end(0), nexts(26) {}
};

class Trie
{
public:
	TrieNode* root;
	Trie() { root = new TrieNode(); }

	void Insert(const string& word);
	bool IsExist(const string& word);
	int CntSearch(const string& word);
	void Delete(const string& word);
	int prefixNumber(const string& word);
};

int Trie::prefixNumber(const string& word)
{
	if (word.empty())
		return 0;

	TrieNode* node = root;
	int idx;
	for (char ch: word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return 0;
		
		node = node->nexts[idx];
	}
	return node->path;
}

void Trie::Delete(const string& word)
{
	if (word.empty())
		return;
	TrieNode* node = root;
	//unique_ptr<TrieNode> node = make_unique<TrieNode>(root);
	int idx = 0;
	for (auto ch : word)
	{
		idx = ch - 'a';
		if (--node->nexts[idx]->path == 0)
		{
			node->nexts[idx] = nullptr;
			return;
		}
		node = node->nexts[idx];
	}
	node->end--;
	return;
}

int Trie::CntSearch(const string& word)
{
	if (word.empty())
		return 0;

	int idx = 0;
	TrieNode* node = root;
	for (char ch : word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return 0;

		node = node->nexts[idx];
	}

	return node->end;
}

bool Trie::IsExist(const string& word)
{
	if (word.empty())
		return false;

	int idx = 0;
	TrieNode* node = root;
	for (char ch : word)
	{
		idx = ch - 'a';
		if (node->nexts[idx] == nullptr)
			return false;

		node = node->nexts[idx];
	}

	return true;
}

void Trie::Insert(const string& word)
{
	if (word.empty())
		return;

	int idx = 0;
	TrieNode* node = root;
	for (auto ch : word)
	{
		idx = ch - 'a'; //���ֵ�������'a'-'z'���ʱ
		if (node->nexts[idx] == nullptr)
			node->nexts[idx] = new TrieNode();
		node = node->nexts[idx];
		node->path++;
	}
	node->end++;
	return;
}

int main()
{
	TrieNode* root = new TrieNode();

	Trie head;
	head.Insert("abc");
	head.Insert("abca");
	//head.Insert("abcs");
	//head.Insert("abcf");
	//head.Insert("abce");
	cout << "is exit " << (head.IsExist("abcs") ? "Exit" : "Inexistence") << endl;
	head.Delete("abcs");
	cout << "is exit " << (head.IsExist("abcs") ? "Exit" : "Inexistence") << endl;
	head.Delete("abc");
	cout << "Seach " << head.CntSearch("abc") << endl;
	cout << "CNT " << head.prefixNumber("abc") << endl;
	return 0;
}