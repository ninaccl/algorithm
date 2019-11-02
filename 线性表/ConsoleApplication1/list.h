#pragma once
#include<malloc.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define OVERFLOW -2

typedef struct {
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L);
int ListInsert_Sq(SqList &L, int i, int e);
int ListDel(SqList &L, int i);
SqList ListMerge(SqList La, SqList Lb);
