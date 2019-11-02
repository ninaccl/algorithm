#include "list.h"

void main()
{
	SqList L;
	InitList_Sq(L);
	for (int i = 1;i <= 10;i++)
	{
		ListInsert_Sq(L, i, i);
	}
	ListDel(L, 8);
	SqList La,Lb;
	int La_elem[4] = { 3, 5, 8, 11 };
	La.elem = La_elem;
	La.length = La.listsize = 4;
	int Lb_elem[7] = { 2,6,8,9,11,15,20 };
	Lb.elem = Lb_elem;
	Lb.length = Lb.listsize = 7;
	ListMerge(La, Lb);
}

