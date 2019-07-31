#pragma once
#include <iostream>
#include <vector>
/*
��������������������������������һ����С��Ԫ�ظ����������ĺ��档�����飺�Ƚϵö࣬�����١�
ѡ������˼·��
1. ��δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
2. ��ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
3. �Դ����ƣ�ֱ������Ԫ�ؾ��������
4. �ӵ�һ��λ�ÿ�ʼ�Ƚϣ��ҳ���С�ģ��͵�һ��λ�û�������ʼ��һ�֡�
*/
class Selection
{
public:
	// ѡ������
	void SelectionSort(std::vector<int>& v);

	// ģ��ʵ��
	template<typename T>
	void Selection_Sort(std::vector<T>& arr);
};

template<typename T>
void Selection::Selection_Sort(std::vector<T>& arr) 
{
	int min, len = arr.size();
	for (int i = 0; i < len - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (i != min)
			std::swap(arr[i], arr[min]);
	}
	return;
}

void Selection::SelectionSort(std::vector<int>& vec)
{
	int min, len = vec.size() - 1;
	for (int i = 0; i < len; i ++)
	{
		min = i;
		for (int j = i + 1; j <= len; j++)
		{
			if (vec[min] > vec[j])
				min = j;
		}
		if (i != min)
			std::swap(vec[i], vec[min]);
	}

	return;
}