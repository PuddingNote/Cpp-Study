// 문제 1
#include <iostream>

int main(void)
{
	int input;
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> input;
		result += input;
	}

	std::cout << "합계: " << result << std::endl;

	return 0;
}

// 문제2
#include <iostream>

int main(void)
{
	char name[100];
	char num[100];

	std::cout << "이름: ";
	std::cin >> name;

	std::cout << "전화번호: ";
	std::cin >> num;

	std::cout << "이름: " << name << std::endl;
	std::cout << "전화번호: " << num << std::endl;

	return 0;
}

// 문제3
#include <iostream>

int main(void)
{
	int num;

	std::cout << "숫자 입력: ";
	std::cin >> num;

	std::cout << num << "행 구구단" << std::endl;
	for (int i = 1; i < 10; i++)
	{
		std::cout << num << " * " << i << " = " << num * i << std::endl;
	}

	return 0;
}

// 문제 4
#include <iostream>

int main(void)
{
	int price;

	while (true)
	{
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> price;

		if (price == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		}

		std::cout << "이번 달 급여: " << 50 + price * 0.12 << "만원" << std::endl;
	}

	return 0;
}