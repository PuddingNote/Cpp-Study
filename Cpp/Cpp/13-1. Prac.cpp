// 문제 1
//#include <iostream>
//using namespace std;
//
//class Point
//{
//private:
//	int xpos;
//	int ypos;
//
//public:
//	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
//	{
//
//	}
//	void ShowPosition() const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//};
//
//template <class T>
//void SwapData(T& data1, T& data2)
//{
//	T temp;
//
//	temp = data1;
//	data1 = data2;
//	data2 = temp;
//}
//
//int main(void)
//{
//	Point p1(1, 2);
//	Point p2(3, 4);
//
//	SwapData(p1, p2);
//
//	p1.ShowPosition();
//	p2.ShowPosition();
//
//	return 0;
//}

// 문제 2
#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len)
{
	T sum = (T)0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int arr1[] = { 1,2,3 };
	cout << SumArray(arr1, sizeof(arr1) / sizeof(int)) << endl;

	double arr2[] = { 10.1,20.2,30.3 };
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << endl;

	return 0;
}