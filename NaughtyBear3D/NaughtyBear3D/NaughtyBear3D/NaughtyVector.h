#pragma once
#include <algorithm>
#include "BearMatrix.h"

class NaughtyVector
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	NaughtyVector() = default;
	NaughtyVector(float x1, float y1, float z1, float w1) :x(x1), y(y1), z(z1), w(w1) {}
	NaughtyVector(const NaughtyVector& vec):x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}
	NaughtyVector& operator = (const NaughtyVector & vec)
	{
		if (&vec == this)
			return *this;

		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
		return *this;
	}
public:
	//��������
	float Length()const;
	//��һ��
	NaughtyVector Normalize();
	//��ˣ������������������Ƴ̶� |a||b|cos�� 
	float Dot(const NaughtyVector& v) const;
	//���(��˵õ���������ֱ��ԭ������������)
	NaughtyVector Cross(const NaughtyVector& v) const;
	//== ��������
	bool operator == (const NaughtyVector& v) const;
	//��任�������
	NaughtyVector operator*(const BearMatrix& m) const;
	//��Vector�������
	NaughtyVector operator*(const NaughtyVector& vec)const;
	//��������
	NaughtyVector operator*(float factor)const;
	//+���������	
	NaughtyVector operator+(const NaughtyVector& vec);
	//-���������
	NaughtyVector operator-(const NaughtyVector& vec);
	//����
	NaughtyVector operator-()const;
};

class NFLOAT3
{
public:
	float x;
	float y;
	float z;

public:
	NFLOAT3() = default;
	NFLOAT3(float r, float b, float g) :x(r), y(b), z(g) {}
	NFLOAT3(const NFLOAT3& f3) :x(f3.x), y(f3.y), z(f3.z) {}
	NFLOAT3& operator = (const NFLOAT3& f3) {
		if (this != &f3)
		{
			x = f3.x;
			y = f3.y;
			z = f3.z;
		}
		return *this;
	}
};

class NFLOAT2
{
public:
	float u;
	float v;


public:
	NFLOAT2() = default;
	NFLOAT2(float r, float b) :u(r), v(b) {}
	NFLOAT2(const NFLOAT2& f2) :u(f2.u), v(f2.v) {}
	NFLOAT2& operator = (const NFLOAT2& f2) {
		if (this != &f2)
		{
			u = f2.u;
			v = f2.v;
		}
		return *this;
	}
};
