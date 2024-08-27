// Point 객체를 출력하지 못하는 함수 템플릿 예제
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

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	Print(pt);	// 에러! 연산이 불가능
}