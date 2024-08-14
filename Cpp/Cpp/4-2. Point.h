#ifndef __POINT_
#define __POINT_

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0);
	friend ostream& operator<<(ostream& os, const Point& pos);
};

#endif