#include "LinkList.h"


void main()
{
	//InitList();
//	LinkList L = CreateLinkListHead(5);
//	LinkList L = CreateLinkListTail(5);
	
/*	int e;
	GetElem_L(L, 3, e);
	ListInsert(L, 3, 6);
	ListDel(L, 3);
*/
	

	LinkList La = CreateLinkListTail(5);
	LinkList Lb = CreateLinkListTail(5);
	MergeList(La, Lb);
	output(La);
	getlen(La);
}

