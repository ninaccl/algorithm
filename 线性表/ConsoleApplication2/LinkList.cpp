#include "LinkList.h"



int InitList()
{
	LNode* L;
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL)
		return 0;
	L->next = NULL;
	return 1;
}

LinkList CreateLinkListHead(int n)
{
	int x;
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0;i < n;i++)
	{
		LNode *p;
		p = (LNode*)malloc(sizeof(LNode));
		scanf_s("%d", &x);
		p->data = x;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

LinkList CreateLinkListTail(int n)
{
	int x;
	LNode* L;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* r;
	r = L;
	while (n--)
	{
		LNode* p;
		p = (LNode*)malloc(sizeof(LNode));
		scanf_s("%d", &x);
		p->data = x;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}

int GetElem_L(LinkList L, int i, int &e)
{
	//L为带头节点的单链表的头指针
	LinkList p = L->next;
	int j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return 0;
	e = p->data;
	return 1;
}

int ListInsert(LinkList &L, int i, int e)
{
	LinkList p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return 0;
	LNode* ins = (LNode*)malloc(sizeof(LNode));
	ins->data = e;
	ins->next = p->next;
	p->next = ins;
	return 1;
}

int ListDel(LinkList &L, int i)
{
	LinkList p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return 0;
	LinkList q = p->next;
	p->next = q->next;
	int e = q->data;
	free(q);
	return 1;
}

LinkList MergeList(LinkList La, LinkList Lb)
{
	LNode* Lc;
	Lc = (LNode*)malloc(sizeof(LNode));
	Lc->next = NULL;
	LinkList pa = La->next, pb = Lb->next, pc = Lc = La;
	while (pa&&pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
	return Lc;
}

void output(LinkList La)
{
	LinkList pa = La->next;
	for (;pa != NULL;pa = pa->next)
		printf("%d\n", pa->data);
}

int getlen(LinkList La)
{
	LinkList pa = La->next;
	int length = 0;
	while (pa)
	{
		length++;
		pa = pa->next;
	}
	return length;
}

void clear(LinkList La)
{
	LinkList p, q;
	p = La->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	La->next = NULL;
}