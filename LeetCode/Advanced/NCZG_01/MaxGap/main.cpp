#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/*
���������������ֵ����Ҫ��ʱ�临�Ӷ�O(N)����Ҫ�����û��ڱȽϵ�����
˼·��ʹ������Ͱ�����˼�룬����N��������N+1��Ͱ��Ϊ������Ȼ�����Сֵ���ڿ�ͷ�����ֵ���ڽ�β��
�ɴ˿ɵ��м���п�Ͱ���д˿�֤��Ͱ�ڵ��������ض�С�ڷ���Ͱ�ڵ�������
Ȼ�����ΰ���Ͱ�����ķ�Χ����Ԫ�أ�����ֵ�Ƚ�
*/
class Solution
{
public:
	int maxGap(vector<int> vec);
private:
	int bucket(int num, int min, int max, int len);
};

int Solution::maxGap(vector<int> vec)
{
	if (vec.size() < 2)
		return -1;
	int len = vec.size();
	int mins = INT_MAX;
	int maxs = INT_MIN;
	for (int i = 0; i < len; i++)
	{
		mins = min(mins, vec[i]);
		maxs = max(maxs, vec[i]);
	}
	if (mins == maxs)
	{
		return 0; //����Ԫ�ض���ͬ
	}

	vector<bool> hasNum(len + 1);
	vector<int> maxsNum(len + 1);
	vector<int> minsNum(len + 1);
	for (int i = 0; i < len ; i++)
	{
		int bid = bucket(vec[i], mins, maxs, len);
		maxsNum[bid] = hasNum[bid] ? max(maxsNum[bid], vec[i]) : vec[i];
		minsNum[bid] = hasNum[bid] ? min(minsNum[bid], vec[i]) : vec[i];
		hasNum[bid] = true;
	}
	int res = 0;
	int beforeMax = maxsNum[0];
	for (int i = 1; i <= len; i++)
	{
		if (hasNum[i])
		{
			int nextMin = minsNum[i];
			res = max(res, nextMin - beforeMax);
			beforeMax = maxsNum[i];
		}
	}

	return res;
}

int Solution::bucket(int num, int min, int max, int len)
{
	return ((num - min) * len / (max - min));
}

int main()
{
	vector<int> vec = { 9, 0, 8, 3, 13, 6, 1, 5, 2, 7, 4 };
	Solution sln;
	int res = sln.maxGap(vec);
	return -1;
}