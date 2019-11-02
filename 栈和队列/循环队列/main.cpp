#include <malloc.h>

#define MAXQSIZE 100
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

bool initQueue(SqQueue &Q)
{
	Q.base = (int *)malloc(MAXQSIZE*sizeof(int *));
	if (!Q.base)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool enterQueue(SqQueue &Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)//¶ÓÁÐÂú
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool delQueue(SqQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

void main()
{
	SqQueue Q;
	int e;
	initQueue(Q);
	enterQueue(Q, 4);
	enterQueue(Q, 3);
	delQueue(Q, e);
}