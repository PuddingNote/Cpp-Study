/*
업데이트 정보 : [2024-08-14] ver0.9
*/

#include "String.h"

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete[] str;
	}
}

String& String::operator=(const String& s)
{
	if (str != NULL)
	{
		delete[] str;
	}
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}

String& String::operator+=(const String& s)
{
	len += (s.len - 1);
	char* tempStr = new char[len];
	strcpy(tempStr, str);
	strcat(tempStr, s.str);

	if (str != NULL)
	{
		delete[] str;
	}
	str = tempStr;

	return *this;
}

bool String::operator==(const String& s)
{
	if (strcmp(str, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

String String::operator+(const String& s)
{
	int tempLen = len + s.len - 1;
	char* tempStr = new char[tempLen];
	strcpy(tempStr, str);
	strcat(tempStr, s.str);

	String temp = tempStr;	// String temp(tempStr);
	delete[] tempStr;

	return temp;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}