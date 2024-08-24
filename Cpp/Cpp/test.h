#ifndef __ARRAY_LIST_
#define __ARRAY_LIST_

#define MAX_ARRAY	100

typedef struct _ArrayList
{
	int arr[MAX_ARRAY];
	int listPos;
	int listLen;

} ArrayList;
typedef ArrayList List;


void ListInit(List* list);				// ����Ʈ �ʱ�ȭ
void LInsert(List* list, int data);		// ������ ����

int LCount(List* list);					// ���� ���

int LFirst(List* list, int* data);		// ù��° ������ ���
int LNext(List* list, int* data);		// ������ ���

void LRemove(List* list);				// ������ ����

#endif