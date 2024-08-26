// Point 클래스의 int 타입 변환 연산자
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	explicit Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void Print() const
	{
		cout << xpos << ", " << ypos << endl;
	}
	operator int() const
	{
		return xpos;
	}
};

int main()
{
	int n = 10;

	Point pt(2, 3);
	n = pt;				// pt.operator int() 암시적 호출
	cout << n << endl;

	return 0;
}