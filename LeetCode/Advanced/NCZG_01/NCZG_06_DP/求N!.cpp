#include<iostream>
using namespace std;

/*
 ��Ŀ����N!
 ˼·���ݹ�

 ��չ����β��0
*/
class Factorial
{
public:
	long GetFactorial(int num);

};

long Factorial::GetFactorial(int num)
{
	//0!Ϊ1
	if (num == 0 || num == 1)
		return 1;


	return num * GetFactorial(num - 1);
}

//int main()
//{
//	Factorial sln;
//	long res = sln.GetFactorial(5);
//
//
//	return 0;
//}