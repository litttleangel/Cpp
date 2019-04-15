#pragma once
#include<assert.h>
typedef int DataType;

class Vector
{
public:
	Vector();//����
	Vector(const Vector& v);//��������
	Vector& operator=(const Vector& v);//��ֵ�����������
	~Vector();//����
	size_t Size();//��С
	size_t Capacity();//����
	void Show();
	void Expand(size_t n);//����
	void PushBack(DataType x);//β��
	void Reserve(size_t n);//����
	void PopBack();//βɾ

	void Insert(size_t pos, DataType x);//����
	void Erase(size_t pos);//ɾ��
	size_t Find(DataType x);//����
	void Swap(Vector& tmp);
	
private:
	DataType* _first;
	DataType* _finish;
	DataType* _endofstorage;
};



