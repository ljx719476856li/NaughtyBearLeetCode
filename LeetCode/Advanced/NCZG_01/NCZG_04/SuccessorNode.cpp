#include <iostream>
//#include "PrintBinaryTree.hpp"
using namespace std;

/*
��Ŀ��
1. �ڶ���������������������У�node����һ���ڵ����node�ĺ�̽ڵ㡣�ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ�
2. �ڶ���������������������У�node����һ���ڵ����node�ĺ�̽ڵ㡣�ڶ��������ҵ�һ���ڵ��ǰ�̽ڵ�

˼·��
��1��Ѱ��һ���ڵ��ڶ���������������еĺ�̽ڵ㣬��Ϊ�������(��������ص㣺�� �� ��)
	1). ��ǰ�ڵ���������ʱ����̽ڵ�һ�����ǵ�ǰ�ڵ����������������Ҷ
	2). ��ǰ�ڵ�û��������ʱ��ͨ��parent�ڵ�����һ�ƶ�curNode��curNode��parent����parent�ڵ����ڵ���curNodeʱ��parent��Ϊ��ǰ�ڵ�ĺ�̽ڵ�(�˴���curNode��һ���ǵ�ǰ�ڵ�)
		i). curNode = parent;  parent = curNode.parent; ����> ͨ��parent�ڵ�����һ�ƶ�curNode��curNode��parent
		ii). ע��߽磬parent != nullptr��

��2��Ѱ��һ���ڵ��ڶ���������������е�ǰ�̽ڵ㣬��Ϊ�������(��������ص㣺�� �� ��)
	1). ��ǰ�ڵ���������ʱ��ǰ�̽ڵ�һ�����ǵ�ǰ�ڵ����������������Ҷ
	2). ��ǰ�ڵ�û��������ʱ��ͨ��parent�ڵ�����һ�ƶ�curNode��curNode��parent����parent�ڵ���ҽڵ���curNodeʱ��parent��Ϊ��ǰ�ڵ��ǰ�̽ڵ�
*/

struct Node
{
public:
	int value;
	Node* parent;
	Node* left;
	Node* right;
	Node() :value(-1), parent(nullptr), right(nullptr), left(nullptr) {}
	Node(int data) :value(data), parent(nullptr), right(nullptr), left(nullptr) {}
};

class BeforeNode
{
public:
	//���node��ǰ�̽ڵ�
	Node* GetBeforeNode(Node* node);
private:
	//���node��������Ҷ
	Node* GetRightMost(Node* node);
};
class SuccessorNode
{
public:
	//���node�ĺ�̽ڵ�
	Node* GetSuccessorNode(Node* node);
private:
	//���node��������Ҷ
	Node* GetLeftMost(Node* node);
}; 


Node* BeforeNode::GetBeforeNode(Node* node)
{
	if (node == nullptr)
		return nullptr;

	Node* parent = node->parent;
	if (node->left != nullptr)
		return GetRightMost(node->left);
	else
	{

		while (parent != nullptr && node != parent->right)
		{
			node = parent;
			parent = node->parent;
		}
	}
	return parent;
}

Node* BeforeNode::GetRightMost(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (node->right != nullptr)
		node = node->right;

	return node;
}

Node* SuccessorNode::GetSuccessorNode(Node* node)
{
	if (node == nullptr)
		return nullptr;

	if (node->right != nullptr)
		return GetLeftMost(node->right);
	else
	{
		Node* parent = node->parent;
		if (parent->left == node)
			return parent;
		else
		{
			while (parent != nullptr && parent->left != node)
			{
				node = parent;
				parent = node->parent;
			}
			return parent;
		}
		
	}

}

Node* SuccessorNode::GetLeftMost(Node* node)
{
	if (node == nullptr)
		return nullptr;
	
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}

/*������
int main()
{
	Nodee* head1 = new Nodee(1);
	head1->left = new Nodee(2);
	head1->left->left = new Nodee(3);
	head1->left->left->right = new Nodee(4);
	head1->left->right = new Nodee(5);
	head1->left->right->right = new Nodee(6);
	head1->right = new Nodee(7);
	head1->right->left = new Nodee(8);
	head1->right->left->left = new Nodee(9);
	head1->right->right = new Nodee(10);
	PrintBinaryTree pbt;
	pbt.printTree(head1);


	Node* head = new Node(1);
	head->parent = nullptr;
	head->left = new Node(2);
	head->left->parent = head;
	head->left->left = new Node(3);
	head->left->left->parent = head->left;
	head->left->left->right = new Node(4);
	head->left->left->right->parent = head->left->left;
	head->left->right = new Node(5);
	head->left->right->parent = head->left;
	head->left->right->right = new Node(6);
	head->left->right->right->parent = head->left->right;
	head->right = new Node(7);
	head->right->parent = head;
	head->right->left = new Node(8);
	head->right->left->parent = head->right;
	head->right->left->left = new Node(9);
	head->right->left->left->parent = head->right->left;
	head->right->right = new Node(10);
	head->right->right->parent = head->right;


	SuccessorNode sn;

	Node* test = head->left->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left->left->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left->right->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right->left->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right->right; // 10's next is null
	cout << test->value << " next: " << (sn.GetSuccessorNode(test) != nullptr ? sn.GetSuccessorNode(test)->value : 0) << endl;
	

	BeforeNode bn;
	test = head->left->left;
	cout << test-> value << " before: " << ( bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0)<< endl;
	test = head->left->left->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->left;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->left->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->left->right->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right->left->left;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right->left;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right->right; // 10's before is null
	cout << test->value << " before: " << (bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0) << endl;
	//System->out->println(test->value + " next: " + sn.GetSuccessorNode(test));

	return -1;
}
*/ 

/*
//for test
void test()
{
	Nodee* head1 = new Nodee(1);
	head1->left = new Nodee(2);
	head1->left->left = new Nodee(4);
	head1->left->right = new Nodee(5);
	head1->right = new Nodee(3);
	head1->right->left = new Nodee(6);
	head1->right->right = new Nodee(7);
	PrintBinaryTree pbt;
	pbt.printTree(head1);


	Node* head = new Node(1);

	head->left = new Node(2);
	head->left->parent = head;
	head->left->left = new Node(4);
	head->left->left->parent = head->left;
	head->left->right = new Node(5);
	head->left->right->parent = head->left;
	head->right = new Node(3);
	head->right->parent = head;
	head->right->left = new Node(6);
	head->right->left->parent = head->right;
	head->right->right = new Node(7);
	head->right->right->parent = head->right;
	//PrintBinaryTree pbt;

	//head->parent = nullptr;
	//head->left = new Node(2);
	//head->left->parent = head;
	//head->left->left = new Node(3);
	//head->left->left->parent = head->left;
	//head->left->left->right = new Node(4);
	//head->left->left->right->parent = head->left->left;
	//head->left->right = new Node(5);
	//head->left->right->parent = head->left;
	//head->left->right->right = new Node(6);
	//head->left->right->right->parent = head->left->right;
	//head->right = new Node(7);
	//head->right->parent = head;
	//head->right->left = new Node(8);
	//head->right->left->parent = head->right;
	//head->right->left->left = new Node(9);
	//head->right->left->left->parent = head->right->left;
	//head->right->right = new Node(10);
	//head->right->right->parent = head->right;


	SuccessorNode sn;
	BeforeNode bn;
	Node* test = head->right;
	cout << test->value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	cout << test->value << " before: " << bn.GetBeforeNode(test)->value << endl;

	//Node* test = head->left->left;
	/*Node* test = head;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test->left)->value << endl;
	test = head->left->left->right;
	cout << test-> value << " next: " << (sn.GetSuccessorNode(test) != nullptr ? sn.GetSuccessorNode(test)->value : 0) << endl;
	test = head->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->left->right->right;
	cout << test-> value << " next: " << (sn.GetSuccessorNode(test) != nullptr ? sn.GetSuccessorNode(test)->value : 0) << endl;
	test = head;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right->left->left;
	cout << test-> value << " next: " << (sn.GetSuccessorNode(test) != nullptr ? sn.GetSuccessorNode(test)->value : 0) << endl;
	test = head->right->left;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right;
	cout << test-> value << " next: " << sn.GetSuccessorNode(test)->value << endl;
	test = head->right->right; // 10's next is null
	cout << test->value << " next: " << (sn.GetSuccessorNode(test) != nullptr ? sn.GetSuccessorNode(test)->value : 0) << endl;


	BeforeNode bn;
	test = head;
	cout << test-> value << " before: " << ( bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0)<< endl;
	test = head->left->left->right;
	cout << test-> value << " before: " << (bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0) << endl;
	test = head->left;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->left->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->left->right->right;
	cout << test-> value << " before: " << (bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0) << endl;
	test = head;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right->left->left;
	cout << test-> value << " before: " << (bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0) << endl;
	test = head->right->left;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right;
	cout << test-> value << " before: " << bn.GetBeforeNode(test)->value << endl;
	test = head->right->right; // 10's before is null
	cout << test->value << " before: " << (bn.GetBeforeNode(test) != nullptr ? bn.GetBeforeNode(test)->value : 0) << endl;
	//System->out->println(test->value + " next: " + sn.GetSuccessorNode(test));

	return;
}
*/