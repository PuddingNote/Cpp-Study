// 객체 정보를 출력하는 ObjectInfo 클래스
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class ObjectInfo
{
	T data;
public:
	ObjectInfo(const T& d) : data(d) { }

	void Print()
	{
		cout << "타입 : " << typeid(data).name() << endl;
		cout << "크기 : " << sizeof(data) << endl;
		cout << "값 : " << data << endl << endl;
	}
};

int main()
{
	ObjectInfo<int> d1(10);
	d1.Print();

	ObjectInfo<double> d2(5.5);
	d2.Print();

	ObjectInfo<string> d3("Hello!");
	d3.Print();

	return 0;
}