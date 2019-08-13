//Code_14_FindFirstIntersectNode
#include <iostream>
using namespace std;

struct Node
{
public:
	int var;
	Node* next;
	Node() : var(0), next(nullptr) {}
	Node(int data) : var(data), next(nullptr) {}
};

/*
	˼·����Ŀ��֪������������������л���Ҳ�����޻����ɴ˿��ܳ��ֵ����˽ṹ
		a). ��< // >��  (��������û�л������)
		b). ���� �� ��     (��������һ���л���һ��û�л�)
		c). ���� �� ����  // >���� // >��
	A). ���� a) ����ͼ��֪������������û�л�������������������ཻ�����˽ṹ��
		1)  �ɴ˳��������Ի�õ�����������head1(len1, end1)��head2(len2, end2)
		2)  ����������ͨ���Ƚ�end1��end2�ɵ�֪(�˴�end1����end2��ʾ����β���ڵ���ڴ��ַ)��
			(1)  end1 == end2 ��������ض��ཻ�������ཻ�ĵ�һ���ڵ㲻һ����β���ڵ�
				ʹ��len1��len2��  ���len1=100 len2=80  head1����20�� Ȼ��head2��ʼ��head1�𲽣� ����һ���Ṳͬ�ߵ���һ���ཻ�Ľڵ㴦
			(2) end2 != end1 ������ز����ཻ����Ϊ��������ṹ�����ܳ��� ��(����) ���ֽṹ
	B). ���� b)����ͼ��֪������������һ���л���һ��û�л���ʱ�򣬱ض���������ཻ�����(������ṹ���ԣ��������)
	C). ���� c)����ͼ��֪���������������л�ʱ���ض�����������������˽ṹ
		1)  �ɴ˳��������Ի�õ�����������head1(len1, loop1)��head2(len2, loop2)
		1)  ��� loop1 == loop2��Ϊ >����  ���˽ṹ
		2) ���loop1 != loop2 ��Ϊ ���� �� ���� // >�� ���˽ṹ
*/

class FindFirstInterserct
{
public:
	Node* GetInterserctNode();
	
	Node* head1;
	Node* head2;

private:
	Node* GetLoopNode(Node* head);
	Node* NoLoop();
	Node* BothLoop(Node* loop1, Node* loop2);
};

Node* FindFirstInterserct::GetInterserctNode()
{
	//�˱߽粻�������ж�
	if (head1 == nullptr && head2 == nullptr)
		return nullptr;

	Node* loop1 = GetLoopNode(head1);
	Node* loop2 = GetLoopNode(head2);

	if (loop1 == nullptr && loop2 == nullptr)
		return NoLoop();
	else if (loop1 != nullptr && loop2 != nullptr)
		return BothLoop(loop1, loop2);

	return nullptr;
}

Node* FindFirstInterserct::GetLoopNode(Node* head)
{
	Node* fast = head, *slow = head;

	//����ָ����������л�
	while (fast != slow)
	{
		if (fast == nullptr && fast->next->next == nullptr)
			return nullptr;

		fast = fast->next->next;
		slow = slow->next;
	}
	fast = head;
	//�˴��������ض����뻷�ĵ�һ���ڵ�
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}
//��������û��
Node* FindFirstInterserct::NoLoop()
{	
	Node* end1 = nullptr, *end2 = nullptr;
	int subtractLen = 0;

	Node* pHead1 = head1, *pHead2 = head2;
	while (pHead1 != nullptr)
	{
		subtractLen++;
		if (pHead1->next == nullptr)
			end1 = pHead1;
		pHead1 = pHead1->next;
	}
	while (pHead2 != nullptr)
	{
		subtractLen--;
		if (pHead2->next == nullptr)
			end2 = pHead2;
		pHead2 = pHead2->next;
	}
	if (end1 != end2)
		return nullptr;


	pHead1 = subtractLen > 0 ? head1 : head2;
	pHead2 = head1 == pHead1 ? head2 : head1;

	subtractLen = abs(subtractLen);
	while (subtractLen > 0)
	{
		pHead1 = pHead1->next;
		subtractLen--;
	}
	while (pHead1 != pHead2)
	{
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}

	return pHead1;

}
//���������л�
Node* FindFirstInterserct::BothLoop(Node* loop1, Node* loop2)
{
	if (loop1 == loop2)
	{
		//ģ��NoLoop�Ĳ���
		Node* cur1 = head1;
		Node* cur2 = head2;
		int subtractLen = 0;
		while (cur1 != loop1)
		{
			subtractLen++;
			cur1 = cur1->next;
		}
		while (cur2 != loop2)
		{
			subtractLen--;
			cur2 = cur2->next;
		}
		
		cur1 = subtractLen > 0 ? head1 : head2;
		cur2 = head1 == cur1 ? head2 : head1;
		subtractLen = abs(subtractLen);
		while (subtractLen > 0)
		{
			cur1 = cur1->next;
			subtractLen --;
		}

		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else //loop1 != loop2��ͨ������loop1�ж����Ǹ����˽ṹ
	{
		Node* temp = loop1->next;
		while (temp != loop1)
		{
			if (temp = loop2)
				return loop2;
			temp = temp->next;
		}
		return nullptr;
	}
}


int main()
{
	FindFirstInterserct sln;

	// 1->2->3->4->5->6->7->null
	sln.head1 = new Node(1);
	sln.head1->next = new Node(2);
	sln.head1->next->next = new Node(3);
	sln.head1->next->next->next = new Node(4);
	sln.head1->next->next->next->next = new Node(5);
	sln.head1->next->next->next->next->next = new Node(6);
	sln.head1->next->next->next->next->next->next = new Node(7);

	// 0->9->8->6->7->null
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next->next->next->next->next; // 8->6
	

	// 1->2->3->4->5->6->7->4->->->
	sln.head1 = new Node(1);
	sln.head1->next = new Node(2);
	sln.head1->next->next = new Node(3);
	sln.head1->next->next->next = new Node(4);
	sln.head1->next->next->next->next = new Node(5);
	sln.head1->next->next->next->next->next = new Node(6);
	sln.head1->next->next->next->next->next->next = new Node(7);
	sln.head1->next->next->next->next->next->next = sln.head1->next->next->next; // 7->4

	// 0->9->8->2->->->
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next; // 8->2
	//System->out->println(getIntersectNode(sln.head1, sln.head2)->value);

	// 0->9->8->6->4->5->6->->
	sln.head2 = new Node(0);
	sln.head2->next = new Node(9);
	sln.head2->next->next = new Node(8);
	sln.head2->next->next->next = sln.head1->next->next->next->next->next; // 8->6
	//System->out->println(getIntersectNode(sln.head1, sln.head2)->value);
	return 0;
}
