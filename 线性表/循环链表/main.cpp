#include<stdlib.h>
#include<stdio.h>
#define len sizeof(Node)

typedef struct Node
{
	int data;
	struct Node * next;
}Node,*CList;

CList InitList()
{
	CList CL;
	CL = (CList)malloc(len);
	CL->next = CL;
	return CL;
}

void CreateList(CList CL)
{
	//β�巨
	Node *rear, *s;
	rear = CL;
	int flag = 1;
	int x;
	printf("please input data and enter 0 end:\n");
	while (flag)
	{
		scanf_s("%d", &x);
		if (x != 0)
		{
			s = (Node*)malloc(len);
			s->data = x;
			rear->next = s;
			rear = s;
		}
		else
		{
			flag = 0;
			rear->next = CL;
		}
	}
}

void PrintList(CList CL)
{
	Node *p;
	p = CL->next;
	printf("Your input data is:\n");
	for (;p != CL;p = p->next)
	{
		printf("%-3d", p->data);
	}
	printf("\n");
}

void InsertList(CList CL, int i, int x)
{
	Node *p, *s;
	int k = 0;
	p = CL;
	if (i <= 0)
	{
		printf("you enter location illegal:\n");
		return;
	}
	while (p->next != CL&&k < i - 1)
	{
		k++;
		p = p->next;
	}
	if (p == CL)
	{
		printf("The insert position is not reasonable:\n");
		return;
	}
	s = (Node*)malloc(len);
	s->data = x;
	s->next = p->next;
	p->next = s;
	printf("insert successfully\n");
}

void DeleteCL(CList CL, int i)
{
	Node *p, *r;
	p = CL;
	int k = 0;
	if (i < 0)
	{
		printf("your input is illegal\n");
		return;
	}
	while (p->next != CL&&k < i - 1)
	{
		p = p->next;
		k++;
	}
	if (p->next == CL)
	{
		printf("Delete Node i is not illgal!\n");
		return;
	}
	r = p->next;
	p->next = r->next;
	free(r);
}

void Clear(CList CL)
{
	CList p, q;
	p = CL->next;
	while (p!=CL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	CL->next = CL;
}

CList MergeList(CList CL_a, CList CL_b)
{
	Node *p, *q;
	p = CL_a;
	q = CL_b;
	while (p->next != CL_a)
		p = p->next;
	while (q->next != CL_b)
		q = q->next;
	q->next = CL_a;
	p->next = CL_b->next;
	free(CL_b);
	return CL_a;
}

int LenList(CList CL)
{
	int i = 0;
	Node *p;
	p = CL->next;
	while (p != CL)
	{
		i++;
		p = p->next;
	}
	return i;
}

int main()
{
	/*int i, x;
	CList CL = InitList();
	CreateList(CL);
	PrintList(CL);

	printf("please enter the location you want to insert:\n");
	scanf_s("%d", &i);
	printf("please enter the values you want to insert:\n");
	scanf_s("%d", &x);

	InsertList(CL, i, x);
	PrintList(CL);
	free(CL);*/

	CList CL_a = InitList();
	CList CL_b = InitList();
	CreateList(CL_a);
	CreateList(CL_b);
	MergeList(CL_a, CL_b);
	PrintList(CL_a);
	LenList(CL_a);
	free(CL_a);

	return 0;
}