#include "test.h"


void ListInit(List* list)
{
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		list->arr[i] = '\0';
	}
	list->listPos = 0;
	list->listLen = MAX_ARRAY;
}


void LInsert(List* list, int data)
{
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		if (list->arr[i] == '\0')
		{
			list->arr[i] = data;
			return;
		}
	}
}


int LCount(List* list)
{
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		if (list->arr[i] == '\0')
		{
			list->listLen = i - 1;
			return i;
		}
	}
}


int LFirst(List* list, int* data)
{
	list->listPos = 0;
	*data = list->arr[list->listPos];

	return *data;
}


int LNext(List* list, int* data)
{
	list->listPos += 1;
	*data = list->arr[list->listPos];

	return *data;
}


void LRemove(List* list)
{
	for (int i = list->listPos; i < list->listLen; i++)
	{
		list->arr[i] = list->arr[i + 1];
	}
	list->arr[list->listLen] = '\0';
	list->listPos -= 1;
	list->listLen -= 1;
}