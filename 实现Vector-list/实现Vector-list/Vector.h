#pragma once
#include<assert.h>
typedef int DataType;

class Vector
{
public:
	Vector();//构造
	Vector(const Vector& v);//拷贝构造
	Vector& operator=(const Vector& v);//赋值运算符的重载
	~Vector();//析构
	size_t Size();//大小
	size_t Capacity();//容量
	void Show();
	void Expand(size_t n);//扩容
	void PushBack(DataType x);//尾插
	void Reserve(size_t n);//逆置
	void PopBack();//尾删

	void Insert(size_t pos, DataType x);//插入
	void Erase(size_t pos);//删除
	size_t Find(DataType x);//查找
	void Swap(Vector& tmp);
	
private:
	DataType* _first;
	DataType* _finish;
	DataType* _endofstorage;
};



