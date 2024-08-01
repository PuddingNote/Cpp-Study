#include <iostream>

namespace BestComTmp1
{
	void SimpleFunc(void)
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImp1
{
	void SimpleFunc(void)
	{
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main(void)
{
	BestComTmp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	return 0;
}