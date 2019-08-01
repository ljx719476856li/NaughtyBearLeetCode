#pragma once
#include <iostream>
#include <vector>
/*
��С������׼Ԫ�أ����������������������ѡһ��Ԫ������׼����С�ڻ�׼��Ԫ�ط��ڻ�׼֮ǰ�����ڻ�׼��Ԫ�ط��ڻ�׼֮���ٷֱ��С�������������������
��������˼·��
1. ѡȡ��һ����Ϊ��׼
2. ���Ȼ�׼С����������ǰ�棬�Ȼ�׼���������������
3. �����������ظ��ڶ�����ֱ��������ֻ��һ����
*/

// ----------------------------------------------------
class Quick
{
public:
	// �������򣨵ݹ飩
	void QuickSort(std::vector<int>& v, int low, int high);
	void quick_sort(std::vector<int>& vec, int left, int right);
	template<typename T>
	void QuickSort2(std::vector<T>& vec, int low, int high);
private:
	//�һ�׼�� ����
	int partition(std::vector<int>& vec, int left, int right);
};


int Quick::partition(std::vector<int>& vec, int left, int right)  //�һ�׼�� ����
{
	int i = left + 1;
	int j = right;
	int temp = vec[left];

	while (i <= j)
	{
		while (vec[i] < temp)
		{
			i++;
		}
		while (vec[j] > temp)
		{
			j--;
		}
		if (i < j)
			std::swap(vec[i++], vec[j--]);
	}
	std::swap(vec[j], vec[left]);
	return j;

}

void Quick::quick_sort(std::vector<int>& vec, int left, int right)
{
	if (left > right)
		return;
	int j = partition(vec, left, right);
	quick_sort(vec, left, j - 1);
	quick_sort(vec, j + 1, right);
}


// �������򣨵ݹ飩
void Quick::QuickSort(std::vector<int>& vec, int low, int high)
{
	if (low >= high)
		return;

	int first = low, last = high, key = vec[first];
	while (first < last)
	{
		//��С�ڵ�һ����Ԫ���Ƶ���ͷ����ߣ�
		while (first < last && vec[last] >= key)
			last--;
		if (first < last)
			vec[first++] = vec[last];

		//�����ڵ�һ����Ԫ���Ƶ���β���ұߣ�
		while (first < last && vec[first] <= key)
			first++;
		if (first < last)
			vec[last--] = vec[first];
	}

	vec[first] = key;

	//������
	QuickSort(vec, low, first - 1);
	//������
	QuickSort(vec, first + 1, high);
}

//ģ��ʵ��
template<typename T>
void Quick::QuickSort2(std::vector<T>& vec, int low, int high)
{
	if (low >= high)
		return; //����λ

	int first = low, last = high, key = vec[first];
	while (first < last)
	{
		//��С�ڵ�һ����Ԫ���ƶ�����ͷ��(���)
		while (first < last && vec[last] >= key)
			last--;
		if (first < last)
			vec[first++] = vec[last];


		//�����ڵ�һ����Ԫ���ƶ�����β��(�ұ�)
		while (first < last && vec[first] <= key)
			first++;
		if (first < last)
			vec[last--] = vec[first];
	}

	vec[first] = key; 

	QuickSort2(vec, low, first - 1);
	QuickSort2(vec, first + 1, high);
}