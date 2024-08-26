// explicit Point 생성자
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
};

int main()
{
	Point p;
	p.Print();

	p = 10;			// 암시적 생성자 호출 불가능
	p = Point(10);	// 명시적 생성자 호출 가능
	
	p.Print();

	return 0;
}