#include "NaughtyVector.h"

//��������
float NaughtyVector::Length()const {}

//��һ��
NaughtyVector NaughtyVector::Normalize(){}

//��ˣ������������������Ƴ̶� |a||b|cos�� 
float NaughtyVector::Dot(const NaughtyVector& v) const{}

//���(��˵õ���������ֱ��ԭ������������)
NaughtyVector NaughtyVector::Cross(const NaughtyVector& v) const{}

//== ��������
bool NaughtyVector::operator == (const NaughtyVector& v) const{}

//��任�������
NaughtyVector NaughtyVector::operator*(const BearMatrix& m) const{}

//��Vector�������
NaughtyVector NaughtyVector::operator*(const NaughtyVector& vec)const{}

//��������
NaughtyVector NaughtyVector::operator*(float factor)const{}

//+���������
NaughtyVector NaughtyVector::operator+(const NaughtyVector& vec){}

//-���������
NaughtyVector NaughtyVector::operator-(const NaughtyVector& vec){}

//����
NaughtyVector NaughtyVector::operator-()const{}