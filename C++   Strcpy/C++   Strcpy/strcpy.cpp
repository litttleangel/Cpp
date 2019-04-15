#include<stdio.h>
using space

class String
{
	public£º
		String(char*str = "", size_t size = 0);
	:_str(str),_size(size)
	{}


private:
	char*_str;
	size_t size;
};



String & operator=(const String&s)
{
	delete[]_str;
	:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		return*this;
	}

}
	



Date(Date&s);

~Date()
{}















