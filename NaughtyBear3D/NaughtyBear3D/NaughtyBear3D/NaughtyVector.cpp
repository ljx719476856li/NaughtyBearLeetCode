#include "NaughtyVector.h"

//��������
float NaughtyVector::Length()const { return 0; }

//��һ��
NaughtyVector NaughtyVector::Normalize() { return NaughtyVector(1, 2, 3, 4); }

//��ˣ������������������Ƴ̶� |a||b|cos�� 
float NaughtyVector::Dot(const NaughtyVector& v) const { return y; }

//���(��˵õ���������ֱ��ԭ������������)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const { return v; }

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