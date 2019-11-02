#pragma once
#include<malloc.h>
#include<stdio.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;



int InitList();
LinkList CreateLinkListHead(int n);
LinkList CreateLinkListTail(int n);
int GetElem_L(LinkList L, int i, int &e);
int ListInsert(LinkList &L, int i, int e);
int ListDel(LinkList &L, int i);
int ListDel(LinkList &L, int i);
LinkList MergeList(LinkList La, LinkList Lb);
void output(LinkList La);
int getlen(LinkList La);
void clear(LinkList La);