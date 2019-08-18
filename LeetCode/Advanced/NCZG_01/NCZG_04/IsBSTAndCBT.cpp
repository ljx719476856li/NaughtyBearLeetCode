#include <iostream>
#include <stack>
using namespace std;

/*
��Ŀ���ж�һ�����Ƿ�������������
˼·��
		(1) ʲô������������
			i). �κ�һ���ڵ㣬Ϊͷ�����������������ȵ�ǰ�ڵ�С����������������
		(2) ����жϣ�
			i). ��������������Ľ�� ��> ���������ʽ���� �� �� ��> �Ƿ����������������
		(3) ����(2) ������ǰ������������������(Binary Search Tree)

��Ŀ���ж�һ�����Ƿ�����ȫ������

˼·��
		(1) ʲô����ȫ������
			i). ��ȫ������Ҫô��һ�����Ķ�����(�κ�һ����Ҷ�ڵ�ĺ��Ӷ���ȫ������������������������������һ�㶼��Ҷ�ڵ�)
			ii).�����ң����β��������Ҳ����ȫ������
		(2) ʹ�ò�������ж��Ƿ�����ȫ������
			i). һ���ڵ����Һ��ӣ�����û������
			ii). ������(1)ʱ��һ���ڵ�����Һ��Ӳ�ȫ�ڣ�������ڵ㶼������Ҷ�ڵ�
		(3) ����ֻҪ����������(2)�Ķ�������Ϊ��ȫ������(Completely Binary Tree)
*/

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data):value(data), left(nullptr), right(nullptr){}
};

class IsBSTAndCBT
{
public:
	bool IsCBTree(Node* head);
	bool IsBSTree(Node* head);
};
bool IsBSTAndCBT::IsCBTree(Node* head)
{
	//����Ҳ����ȫ������
	if (head == nullptr)
		return true;

	Node* left = nullptr;
	Node* right = nullptr;




}

bool IsBSTAndCBT::IsBSTree(Node* head)
{
	if (head == nullptr)
		return false;
	stack<Node*> help;
	bool res = false;
	int temp = INT_MIN;
	while (!help.empty() || head != nullptr)
	{
		if (head != nullptr)
		{
			help.push(head);
			head = head->left;
		}
		else
		{
			head = help.top();
			temp = (temp > head->value ? temp : head->value); //������������tempӦ��С��head.value
			res = (temp == head->value ? true : false);

			help.pop();
			head = head->right;
		}
	}
	return res;
}

int main()
{
	Node* node = new Node(5);
	node->left = new Node(3);
	node->right = new Node(8);
	node->left->left = new Node(2);
	node->left->right = new Node(4);
	node->left->left->left = new Node(1);
	node->right->left = new Node(6);
	node->right->left->right = new Node(7);
	node->right->right = new Node(8);
	node->right->right->left = new Node(9);


	IsBSTAndCBT sln;
	bool res = sln.IsBSTree(node);
	cout << (res ? "BT is BST" : "BT is not BST");
	
	return 0;
}