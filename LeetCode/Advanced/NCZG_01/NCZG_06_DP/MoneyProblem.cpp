#include <iostream>
#include <vector>
using namespace std;

/*
��Ŀ������һ������arr����һ������aim�������������ѡ��arr�е����֣��ܲ����ۼӵ�aim������true����false
˼·��arr: [3, 2, 7], aim:10
			(1) չ��arr�Ľ����ѡ��ѡ
			(2) ����idx, sum
				i). idx: ��ǰ�ڵ�λ��
				ii). sum: ��ǰ�ڵ�λ��֮ǰ��ѡ�����ĺ�
			(3) �߽�۶�
				i). ��idx == arr.length�������β
				ii). ��sum == aim������true
					a). ѡ����� || ��ѡ���������Ĺ�ϵ
*/

class MoneyProblem
{
public:
	//�ݹ�汾
	//������idx����ǰ�ڵ�λ�ã�sum����ǰ�ڵ�λ��֮ǰ��ѡ�����ĺ�
	//����ֵ��true��ʾ���ۼӵ�aim����֮false
	bool Process(vector<int> nums, int sum, int idx, int aim);

	bool DP(vector<int> nums, int aim);
};

bool MoneyProblem::DP(vector<int> nums, int aim)
{
	vector<vector<bool>> dp(nums.size() + 1, vector<bool>(aim + 1, false)); //��С��ֵ
	
	for (int i = 0; i < dp.size(); i++)
		dp[i][aim] = true;
	
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		for (int j = aim - 1; j >= 0; j --)
		{
			dp[i][j] = dp[i + 1][j];
			if (j + nums[i] <= aim)
				dp[i][j] = dp[i][j] || dp[i + 1][j + nums[i]];
		}
	}

	return dp[0][0];
}

bool MoneyProblem::Process(vector<int> nums, int sum, int idx, int aim)
{
	if (nums.size() == idx)
		return aim == sum;
	

	return (Process(nums, sum, idx + 1, aim)
				||
		Process(nums, sum + nums[idx], idx + 1, aim)
		);
}

//int main()
//{
//	vector<int> nums = { 3, 2, 7 };
//	MoneyProblem sln;
//	bool flag = sln.DP(nums, 10);
//	flag = sln.Process(nums, 0, 0, 10);
//	return 0;
//}