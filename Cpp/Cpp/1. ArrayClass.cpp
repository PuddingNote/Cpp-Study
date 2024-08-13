#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	// 배열은 저장소의 일종이고, 저장소에 저장된 데이터는 유일성을 보장받아야한다.
	// 따라서 대부분의 경우 저장소의 복사는 불필요하거나 잘못된 일로 간주하기 때문에
	// 깊은복사가 되도록 클래스를 정의하는게 아니라 private멤버로 복사와 대입을 원천적으로 막는게 좋다.
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int index)
	{
		if (index < 0 || index >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[index];
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}

	/*for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}*/

	BoundCheckIntArray cpy(5);
	cpy = arr;						// 안전하지 않은 코드
	BoundCheckIntArray copy = arr;	// 안전하지 않은 코드

	return 0;
}