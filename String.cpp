#include "String.hpp"

String* String::dummy = 0;
char* String::dummy_char = 0;

int String::GetLen(const char *str)
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return i;
}

void String::StrCopy(char *destination, const char *from)
{
	int i = 0;
	while (*(from+i))
	{
		destination[i] = from[i];
		i++;
	}
	destination[i] = 0;
}

String::String() : str(0), len(0), size(0) {}
String::String(const char *_str)
{
	len = GetLen(_str);
	size = len+1;
	str = new char[size];
	StrCopy(str, _str);
}
String::String(const String& a)
{
	len = a.len;
	str = new char[a.size];
	size = a.size;
	StrCopy(str, a.str);
}
String::~String() { if (str) delete [] str; }

const char* String::operator*() { return str; }
char& String::operator[](int idx)
{
	if (idx >= len || idx < 0)
		return *dummy_char;
	return str[idx];
}
String& String::operator=(const String& a)
{
	if (this != &a)
	{
		if (a.len >= size)
		{
			if (str) 
				delete [] str;
			str = new char[a.size];
			size = a.size;
		}
		len = a.len;
		StrCopy(str, a.str);
	}
	return *this;
}
String& String::operator+=(const String &a)
{
	int new_len = len + a.len;
	if (new_len >= size)
	{
		int new_size = new_len + 1;
		char* new_str = new char[new_size];
		StrCopy(new_str, str);
		delete [] str;
		str = new_str;
		size = new_size;
	}
	StrCopy(str+len, a.str);
	len = new_len;
	return *this;
}

String& String::operator-=(int len)
{
	if (len > this->len)
		return *dummy;
	str[this->len - len] = 0;
	this->len -= len;
	return *this;
}

////////////////////////////////////////////////
