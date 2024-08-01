// 문제1
#include <iostream>

int BoxVolume(int length)
{
	return length * 1 * 1;
}

int BoxVolume(int length, int width)
{
	return length * width * 1;
}

int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}

int main(void)
{
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	return 0;
}

// 문제 2
// 다음과 같은 형태의 함수 오버로딩의 문제점 설명
#include <iostream>

int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

int main(void)
{
	std::cout << SimpleFunc(); // 매개변수를 비워놓고 호출하면 오버로딩 함수가 겹치기 때문에 오류가 발생

	return 0;
}