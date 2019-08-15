#include <iostream>
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

class SuccessorNode
{
public:
	Node* getSuccessorNode(Node* node);
	Node* getLeftMost(Node* node);
};

Node* SuccessorNode::getSuccessorNode(Node* node)
{
	if (node == nullptr)
		return nullptr;

	if (node->right != nullptr)
		return getLeftMost(node->right);
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

Node* SuccessorNode::getLeftMost(Node* node)
{
	if (node == nullptr)
		return nullptr;
	
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}

int main()
{
	Node* head = new Node(6);
	head->parent = nullptr;
	head->left = new Node(3);
	head->left->parent = head;
	head->left->left = new Node(1);
	head->left->left->parent = head->left;
	head->left->left->right = new Node(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new Node(4);
	head->left->right->parent = head->left;
	head->left->right->right = new Node(5);
	head->left->right->right->parent = head->left->right;
	head->right = new Node(9);
	head->right->parent = head;
	head->right->left = new Node(8);
	head->right->left->parent = head->right;
	head->right->left->left = new Node(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new Node(10);
	head->right->right->parent = head->right;

	SuccessorNode sn;

	Node* test = head->left->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->left->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->left->right->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->left->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->left;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right;
	cout << test-> value << " next: " << sn.getSuccessorNode(test)->value;
	test = head->right->right; // 10's next is null
	//cout << test->value << " next: " << sn.getSuccessorNode(test)->value;
	//System->out->println(test->value + " next: " + sn.getSuccessorNode(test));

	return -1;
}