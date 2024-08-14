#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

// 함수 템플릿의 특수화
// 가급적이면 자료형 정보를 명시하는 것이 뜻을 명확히 하는 방법이 된다.
template <>
char* Max(char* a, char* b)	// char* Max<char*>(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b)	// const char* Max<const char*>(const char* a, const char* b)
{
	cout << "const char* Max<char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;

	return 0;
}