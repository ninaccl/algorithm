#include "list.h"

int InitList_Sq(SqList &L) {
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 1;
}

int ListInsert_Sq(SqList &L, int i, int e)
{
	if (i<1 || i>L.length + 1)
		return 0;
	if (L.length >= L.listsize)
	{
		int *newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(int));
		if (!newbase)
			exit(0);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	int *q = &(L.elem[i - 1]);
	for (int *p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return 1;
}

int ListDel(SqList &L, int i)
{
	if (i<1 || i>L.length)
		return 0;
	int *p = &L.elem[i - 1];
	int e = *p;
	for (p++;p <= L.elem + L.length - 1;p++)
	{
		*(p - 1) = *p;
	}
	L.length--;
	return 1;
}

SqList ListMerge(SqList La, SqList Lb)
{

	SqList Lc;
	int *pa = La.elem;
	int *pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	int *pc = Lc.elem = (int*)malloc(Lc.listsize*sizeof(int));
	if (!Lc.elem)
		exit(OVERFLOW);
	int *pa_last = La.elem + La.length - 1;
	int *pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
	return Lc;
}