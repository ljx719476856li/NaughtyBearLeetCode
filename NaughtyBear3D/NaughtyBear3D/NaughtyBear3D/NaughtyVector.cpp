#include "NaughtyVector.h"


//��������
float NaughtyVector::Length()const 
{ 
	float sq = x*x + y*y + z*z;
	return static_cast<float>(sqrt(sq));
}
//��һ��
NaughtyVector NaughtyVector::Normalize() 
{ 
	float length = Length(); //��ȡ�������ĳ��ȣ�Ҳ����ģ
	if (length != 0.0f)
	{
		float inv = 1.0f / length;
		x *= inv;
		y *= inv;
		z *= inv;
	}
}

//��ˣ������������������Ƴ̶� |a||b|cos�� 
float NaughtyVector::Dot(const NaughtyVector& v) const 
{
	return x * v.x + y * v.y + z * v.z;
}

//���(��˵õ���������ֱ��ԭ������������)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const 
{
	float m1 = y * v.z - z * v.y;
	float m2 = z * v.x - x * v.z;
	float m3 = x * v.y - y * v.x;

	return NaughtyVector(m1, m2, m3, 0.0f);
}

//== ��������
bool NaughtyVector::operator == (const NaughtyVector& v) const { return true; }

//��任�������
NaughtyVector NaughtyVector::operator*(const BearMatrix& m) const { return NaughtyVector(1, 2, 3 ,4); }

//��Vector�������
NaughtyVector NaughtyVector::operator*(const NaughtyVector& vec)const { return vec; }

//��������
NaughtyVector NaughtyVector::operator*(float factor)const { return NaughtyVector(1, 2, 3, 4); }

//+���������
NaughtyVector NaughtyVector::operator+(const NaughtyVector& vec) { return vec; }

//-���������
NaughtyVector NaughtyVector::operator-(const NaughtyVector& vec) { return vec; }

//����
NaughtyVector NaughtyVector::operator-()const { return *this; }