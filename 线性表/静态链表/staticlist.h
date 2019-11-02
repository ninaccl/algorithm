#pragma once
#include<stdio.h>
#define MAXSIZE 1000
typedef struct
{
	char data;
	int cur;
}component,SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList &S);
int LocateElem_SL(SLinkList S, int e);
int Malloc_SL(SLinkList &S);
void Free_SL(SLinkList &S, int k);
void difference(SLinkList &S, int &l);