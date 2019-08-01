#pragma once
#include <iostream>

// �����򣺣����ѣ������������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ��ѡ�
class HeapSort
{
public:
	void max_heapify(int arr[], int start, int end);
	void heap_sort(int arr[], int len);
};


void HeapSort::max_heapify(int arr[], int start, int end)
{
	//���������cָ�˺��ӹ��cָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //���ӹ��cָ���ڹ����Ȳ������^
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱ��^�ɂ��ӹ��c��С���x������
			son++;
		if (arr[dad] > arr[son]) //��������c����ӹ��c�����{���ꮅ��ֱ����������
			return;
		else { //��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
			std::swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void HeapSort::heap_sort(int arr[], int len)
{
	//��ʼ����i������һ�������c�_ʼ�{��
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//�Ȍ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�����Q���ُ����{��(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ�������ꮅ
	for (int i = len - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}