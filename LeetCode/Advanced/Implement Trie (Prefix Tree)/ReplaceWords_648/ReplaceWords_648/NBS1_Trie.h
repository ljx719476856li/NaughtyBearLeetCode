//*************************************
//ʱ�䣺2019/7/23
//���ƣ�648. �����滻
//˼·:
/*
������������һ��ǰ׺�ֵ䣬�ָ���һ�����ӣ������ǽ������нϳ��ĵ��ʻ�����ǰ׺(�����ǰ׺�ֵ��д��ڵĻ�)��
���Ƕ��ھ����е�һ�������������ǰ׺�أ��ǲ��ǿ��Ը��ݵ�һ����ĸ�����ٶ�λ�أ�����cattle������ʵ�����ĸ��c����ô������ǰ׺�ֵ��������п�ͷ��c��ǰ׺
*/
//*************************************

#pragma once
#include <iostream>
#include <sstream>
#include<algorithm>
#include <vector>

using namespace std;

class  Solution
{
public:
	string replaceWords(vector<string>& dict, string sentence)
	{
		//��Ž��
		string res = "";
		string sTmp = "";
		//���ڴ��ǰ׺���ʵ�����
		vector<vector<string>> vecDic(26);

		//����C++��û��split�������������ǲ����ַ���������ȡÿһ������
		istringstream is(sentence);

		//��Ŀ��Ҫ������̵�ǰ׺���滻���ʣ�����ͨ��sort���򽫶�ǰ׺���ڳ�ǰ׺��ǰ��
		sort(dict.begin(), dict.end(), [](string& a, string& b) { return a.size() < b.size(); });
		for (string word: dict)
			vecDic[word[0] - 'a'].push_back(word);

		//�����ַ���������ȡÿһ������
		while (is >> sTmp)
		{
			for (string word: vecDic[sTmp[0] - 'a'])
			{
				if (sTmp.substr(0, word.size()) == word)
				{
					sTmp = word;
					break;
				}
			}
			res += sTmp + " ";
		}

		//ȥ�����һ��" "
		res.pop_back();
		return res;
	}
};
