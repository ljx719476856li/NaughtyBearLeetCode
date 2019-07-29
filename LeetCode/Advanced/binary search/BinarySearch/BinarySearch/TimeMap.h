#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <numeric>
#include <map>

using namespace std;

//vector<tuple<string, string, int> > vec;
//auto iter = back_inserter(vec);
//vector<pair<string, map<string, int> > > vec;
//auto iter = back_inserter(vec);
//multimap<string, map<string, int> > mun;

class TimeMap {
public:
	TimeMap() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	}

	void set(string key, string value, int timestamp) {
		mun[key].insert(map<int, string>::value_type(timestamp, value));//�洢set()�����Ĳ���ֵ
	}

	string get(string key, int timestamp) {
		auto iter = mun[key].upper_bound(timestamp);
		/*����ʹ���˶��ַ��������������ʹ��upper_bound(),
		��Ϊ�����С�����ж��������ֵ���򷵻ض�Ӧ����timestamp_prev���Ǹ�ֵ�����������
		iter��λ�ã�ǡ�������ֵ����һ��λ��
		*/
		return iter == mun[key].end() ? prev(iter)->second : (iter == mun[key].begin() ? "" : prev(iter)->second);
		/*����Ҳ����ʹ�� return iter == mun[key].begin() ? "" : prev(iter)->second;  ����������Ϊ�������*/
		/*ʹ���������ַ�������ʾ�����map������û���ҵ���С��timestamp��ֵ����ʾmap�����е�ֵ��������Ŀ��
		������ֻ��Ҫȡǰһλ�õ�ֵ��
		����ҵ��ˣ�������������Ҫ�жϣ��ҵ���λ���ǲ�����map�ĵ�һ��λ�ã�����ڣ����ʾmap�е�Ԫ�ض���������Ŀ�������""
		������ڣ���ʾiterǰһλ�õ�ֵ��������Ŀ�ġ�
		*/
	}
private:
	map<string, map<int, string> > mun;//�洢set()������map����
};