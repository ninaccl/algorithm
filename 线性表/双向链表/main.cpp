#include<stdlib.h>

typedef struct DulNode
{
	int data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLink;

int InsertListDul(DuLink &L, int i, int e)
{
	//�ڵ�i��λ��ǰ����e
	//i�ĺϷ�ֵΪ1<=i<=��+1
	if (!(p = GetElemDul(L, i)))
		return 0;
	//i���ڱ���1ʱ��pָ��ͷ��㣻i���ڱ���1ʱ��p=NULL
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