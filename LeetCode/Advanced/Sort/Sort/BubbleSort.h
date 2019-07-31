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
	void BubbleSort1(T arr[], int len);


	// ð�����򣨸Ľ��棩
	void BubbleSort2(std::vector<int>& v);
};

