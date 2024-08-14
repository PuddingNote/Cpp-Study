#include "4-2. Point.h"

Point::Point(int x, int y) : xpos(x), ypos(y) {}

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}