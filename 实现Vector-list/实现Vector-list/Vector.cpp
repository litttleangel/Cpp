
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"Vector.h"

using namespace std;

Vector::Vector()//构造
	:_first(NULL)
	, _finish(NULL)
	, _endofstorage(NULL)
{}

Vector::~Vector()//析构
{
	if (_first)
	{
		delete[]_first;
	}
	_first=_finish = _endofstorage = NULL;
}

void Vector::Show()
{
	DataType*cur = _first;
	while (cur < _finish)
	{
		cout << *cur << ' ';
		++cur;
	}
	cout << endl;
}

size_t Vector::Size()//大小
{
	return _finish - _first;
}

size_t Vector::Capacity()//容量
{
	return _endofstorage - _first;
}




//v1(v)——>深拷贝
Vector::Vector(const Vector& v)//拷贝构造
{
	if (this != &v)
	{
		DataType* cur = v._first;
		while (cur < v._finish)//用尾插法把数据一个一个插进去
							  //因为是拷贝构造，是构造出一个类v，与v的_finish比较
		{
			this->PushBack(*cur);
			cur++;
		}

	}
	
}

void Vector::Swap(Vector& tmp)
{
	
	swap(_first, tmp._first);
	swap(_finish ,tmp._finish);
	swap(_endofstorage , tmp._endofstorage);
}


Vector& Vector::operator=(const Vector& v)//赋值运算符的重载
{
	if (this != &v)
	{
		Vector tmp(v);
		Swap(tmp);
	}
	return *this;

}



void Vector::Expand(size_t n)//扩容
{
	if (n > Capacity())
	{
		DataType*array =new DataType[n];
		DataType*_newend = array + n;
		DataType*_newfinish = array;

		DataType*cur = _first;
		while (cur < _finish)
		{
			*_newfinish = *cur;
			cur++;
			_newfinish++;
		}
		delete[]_first;
		_finish = _endofstorage = NULL;
		
		_first = array;
		_finish = _newfinish;
		_endofstorage = _newend;

		//开空间，拷数据
	}
}


void Vector::PushBack(DataType x)//尾插
{
	if (_finish == _endofstorage)
	{
		size_t capacity = Capacity() > 0 ? Capacity() * 2 : 3;
		Expand(capacity);
	}

	*_finish = x;
	_finish++;
}

void Vector::Reserve(size_t n)//n的大小，保留空间，预开空间
{
	Expand(n);
}

void Vector::PopBack()//尾删
{
	if (_finish != NULL&&_finish != _first)
	{
		_finish--;
	}
	
}

void Vector::Insert(size_t pos, DataType x)//插入(4种)
{
	if (_first + pos > _endofstorage)//插入位置不合法（插入位置超过总容量）
	{
		return;
	}

	if (_first + pos == _endofstorage)//插入位置刚好在_endofstorage，扩容
	{
		size_t capacity = Capacity() > 0 ? Capacity() * 2 : 3;
		Expand(capacity);
	}

	DataType*cur = _finish;//合理插入两种：1.插入位置在_finish 之前的某个位置  2.在finish之后
	while (cur >= _first+pos)
	{
		*(cur + 1) = *cur;
		--cur;
	}
	*(_first + pos) = x;
	_finish++;
	
}

void Vector::Erase(size_t pos)//删除（3种）
{
	if (_first + pos > _endofstorage)//删除位置越界
	{
		return;
	}

	//头删、尾删、中间删——将pos位置的数和_finish位置的进行交换，然后删除_finish位置的那个
	DataType tmp = *(_first + pos);
	tmp = *(_finish - 1);
	*(_finish - 1) = tmp;

	--_finish;
}



size_t Vector::Find(DataType x)//查找
{
	assert(_first);

	DataType*cur = _first;
	while (cur<_finish)
	{
		if (*cur == x)
		{
			return cur-_first;//找到，就返回这个数据对应的指针
		}
		++cur;
	}
	return - 1;
}



