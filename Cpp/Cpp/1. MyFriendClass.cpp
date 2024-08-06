// friend선언에 대한 나름의 기준이 설 때까지는 사용을 자제하자! : 객체지향의 정보은닉을 무너뜨리는 문법!
#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;	// friend 선언은 public, private 어디에서든 선언해도 문제가 없다
	
public:
	Boy(int len) : height(len)
	{

	}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];

public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}