#include "Solution.h"

void main()
{
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(4);

	Solution sln;
	sln.reverseList(ln);

	return;
}