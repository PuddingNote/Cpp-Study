#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* nextNode;
};

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int input = 0;

	// ������ ����
	for (int i = 0; i < 5; i++)
	{
		cout << "������ ���� : ";
		cin >> input;

		newNode = new Node;
		newNode->data = input;
		newNode->nextNode = NULL;
		if (head == NULL)
		{
			head = newNode;
			cur = head;
		}
		else
		{
			tail->nextNode = newNode;
		}
		
		tail = newNode;
	}
	cout << endl;

	// ������ ���
	cout << "������ ��� : ";
	cur = head;
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->nextNode;
	}
	cout << endl << endl;

	// ������ ����
	while (head != NULL)
	{
		cur = head;
		head = head->nextNode;

		cout << cur->data << " ����" << endl;
		delete cur;
	}
	cout << endl;

	// ������ ���
	cout << "������ ��� : ";
	cur = head;
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->nextNode;
	}
	cout << endl << endl;

	return 0;
}