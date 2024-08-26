#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* s;

public:
	String(const char* str)
	{
		s = new char[strlen(str) + 1];
		strcpy(s, str);
	}
	~String()
	{
		delete[] s;
	}
	operator const char*() const
	{
		return s;
	}
};

int main()
{
	String s("Hello!");
	const char* sz = s;
	
	return 0;
}