#pragma once
#include<malloc.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;


bool Init(SqStack &S);
bool GetTop(SqStack S, int &e);
bool Push(SqStack &S, int e);
bool pop(SqStack &S, int &e);
bool Clear(SqStack &S);
bool DestroyStack(SqStack &S);