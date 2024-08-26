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
	const String& operator=(const char* str)
	{
		delete[] s;
		s = new char[strlen(str) + 1];
		strcpy(s, str);
		return *this;
	}
};

int main()
{
	const char* sz = "Hello!";
	String s("Hi~");
	s = sz;

	return 0;
}