#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
��Ŀ��������������w��v���������鳤����ȣ�w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ��
		�ٸ���һ������bag��Ҫ������ѡ��Ʒ������������һ�����ܳ���bag������������������£����ܻ�õ�����ֵ��
˼·��
		(1) �������ݹ�汾
			i). �۶��߽缰����
				a). ��ѡ��Ʒ������������һ�����ܳ���bag
			ii). ��ͨ���������ѡ�Ͳ�ѡ�������
				a). ѡ��
				b). ��ѡ��
		(2) ���ݹ�汾�Ľ�Ϊ��̬�滮�汾
			i). �����ɱ����(��ռ�)
				a). ��ά��
				b). �ɱ������i��alreadyWeight
			ii). ȷ������״̬
				a). (0, 0)
			iii). ����base caseȷ����ʼ
				a). ��i == values.size()ʱ������0
			IV). ������ͨλ��������
				a). i����i+1
				b). alreadyWeight����alreadyWeight + weights[i]
*/

class Knapsack
{
public:
	int maxValue(vector<int> values, vector<int> weights, int bag);

	//�ݹ�汾
	//������values: ��ֵ���飬 weights����������
	//bag�������������� alreadyWeight�� ����ѡ������
	//����ֵ������ֵ
	int Process(vector<int> values, vector<int> weights, int bag, int i, int alreadyWeight);

	int DP(vector<int> values, vector<int> weights, int bag);
};

int Knapsack::DP(vector<int> values, vector<int> weights, int bag)
{
	vector<vector<int>> dp(values.size() + 1, vector<int>(weights.size() + 1, 0));

	for (int i = values.size() - 1; i >= 0; i--)
	{
		for (int j = bag; j >= 0; j--)
		{
			dp[i][j] = dp[i + 1][j];
			if (j + weights[i] < bag)
				dp[i][j] = max(dp[i][j], values[i] + dp[i + 1][j + weights[i]]);
		}
	}

	return dp[0][0];
}


int Knapsack::maxValue(vector<int> values, vector<int> weights, int bag)
{
	return Process(values, weights, bag, 0, 0);
}

int Knapsack::Process(vector<int> values, vector<int> weights, int bag, int i, int alreadyWeight)
{
	//����bag������ֱ�ӷ���ϵͳ��Сֵ
	if (alreadyWeight > bag)
		return INT_MIN;

	//����bag�Ĳ��֣�ֱ�ӷ���0���ɵݹ鷽���ۼ��Ͻ�βǰ�Ĳ���
	if (i == weights.size())
		return 0;

	return max(
		Process(values, weights, bag, i + 1, alreadyWeight),
		values[i] + Process(values, weights, bag, i + 1, alreadyWeight + weights[i])
	);
}

int main()
{
	vector<int> values = { 3, 2, 4, 7 };
	vector<int> weights= { 5, 6, 3, 19 };
	int bag = 11;

	Knapsack sln;
	cout << sln.maxValue(values, weights, bag);
	cout << sln.DP(values, weights, bag);

	return 0;
}