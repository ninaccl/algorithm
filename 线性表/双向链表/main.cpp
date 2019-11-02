#include<stdlib.h>

typedef struct DulNode
{
	int data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLink;

int InsertListDul(DuLink &L, int i, int e)
{
	//在第i个位置前插入e
	//i的合法值为1<=i<=表长+1
	if (!(p = GetElemDul(L, i)))
		return 0;
	//i等于表长加1时，p指向头结点；i大于表长加1时，p=NULL
	if (!(s = (DuLink)malloc(sizeof(DulNode))))
		return 0;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}

int DelListDul(DuLink &L, int i, int &e)
{
	if (!(p = GetElemDul(L, i)))
		return 0;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 0;
}

void main()
{

}