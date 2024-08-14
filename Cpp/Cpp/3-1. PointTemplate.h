#ifndef __POINT_TEMPLATE_
#define __POINT_TEMPLATE_

template <class T>
class Point
{
private:
	T xpos;
	T ypos;

public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

#endif