// ���� 1
#include <iostream>

int main(void)
{
	int input;
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "��° ���� �Է�: ";
		std::cin >> input;
		result += input;
	}

	std::cout << "�հ�: " << result << std::endl;

	return 0;
}

// ����2
#include <iostream>

int main(void)
{
	char name[100];
	char num[100];

	std::cout << "�̸�: ";
	std::cin >> name;

	std::cout << "��ȭ��ȣ: ";
	std::cin >> num;

	std::cout << "�̸�: " << name << std::endl;
	std::cout << "��ȭ��ȣ: " << num << std::endl;

	return 0;
}

// ����3
#include <iostream>

int main(void)
{
	int num;

	std::cout << "���� �Է�: ";
	std::cin >> num;

	std::cout << num << "�� ������" << std::endl;
	for (int i = 1; i < 10; i++)
	{
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	}

	return 0;
}

// ���� 4
#include <iostream>

int main(void)
{
	int price;

	while (true)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> price;

		if (price == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			break;
		}

		std::cout << "�̹� �� �޿�: " << 50 + price * 0.12 << "����" << std::endl;
	}

	return 0;
}