#include <malloc.h>

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

bool initQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		return false;
	Q.front->next = NULL;
	return true;
}

bool destroyQueue(LinkQueue &Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return true;	
}

bool enQueue(LinkQueue &Q, int e)
{
	//rearÎª¶ÓÎ²Ö¸Õë
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return false;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

bool deQueue(LinkQueue &Q, int e)
{
	if (Q.front == Q.rear)
		return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

void main()
{
	int e;
	LinkQueue Q;
	initQueue(Q);
	enQueue(Q, 5);
	enQueue(Q, 6);
	deQueue(Q, e);
	deQueue(Q, e);
}