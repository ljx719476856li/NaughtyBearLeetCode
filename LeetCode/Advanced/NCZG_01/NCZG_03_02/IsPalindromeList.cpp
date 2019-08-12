#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node
{
	int var;
	Node* next;
	Node() :var(0), next(nullptr) {}
	Node(int var) : var(var) {}
	Node(int var, Node* next) : var(var), next(nullptr) {}
};

class PalindromeList
{
public:
	bool IsPalindromeList_pen1();	
	bool IsPalindromeList_pen2();
	bool IsPalindromeList_interview();

private: 
	bool Cmp(stack<Node*> help)
	{
		Node* pHead = m_pHead;
		while (help.size() > 0)
		{
			if (pHead->var != help.top()->var)
				return false;
			pHead = pHead->next;
			help.pop();
		}
		return true;
	}
	int Size()
	{
		int length = 0;
		while (m_pHead->next)
			++length;
		return length;
	}

public:
	Node* m_pHead;
};

/*
˼·��ʹ�ø���ջ���������
			a). ͨ���������������ݵ���ջ�У�Ȼ��ͨ��ջ���������ζ�ȡ��������ԭ�������Ƚ�
			b). ͨ������ָ�룬��ָ������������ָ����һ�������������
				1) ��������Ϊż��ʱ����ָ���ͣ���м����߽ڵ�
				2) ��������Ϊ����ʱ����ָ���ͣ���м�ڵ�
			c). ͨ�����Ͻ�������а�μ���ջ�У�Ȼ��ͨ��ջ�����У�һ�ν����Ұ�ν��бȽ�
����ʱ�临�Ӷȶ�Ϊ��O(N)������ռ临�Ӷ�O(N)
*/
bool PalindromeList::IsPalindromeList_pen1()
{
	//����ջ
	stack<Node*> help;
	Node* pHead = m_pHead;
	while (pHead != nullptr)
	{
		help.push(pHead);
		pHead = pHead->next;
	}
	
	return Cmp(help);
}
bool PalindromeList::IsPalindromeList_pen2()
{
	if (m_pHead == nullptr || m_pHead->next == nullptr)
		return true;

	//����ջ
	stack<Node*> help;
	Node* fast = m_pHead, *slow = m_pHead, *mid = nullptr;

	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	while (slow->next != nullptr)
	{
		help.push(slow->next);
		slow = slow->next;
	}

	return Cmp(help);
}

/* 
˼·��ͨ���ı��а�β��������ָ��������
			A). ͨ������ָ�룬��ָ������������ָ����һ�������������
				a) ��������Ϊż��ʱ����ָ���ͣ���м����߽ڵ�
				b) ��������Ϊ����ʱ����ָ���ͣ���м�ڵ�
			B). ͨ�����Ͻ�������а�β���ָ�뷴���ٽ���ָ��ָ����м�ڵ�ָ��null
����ʱ�临�Ӷȶ�Ϊ��O(N)������ռ临�Ӷ�O(1)
*/
bool PalindromeList::IsPalindromeList_interview()
{
	if (m_pHead == nullptr || m_pHead->next == nullptr)
		return true;
	Node* fast = m_pHead, *slow = m_pHead;
	while (fast->next != nullptr && fast->next->next != nullptr) //�ҵ��е�
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	fast = slow->next;
	slow->next = nullptr;
	Node* temp = nullptr;
	while (fast != nullptr)
	{
		temp = fast->next;
		fast->next = slow;
		slow = fast;
		fast = temp;
	}
	fast = m_pHead;
	temp = slow;
	while (fast != nullptr)
	{
		if (fast->var != slow->var)
			return false;
		fast = fast->next;
		slow = slow->next;
	}
	fast = temp->next;
	temp->next = nullptr;
	while (fast != nullptr)
	{
		slow = fast->next;
		fast->next = temp;
		temp = fast;
		fast = slow;
	}

	return true;
}

int main()
{
	PalindromeList sln;
	sln.m_pHead = new Node(1);
	sln.m_pHead->next = new Node(2);
	sln.m_pHead->next->next = new Node(3);
	sln.m_pHead->next->next->next = new Node(1, nullptr);
	//sln.m_pHead->next->next->next->next = new Node(1, nullptr);


	bool res1 = sln.IsPalindromeList_pen1();
	bool res2 = sln.IsPalindromeList_pen2();
	bool res3 = sln.IsPalindromeList_interview();
	return 0;
}