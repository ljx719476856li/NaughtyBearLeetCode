#include <iostream>
#include <stack>
using namespace std;

/*
ʵ��һ���������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ�е���СԪ�صĲ���
*/

class MinStack
{
public:
	void Push(int num);
	int Pop();
	int Peek();
	int GetMin();

private:
	stack<int> statckMin;
	stack<int> statckData;
	
};

void MinStack::Push(int num)
{
	if (statckMin.empty()) //statckMin��ջ����1��stackMinջ����Ϊ0
		statckMin.push(num);
	else if (num <= GetMin())//statckMin��ջ����2����ǰ��ջԪ��С��stackMin����Ԫ��
		statckMin.push(num);

	statckData.push(num); //num�ض���ջstackData
}
int MinStack::Pop()
{
	if (statckData.empty())
		return -1;
	int var = statckData.top();
	statckData.pop();

	//������������ջԪ�� == stackMinջ������ʱ�����stackMin��Ҳ��ջ
	if (var == GetMin())
		statckMin.pop();

	return var;
}
int MinStack::Peek()
{
	if (statckData.empty())
		return -1;
	int var = statckData.top();

	return var;
}

int MinStack::GetMin()
{
	if (statckMin.empty())
		return -1;

	return statckMin.top();
}

int main()
{
	MinStack stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(0);
	int var = stack.Pop();
	int num = stack.GetMin();

	return -1;
}