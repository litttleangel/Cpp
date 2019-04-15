
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"Vector.h"

using namespace std;

Vector::Vector()//����
	:_first(NULL)
	, _finish(NULL)
	, _endofstorage(NULL)
{}

Vector::~Vector()//����
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

size_t Vector::Size()//��С
{
	return _finish - _first;
}

size_t Vector::Capacity()//����
{
	return _endofstorage - _first;
}




//v1(v)����>���
Vector::Vector(const Vector& v)//��������
{
	if (this != &v)
	{
		DataType* cur = v._first;
		while (cur < v._finish)//��β�巨������һ��һ�����ȥ
							  //��Ϊ�ǿ������죬�ǹ����һ����v����v��_finish�Ƚ�
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


Vector& Vector::operator=(const Vector& v)//��ֵ�����������
{
	if (this != &v)
	{
		Vector tmp(v);
		Swap(tmp);
	}
	return *this;

}



void Vector::Expand(size_t n)//����
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

		//���ռ䣬������
	}
}


void Vector::PushBack(DataType x)//β��
{
	if (_finish == _endofstorage)
	{
		size_t capacity = Capacity() > 0 ? Capacity() * 2 : 3;
		Expand(capacity);
	}

	*_finish = x;
	_finish++;
}

void Vector::Reserve(size_t n)//n�Ĵ�С�������ռ䣬Ԥ���ռ�
{
	Expand(n);
}

void Vector::PopBack()//βɾ
{
	if (_finish != NULL&&_finish != _first)
	{
		_finish--;
	}
	
}

void Vector::Insert(size_t pos, DataType x)//����(4��)
{
	if (_first + pos > _endofstorage)//����λ�ò��Ϸ�������λ�ó�����������
	{
		return;
	}

	if (_first + pos == _endofstorage)//����λ�øպ���_endofstorage������
	{
		size_t capacity = Capacity() > 0 ? Capacity() * 2 : 3;
		Expand(capacity);
	}

	DataType*cur = _finish;//����������֣�1.����λ����_finish ֮ǰ��ĳ��λ��  2.��finish֮��
	while (cur >= _first+pos)
	{
		*(cur + 1) = *cur;
		--cur;
	}
	*(_first + pos) = x;
	_finish++;
	
}

void Vector::Erase(size_t pos)//ɾ����3�֣�
{
	if (_first + pos > _endofstorage)//ɾ��λ��Խ��
	{
		return;
	}

	//ͷɾ��βɾ���м�ɾ������posλ�õ�����_finishλ�õĽ��н�����Ȼ��ɾ��_finishλ�õ��Ǹ�
	DataType tmp = *(_first + pos);
	tmp = *(_finish - 1);
	*(_finish - 1) = tmp;

	--_finish;
}



size_t Vector::Find(DataType x)//����
{
	assert(_first);

	DataType*cur = _first;
	while (cur<_finish)
	{
		if (*cur == x)
		{
			return cur-_first;//�ҵ����ͷ���������ݶ�Ӧ��ָ��
		}
		++cur;
	}
	return - 1;
}



