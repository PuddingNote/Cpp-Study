#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point p;
	int radius;

public:
	void Init(int x, int y, int rad)
	{
		p.Init(x, y);
		radius = rad;
	}
	void ShowCircleInfo() const
	{
		cout << "radius: " << radius << endl;
		p.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle innerCircle;
	Circle outterCircle;

public:
	void Init(int x1, int y1, int rad1, int x2, int y2, int rad2)
	{
		innerCircle.Init(x1, y1, rad1);
		outterCircle.Init(x2, y2, rad2);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		innerCircle.ShowCircleInfo();
		
		cout << "Outter Circle Info..." << endl;
		outterCircle.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	return 0;
}