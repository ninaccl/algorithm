#include "stack.h"

bool Init(SqStack &S)
{
	S.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!S.base)
		return false;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool GetTop(SqStack S, int &e)
{
	if (S.top == S.base)
		return false;
	e = *(S.top - 1);
	return true;
}

bool Push(SqStack &S, int e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(int));
		if (!S.base)
			return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return true;
}

bool pop(SqStack &S, int &e)
{
	if (S.top == S.base)
		return false;
	e = *--S.top;
	return true;
}

bool Clear(SqStack &S)
{
	//TODO
}

bool DestroyStack(SqStack &S)
{
	//TODO
}