#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
��Ŀ���������ά���飬��λ�����е�ÿ��������������Ҫ������Ͻ��ߵ����½ǣ�ÿһ��ֻ�����һ������¡���;����������Ҫ�ۼ�������������С��·����
˼·��
		(1) �ݹ�˼�봦����������x��������y
		(2) �ݹ���ڣ��߽����
			i) �Ѿ��������½ǣ�ֱ�ӷ������½�ֵ
			ii) x��y������߽�
				a) x == matrix.length - 1 ʱ��x���������󣬼���ʱֻ������
				b) y == matrix[0].length - 1ʱ��y���������󣬼���ʱֻ������
		(3) ������ͨ��������min(���� ��)

*/
class MinPath
{
public:
	//�ݹ鴦��
	//������matrix: ���� x: �У� y: ��
	//������С·��
	int Process(vector<vector<int>> matrix, int x, int y); 

	//����������
	int MemoryProcess(vector<vector<int>> matrix, int x, int y);
	unordered_map<string, int> m_haspMap;

	//DP
	int DPProcess(vector<vector<int>> matrix);
};



//����������
int MinPath::MemoryProcess(vector<vector<int>> matrix, int x, int y)
{
	//�ݹ���� && �߽�۶�
	if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
		return matrix[x][y]; //ֱ�ӷ������½�ֵ
	if (x == matrix.size() - 1)  //x�Ѿ�����߽粻�������󣬼���ʱֻ������
	{
		string key = to_string(x) + '-' + to_string(y + 1);
		if (m_haspMap.find(key) == m_haspMap.end())
			m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, x, y + 1);

		return m_haspMap[key];
	}//return matrix[matrix.size() - 1][++y]; //�����ƶ�
	if (y == matrix[0].size() - 1) //x�Ѿ�����߽粻�������󣬼���ʱֻ������
	{
		string key = to_string(x + 1) + '-' + to_string(y);
		if (m_haspMap.find(key) == m_haspMap.end())
			m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, x + 1, y);

		return m_haspMap[key];
		//return matrix[++x][matrix[0].size() - 1]; //�����ƶ�
	}
	int row = x, column = y;
	row += matrix[x + 1][y] == min(matrix[x + 1][y], matrix[x][y + 1]) ? 1 : 0;
	column += x == row ? 1 : 0;
	
	string key = to_string(x) + '-' + to_string(y);
	m_haspMap[key] = matrix[x][y] + MemoryProcess(matrix, row, column);

	return m_haspMap[key];
}

//DP
int MinPath::DPProcess(vector<vector<int>> matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col));

	dp[0][0] = matrix[0][0];
	for (int i = 1; i < row; i++)
		dp[i][0] = dp[i - 1][0] + matrix[i][0];
	for (int j = 1; j < col; j++)
		dp[0][j] = dp[0][j - 1] + matrix[0][j];
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
	}
	return dp[row - 1][col - 1];
}

//�ݹ鴦��
//������matrix: ���� x: �У� y: ��
//������С·��
int MinPath::Process(vector<vector<int>> matrix, int x, int y)
{
	//�ݹ���� && �߽�۶�
	if (x == matrix.size() - 1 && y == matrix[0].size() - 1)
		return matrix[x][y]; //ֱ�ӷ������½�ֵ
	if (x == matrix.size() - 1)  //x�Ѿ�����߽粻�������󣬼���ʱֻ������
		return matrix[x][y] + Process(matrix, x, y + 1);
	//return matrix[matrix.size() - 1][++y]; //�����ƶ�
	if (y == matrix[0].size() - 1) //x�Ѿ�����߽粻�������󣬼���ʱֻ������
		return matrix[x][y] + Process(matrix, x + 1, y);
	//return matrix[++x][matrix[0].size() - 1]; //�����ƶ�

	int row = x, column = y;
	row += matrix[x + 1][y] == min(matrix[x + 1][y], matrix[x][y + 1]) ? 1 : 0;
	column += x == row ? 1 : 0;

	return matrix[x][y] + Process(matrix, row, column);

}

/*
int main()
{
	vector<vector<int>> matrix = { {3, 2, 1, 0}, {7, 5, 0, 1}, {3, 7, 6, 2} };

	MinPath sln;
	//int res = sln.Process(matrix, 0, 0);
	//int res = sln.MemoryProcess(matrix, 0, 0);
	int res = sln.DPProcess(matrix);
	return 0;
}
*/

