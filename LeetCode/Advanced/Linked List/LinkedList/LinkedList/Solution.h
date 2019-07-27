#pragma once
#include <iostream>
using namespace std;
//Definition for singly - linked list.
//https://docs.google.com/spreadsheets/d/1SbpY-04Cz8EWw3A_LBUmDEXKUMO31DBjfeMoA0dlfIA/edit#gid=410905529

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class  Solution
{
public:
	//�������
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(-1), *cur = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			//��ȡ�����б��е�valueֵ
			int val1 = l1 ? l1->val : 0; 
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry; //val1 + val2 + ��λ(carry) = ������ͬλ���ĺ�
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next; //curָ����һλ
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		if (carry) cur->next = new ListNode(1); //����һ����λ
		return dummy->next;
	}

	// ɾ������ĵ�����N���ڵ�
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		//���������������� > 1
		if (!head->next) 
			return nullptr;
		
		ListNode* cur = head, *pre = head;
		for (int i = 0; i < n; ++i)
			cur = cur->next;

		//ɾ������ͷ�ڵ�
		if (!cur) return head->next;
		//�ƶ�pre���Լ�cur��ֱ��cur����β��
		while (cur->next)
		{
			cur = cur->next;
			pre = pre->next;
		}

		pre->next = pre->next->next;
		return head;
	}
	
	//�������������еĽڵ�
	ListNode* swapPairs(ListNode* head)
	{
		if (!head || !head->next)
			return head;

		//��tmpָ��ָ��head->next
		ListNode* tmp = head->next;
		head->next = swapPairs(head->next->next);
		tmp->next = head;
		return tmp;
	}

	//��ת����
	//��תһ��������
	ListNode* reverseList(ListNode* head) 
	{
		if (!head || !head->next) 
			return head;

		ListNode *newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}

};