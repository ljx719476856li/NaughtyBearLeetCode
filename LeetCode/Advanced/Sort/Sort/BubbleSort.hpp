#pragma once
#include <iostream>
#include <vector>

class Bubble
{
public:

	//ð������
	void BubbleSort(std::vector<int>& v);

	// ģ��ʵ��ð������
	template<typename T> 	//�������߸������Կ�ʹ�ã���Ҫʹ������(class)ʱ�����趨����(��)�����㹦��
	void BubbleSort1(std::vector<T>& arr, int len);


	// ð�����򣨸Ľ��棩
	void BubbleSort2(std::vector<int>& v);
};



/*
����������������������������ͨ�������ҳ����Ԫ�طŵ�������ǰ�ˡ�
ѡ������˼·��
1. �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2. ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
3. ������е�Ԫ���ظ����ϵĲ��裬�������һ����
4. ����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
*/


//ð������
void Bubble::BubbleSort(std::vector<int>& vec)
{
	int len = vec.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (vec[i] < vec[j])
				std::swap(vec[i], vec[j]);
		}
	}
	return;
}

// ģ��ʵ��ð������
template<typename T>
void Bubble::BubbleSort1(std::vector<T>& arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] < arr[j])
				std::swap(arr[i], arr[j]); 
		}
	}
	return;
}

//
//// ð�����򣨸Ľ��棩
//void Bubble::BubbleSort2(std::vector<int>& vec)
//{}
