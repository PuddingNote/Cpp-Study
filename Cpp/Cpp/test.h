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


void ListInit(List* list);				// 리스트 초기화
void LInsert(List* list, int data);		// 데이터 삽입

int LCount(List* list);					// 길이 출력

int LFirst(List* list, int* data);		// 첫번째 데이터 출력
int LNext(List* list, int* data);		// 데이터 출력

void LRemove(List* list);				// 데이터 삭제

#endif