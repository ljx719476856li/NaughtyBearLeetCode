#include <iostream>
using namespace std;

/*
��Ŀ����֪һ����ȫ������������ڵ�ĸ�����Ҫ��ʱ�临�Ӷȵ���O(N),NΪ��Ŷ������Ľڵ���
˼·��ͨ���ֱ�������������ұ߽磬�ֱ�����Ϣ���������Ĳ㼶(ͨ����������������߽���)���������Ĳ㼶(ͨ����������������߽���)
	(1) ���ȱ�����������߽磬����������߶�
		i). ��Ϊ��������ȫ��������������ȫ���������������߽磬���ɻ�ø߶�
	(2) Ȼ������������ұ߽磬ͬ������ұ߽�㼶
		i). ����ұ߽�㼶������߽�㼶����������һ������������
		ii). ����ұ߽�㼶���ܵ�����߽�㼶������������һ����������������������һ������������
	(3) ͨ�����㲻ͬ�������в�ͬ�Ĵ�����
		i). ��������i)���������������Ľڵ����Ϊ2^n - 1(nΪ�������Ĳ㼶��)��Ȼ���ٵݹ�ȥ���������Ľڵ����
		i). ��������ii)���������������Ľڵ����Ϊ2^n(nΪ�������Ľڵ����)��Ȼ����ȥ�ݹ����������Ľڵ����
	
ʱ�临�Ӷ��� log(nƽ��)
	��һ��logN�� ��Ҫ�������ٸ��ڵ�
	�ڶ���logN�� �����ı߽�
*/
struct Node
{
	int value;
	Node* left;
	Node* right;

	Node(int data): value(data), left(nullptr), right(nullptr){}
};

class CBTNodeNum
{
public:
	//��ö������Ľڵ���
	int GetNodeNum(Node* head);
private:
	//�ݹ麯��
	//parameter��head ��ǰ�ڵ㣬level ��ǰ�ڵ������������depth ��ǰ�ڵ�������������
	//return�������Ե�ǰ�ӽڵ�Ϊͷ�������Ľڵ���
	int BSProcess(Node* head, int level, int depth);
	//��������������
	//parameter��head ��ǰ�ڵ㣬level ��ǰ�ڵ���������
	//return�����ص�ǰ�ڵ�������������
	int LeftLevel(Node* head, int level);

};
int CBTNodeNum::GetNodeNum(Node* head)
{
	if (head == nullptr)
		return 0; //����Ҳ����ȫ������

	return BSProcess(head, 1, LeftLevel(head, 1));
}

int CBTNodeNum::BSProcess(Node* head, int level, int depth)
{
	//�ݹ����
	if (level == depth)
		return 1; //���㼶level �Ѿ� �ﵽ �������ʱ��֤������Ҷ�ڵ���
	

	//����������Ȳ��ܴﵽ��߽�Ĳ㼶��ȣ���������һ������������
	if (LeftLevel(head->right, level + 1) != depth)
		return (1 << depth - level - 1) + BSProcess(head->left, level + 1, depth);
	else //����������ȴﵽ��߽�Ĳ㼶��ȣ���������һ������������
		return (1 << depth - level) + BSProcess(head->right, level + 1, depth);
}

int CBTNodeNum::LeftLevel(Node* head, int level)
{
	while (head != nullptr)
	{
		level++;
		head = head->left;
	}

	return level - 1; //��������������ȣ����Լ�����ǰ�ڵ���ǲ� ��1��
}

int main()
{
	//int num = 0;
	//// << ����
	//num = 3 << 2;
	//// >> ����
	//num = num >> 2;
	Node* node2 = new Node(5);
	node2->left = new Node(3);
	node2->right = new Node(8);
	node2->left->left = new Node(2);
	node2->left->right = new Node(4);
	node2->right->left = new Node(6);
	node2->left->left->right = new Node(7);
	node2->right->right = new Node(8);
	node2->left->left->left = new Node(9);
	node2->left->right->left = new Node(10);

	CBTNodeNum sln;
	int res = sln.GetNodeNum(node2);

	cout << " �����" << res << endl;
	return 0;
}