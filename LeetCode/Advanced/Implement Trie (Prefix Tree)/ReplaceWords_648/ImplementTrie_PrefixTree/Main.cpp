#include <iostream>
#include "NBS_Trie.h"

using namespace std;

void main()
{
	//�������Զ���
	unique_ptr<Trie> trie(new Trie());

	trie->insert("apple");
	bool isTrue = trie->search("apple");   // ���� true
	isTrue = trie->search("app");     // ���� false
	isTrue = trie->startsWith("app"); // ���� true
	trie->insert("app");
	isTrue = trie->search("app");     // ���� true

	isTrue = trie->search("apple");
	isTrue = trie->startsWith("bp");


	return;
}