// 내 풀이
//#include <iostream>
//using namespace std;
//
//template <class T>
//class Queue
//{
//	T buf[100];
//	int pos;
//
//public:
//	Queue() : pos(0) { }
//	void Push(const T& data)
//	{
//		buf[pos++] = data;
//	}
//	const T& Pop()
//	{
//		T temp = buf[0];
//		for (int i = 0; i < pos; i++)
//		{
//			buf[i] = buf[i + 1];
//		}
//		pos--;
//		return temp;
//	}
//	bool Empty()
//	{
//		return pos <= 0;
//	}
//};
//
//int main()
//{
//	Queue<int> q;
//
//	q.Push(10);
//	q.Push(20);
//	q.Push(30);
//
//	if (!q.Empty())
//	{
//		cout << q.Pop() << endl;
//	}
//	if (!q.Empty())
//	{
//		cout << q.Pop() << endl;
//	}
//	if (!q.Empty())
//	{
//		cout << q.Pop() << endl;
//	}
//
//	return 0;
//}

// 책 풀이
#include <iostream>
using namespace std;

template <class T>
class Queue
{
	enum { CAP = 100 };
	T buf[CAP];
	int front;
	int rear;

public:
	Queue() : front(0), rear(0) { }
	void Push(const T& data)
	{
		buf[rear = (rear + 1) % CAP] = data;
	}
	const T& Pop()
	{
		return buf[front = (front + 1) % CAP];
	}
	bool Empty()
	{
		return rear == front;
	}
};

int main()
{
	Queue<int> q;

	q.Push(10);
	q.Push(20);
	q.Push(30);

	if (!q.Empty())
	{
		cout << q.Pop() << endl;
	}
	if (!q.Empty())
	{
		cout << q.Pop() << endl;
	}
	if (!q.Empty())
	{
		cout << q.Pop() << endl;
	}

	return 0;
}