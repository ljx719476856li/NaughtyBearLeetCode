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
	Nodee* ReconByPreString(string str);

	Nodee* ReconPreOrder(queue<string> preQueue);


	string serialByPre(Nodee* head);
	Nodee* reconByPreString(string preStr);
	Nodee* reconPreOrder(queue<string> queue);

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

Nodee* SerializeAndReconsturctTrees::ReconByPreString(string preStr)
{
	vector<string> values;
	SplitString(preStr, values, "_");
	queue<string> queueStr;
	for (int i = 0; i <values.size(); i++)
		queueStr.push(values[i]);

	return ReconPreOrder(queueStr);
}

Nodee* SerializeAndReconsturctTrees::ReconPreOrder(queue<string> preQueue)
{
	string value = preQueue.front();
	preQueue.pop();
	//����ȡ��#ʱ����ɷ�����
	if (value._Equal("#"))
	{
		return nullptr;
	}

	
	Nodee* head = new Nodee(atoi(value.c_str()));
	//Nodee* head = new Nodee(static_cast<int>(strtol(value.c_str(), &end, 16)););
	head->left = ReconPreOrder(preQueue);
	head->right = ReconPreOrder(preQueue);

	return head;
}

string SerializeAndReconsturctTrees::serialByPre(Nodee* head) {
	if (head == nullptr) {
		return "#!";
	}
	string res = to_string(head->value) + "!";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}

Nodee* SerializeAndReconsturctTrees::reconByPreString(string preStr) {
	vector<string> values;
	SplitString(preStr, values, "!");
	queue<string> queue;
	for (int i = 0; i != values.size(); i++) {
		queue.push(values[i]);
	}
	return reconPreOrder(queue);
}

Nodee* SerializeAndReconsturctTrees::reconPreOrder(queue<string> queue) {
	string value = queue.front();
	queue.pop();
	if (value._Equal("#")) {
		return nullptr;
	}
	Nodee* head = new Nodee(atoi(value.c_str()));
	head->left = reconPreOrder(queue);
	head->right = reconPreOrder(queue);
	return head;
}

/*
int main()
{
	PrintBinaryTree pbt;

	Nodee* head;
	head = new Nodee(100);
	head->left = new Nodee(21);
	head->left->left = new Nodee(37);
	head->right = new Nodee(-42);
	head->right->left = new Nodee(0);
	head->right->right = new Nodee(666);
	pbt.printTree(head);

	SerializeAndReconsturctTrees sart;
	string res = sart.serialByPre(head);
	cout << res << endl;
	Nodee* head2 = sart.reconByPreString(res);
	pbt.printTree(head2);

	return 0;
}
*/
