// ����1
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

// ���� 2
// ������ ���� ������ �Լ� �����ε��� ������ ����
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
	std::cout << SimpleFunc(); // �Ű������� ������� ȣ���ϸ� �����ε� �Լ��� ��ġ�� ������ ������ �߻�

	return 0;
}