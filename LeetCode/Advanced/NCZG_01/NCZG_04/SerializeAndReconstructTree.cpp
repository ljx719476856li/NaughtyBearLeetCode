#include <queue>
#include "PrintBinaryTree.hpp"

/*
��Ŀ�������������л��뷴���л�
˼·��ʹ��ǰ�����򣬺��򣬲���ȱ����������ķ��������л�������Ϊ�ַ�����Ϊ��¼��Ȼ����ͨ����ͬ�ķ������ַ��������л�����ض�����
		1). ǰ�����
			i). ��������������������нڵ��¼���ַ�����ȥ�������սڵ�(#��ʾ�սڵ�)��_�»�����Ϊÿ���ڵ��ķָ���
			ii). �����϶��ɵ��ַ��������ǶԶ����������л����
			iii). �����л�����Ϊ�����л���������������ͬ��ǰ��ݹ���������ɻ�ԭ���ö������Ľṹ
				a). ͨ���ֽ��ַ������������Ӧ���ַ������飬����ÿһ���ڵ����Ϣ
				b). ͨ���������洢��ÿ���ڵ����Ϣ(����ѹ�뵯����˳���Ƚ��ȳ��������ع���������Ҫ��)
				c). �Ӷ�����ȡ���ڵ���Ϣ��ʹ����ǰ�����˳����ͬ�ķ�ʽ�ݹ�����

		2). ���򣬺�����������
		3). �ر�����������������
*/

struct Node : public Nodee
{
	Node(int data) : Nodee(data) {}
};

class SerializeAndReconsturctTrees
{
public:
	//�����������л�
	//parameter����Ҫ���л���������ͷ�ڵ�
	//return��string���͵��ַ���
	string SerializeByTree(Nodee* head);

	//�������л��ַ���Ϣ���ֽ⵽��Ӧ�Ķ����д洢
	//parameter�����л��ַ���
	//return�������ع��������ĸ��ڵ�
	Node* ReconByPreString(string str);

	Node* ReconPreOrder(queue<string> preQueue);

};

string SerializeAndReconsturctTrees::SerializeByTree(Nodee* head)
{
	if (head == nullptr)
		return "#_"; //�սڵ�ҲӦ��¼

	string res = to_string(head->value); //ͨ��_�»�����Ϊ�ָ���
	res.append("_");
	res += SerializeByTree(head->left);
	res += SerializeByTree(head->right);

	return res;
}

Node* SerializeAndReconsturctTrees::ReconByPreString(string preStr)
{
	vector<string> values(3);
	SplitString(preStr, values, "_");
	queue<string> queueStr;
	for (int i = 0; i <values.size(); i++)
		queueStr.push(values[i]);

	return ReconPreOrder(queueStr);
}

Node* SerializeAndReconsturctTrees::ReconPreOrder(queue<string> preQueue)
{
	string value = preQueue.front();
	preQueue.pop();
	//����ȡ��#ʱ����ɷ�����

	
	//Node* head = new Node(static_cast<int>(strtol(value.c_str(), &end, 16)););
		ReconPreOrder(preQueue)
}
int main()
{
	PrintBinaryTree pbt;

	Node* head;
	head = new Node(100);
	head->left = new Node(21);
	head->left->left = new Node(37);
	head->right = new Node(-42);
	head->right->left = new Node(0);
	head->right->right = new Node(666);
	pbt.printTree(head);

	SerializeAndReconsturctTrees sart;
	string res = sart.SerializeByTree(head);
	cout << res << endl;

	return 0;
}
