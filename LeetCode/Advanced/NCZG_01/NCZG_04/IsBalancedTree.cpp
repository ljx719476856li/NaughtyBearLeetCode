#include <iostream>
#include <algorithm>
using namespace std;

/*
��Ŀ���ж�һ�ö������Ƿ���ƽ�������(ʲô��ƽ�������  ����������������κ�һ���ڵ� �������������������ĸ߶Ȳ� ������1 �����ƽ�������)
˼·���ж�һ�����Ƿ���ƽ�����������򵥵���������:
		(1) ���ǵݹ麯���ܺ��ã���Ϊ�ݹ麯����ص�һ���ڵ�����
			i). ����ͷ�ڵ�x ����һ�λ�����x����ȥx�����������ص�x����ȥx�����������ֻص�x��һ������
			ii). ��Ȼ���ռ��ڵ���Ϣ���Σ��Ϳ������ռ�����������Ϣ�����ռ�����������Ϣ��Ȼ�������жϷ���ƽ���������������
				a). �ж��������Ƿ���ƽ���
				b). �ж��������Ƿ���ƽ���
				c). �ж����������������ĸ߶��Ƿ� <= 1
			iii). �����ÿһ���ڵ���Ϊ����ͷ�ڵ㶼��������a), b), c)���������򶼾���ƽ���ԣ���ô�������ƽ�������
		(2). �ݹ���ʽ ��> ��ƽṹ ��> ��������ֵ�趨(����ֵ��Ҫ�����������Ƿ���ƽ������������ĸ߶�)
*/

struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data) :value(data), left(nullptr), right(nullptr) {}
};
struct ReturnTreeData
{
	bool isBlanced; //�����Ƿ�ƽ��
	int treeHeight; //�����ĸ߶�

	ReturnTreeData(bool isB, int h) : isBlanced(isB), treeHeight(h) {}
};

class IsBalancedTree
{
private:
	//�ж�ƽ�����������Ϣ����ݹ�
	//parameter����������ͷ�ڵ�
	//return�����ص�������/���Ŷ���������Ϣ��������Ϣ���ṹ��ReturnTreeData
	ReturnTreeData* Process(Node* node);
public:
	//�ж��Ƿ���ƽ�������
	//parameter����Ҫ�ж�����ͷ�ڵ�
	//return��true ��ʾ��ƽ�����������֮��Ȼ
	bool IsBalanceTree(Node* node);
};

bool IsBalancedTree::IsBalanceTree(Node* node)
{
	return Process(node)->isBlanced;
}

ReturnTreeData* IsBalancedTree::Process(Node* node)
{
	if (node == nullptr)
		return new ReturnTreeData(true, 0); //����Ҳ��ƽ��ģ��ݹ����

	ReturnTreeData* left = Process(node->left);
	if (!left->isBlanced)
		return new ReturnTreeData(false, 0);

	ReturnTreeData* right = Process(node->right);
	if (!right->isBlanced)
		return new ReturnTreeData(false, 0);

	if (abs(left->treeHeight - right->treeHeight) > 1)
		return new ReturnTreeData(false, 0);

	return new ReturnTreeData(true, max(left->treeHeight, right->treeHeight) + 1);
}

int main()
{
	Node* node = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(4);
	node->left->right = new Node(5);
	node->right->left = new Node(6);
	node->right->right = new Node(7);
	node->right->right->left = new Node(8);
	node->right->right->right = new Node(2);
	node->right->right->right->left = new Node(2);


	IsBalancedTree sln;
	bool isB = sln.IsBalanceTree(node);
	cout << (isB ? "Is Balanced Tree" : "Is Not Balanced Tree");

	return 0;
}