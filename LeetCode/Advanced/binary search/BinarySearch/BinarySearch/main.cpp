#include "Solution.h"
#include "TimeMap.h"

void main()
{
	TimeMap kv;
	kv.set("foo", "bar", 1); // �洢�� "foo" ��ֵ "bar" �Լ�ʱ��� timestamp = 1   
	cout << kv.get("foo", 1) << " ";  // ��� "bar"   
	cout << kv.get("foo", 3) << " "; // ��� "bar" ��Ϊ��ʱ��� 3 ��ʱ��� 2 ��û�ж�Ӧ "foo" ��ֵ������Ψһ��ֵλ��ʱ��� 1 ������ "bar"��   
	kv.set("foo", "bar2", 4);
	cout << kv.get("foo", 4) << " "; // ��� "bar2"   
	cout << kv.get("foo", 5) << " "; // ��� "bar2" 


	//Solution sln;
	//vector<int> vec = { };
	//vector<int> res;

	//int idx = sln.searchInsert(vec, 5);
	//res = sln.searchRange(vec, 0);
	
	return;
}