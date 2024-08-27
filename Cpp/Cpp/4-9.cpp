// Point 객체만의 함수 템플릿 특수화 지원
#include <iostream>
using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
};

template <class T>
void Print(T a)
{
	cout << a << endl;
}

template <>
void Print(Point a)
{
	cout << "Print 특수화 버전: ";
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);		// 특수화 버전 호출
}