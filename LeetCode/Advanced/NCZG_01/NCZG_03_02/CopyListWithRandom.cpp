#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	int var;
	Node* next;
	Node* random;
	Node() :var(0), next(nullptr), random(nullptr){}
	Node(int var) :var(var), next(nullptr), random(nullptr) {}
	Node(const Node& node) : var(node.var), next(node.next), random(node.random) {}
};

class CopyListWithRandom
{
public:
	Node* head;

	Node* CopyList1();
	Node* CopyList2();
};

/*
	˼·��ͨ��stl������hash_table��Ϊ�ײ�ʵ�ֵĹ�����������unordered_map<Key, Valule>������Դ�ڵ��뿽���ڵ��ֵ�ԵĹ�ϵӳ��
		A). ͨ��ѭ������ԭ�����unordered_map��ֵ��key��ԭnode�� value���������node
		B). Ȼ��ͨ��unordered_map�ġ�Key��ȡ����Ӧ��value��������������
		C). ����ѭ����������(��pHead == nullptr����ѭ��)��
			a). copyListMap[pHead]->next = copyListMap[pHead->next];
			b). copyListMap[pHead]->parent = copyListMap[pHead->parent];
			c)	pHead = pHead->next;

1). ����1
	while (pHead != nullptr)
	{
		copyListMap[pHead] = &Node(*pHead);
		pHead = pHead->next;
	}
	֮�󣬣�����Ӧ����copyListMap�е����п����ڵ��ֵÿ�ζ��ᱻ�޸�Ϊ���µģ�������ÿ��&Node(*pHead)����ȡ�ĵ�ַ���µ�
2). ����2
	ʹ�ÿ������캯���������������µĽڵ�
*/
Node* CopyListWithRandom::CopyList1()
{
	unordered_map<Node*, Node*> copyListMap;
	Node* pHead = head;
	while (pHead != nullptr)
	{
		//copyListMap[pHead] = &Node(*pHead); wrong

		/*int value = pHead->var;
		Node* copyNode = new Node(value);
		copyListMap[pHead] = copyNode;   right but to long*/

		copyListMap[pHead] = new Node(/**pHead*/pHead->var); //simple
		pHead = pHead->next;
	}

	pHead = head;
	pHead->next = nullptr;
	while (pHead != nullptr)
	{
		//pHead->next
		copyListMap[pHead]->next = copyListMap[pHead->next];
		copyListMap[pHead]->random = copyListMap[pHead->random];
		pHead = pHead->next;
	}

	return copyListMap[head];
}

/*
	˼·������1����ʹ����ռ临�Ӷ�ΪO(N)�����������Ǻܼ򵥵Ľṹ����˿��Բ�ͨ��������ϣmap�������
		A). ԭ����1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> nullptr
		B). ����Ϊ��1 -> 1' -> 2 -> 2' -> 3 -> 3' ...... 8 -> 8' -> nullptr
		C). ��ʱ����֪��ÿ��ԭ�ڵ��next���ǿ����ڵ�
		D). ���⼴�ɽ�����Ҵ�ʱ�Ķ���ռ临�Ӷ�ΪO(1)
*/
Node* CopyListWithRandom::CopyList2()
{
	Node* pHead = head;
	
	//B)���� ��������
	while (pHead != nullptr)
	{
		Node* temp = pHead->next;
		pHead->next = new Node(pHead->var);
		pHead->next->next = temp;
		pHead = temp;
	}

	pHead = head;
	Node* curCopy;
	while (pHead != nullptr)
	{
		Node* temp = pHead->next->next;
		curCopy = pHead->next;
		curCopy->random = pHead->random != nullptr ? pHead->random->next : nullptr;
		pHead = temp;
		/*
		Node* temp = pHead->next; //�����ڵ�
		if(temp->random != nullptr)
			temp->random = temp->random->next; //����random����
		pHead = temp->next;
		*/
	}

	pHead = head;
	Node* res = head->next;
	while (pHead != nullptr)
	{
		Node* temp = pHead->next->next != nullptr ? pHead->next->next : nullptr;
		curCopy = pHead->next;
		pHead->next = temp;
		curCopy->next = temp != nullptr ? temp->next : nullptr;
		pHead = temp;
		//temp = pHead->next;
		//pHead->next = temp->next;
		//temp->next = pHead->next->next;
		//pHead = pHead->next;
	}

	return res;
}

/*
int main()
{
	CopyListWithRandom sln;

	sln.head = new Node(1);
	sln.head->next = new Node(2);
	sln.head->next->next = new Node(3);
	sln.head->next->next->next = new Node(4);
	sln.head->next->next->next->next = new Node(5);
	sln.head->next->next->next->next->next = new Node(6);

	sln.head->random = sln.head->next->next->next->next->next; // 1 -> 6
	sln.head->next->random = sln.head->next->next->next->next->next; // 2 -> 6
	sln.head->next->next->random = sln.head->next->next->next->next; // 3 -> 5
	sln.head->next->next->next->random = sln.head->next->next; // 4 -> 3
	sln.head->next->next->next->next->random = nullptr; // 5 -> nullptr
	sln.head->next->next->next->next->next->random = sln.head->next->next->next; // 6 -> 4


	Node* res1 = sln.CopyList1();
	Node* res2 = sln.CopyList2();
	return 0;
}
*/