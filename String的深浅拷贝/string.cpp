#include<iostream>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}


	String(const String &s)
		:_str(s._str)




private:
	char*_str;
};