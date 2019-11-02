#include "staticlist.h"

int LocateElem_SL(SLinkList S, int e)
{
	int i = S[0].cur;
	while (i&&S[i].data != e)
		i = S[i].cur;
	return i;
}

void InitSpace_SL(SLinkList &S)
{
	//将数组空间初始化为一个链表
	//将一维数组S中各分量链成一个备用链表，S[0].cur为头指针
	//"0"表示空指针
	for (int i = 0;i < MAXSIZE;i++)
		S[i].cur = i + 1;
	S[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList &S)
{
	//从备用空间取回一个结点
	//若备用链表非空，返回下标
	//否则，返回0
	int i = S[0].cur;
	if (S[0].cur)
		S[0].cur = S[i].cur;
	return i;
}

void Free_SL(SLinkList &S, int k)
{
	//将下标为k的空闲结点回收到备用链表
	S[k].cur = S[0].cur;
	S[0].cur = k;
}

void difference(SLinkList &S, int &l)
{
	//依次输入集合A和B的元素，在一维数组S中建立表示集合(A-B)U(B-A)的静态链表，
	//S为其头指针，假设备用空间足够大,S[0].cur为其头指针
	InitSpace_SL(S);
	l = Malloc_SL(S);
	int r = l;
	int m, n;
	scanf_s("%d%d",&m, &n);
	for (int j = 1;j <= m;++j)
	{
		int i = Malloc_SL(S);		
		scanf_s("%c", &S[i].data);
		S[r].cur = i;
		r = i;
	}
	S[r].cur = 0;
	char b;
	for (int j = 1;j <= n;++j)
	{
		scanf_s("%c", &b);
		int p = l;
		int k = S[l].cur;
		while (k != S[r].cur&&S[k].data != b)
		{
			p = k;
			k = S[k].cur;
		}
		if (k == S[r].cur)
		{
			int i = Malloc_SL(S);
			S[i].data = b;
			S[i].cur = S[r].cur;
			S[r].cur = i;
		}
		else
		{
			S[p].cur = S[k].cur;
			Free_SL(S, k);
			if (r == k)
				r = p;
		}
	}
}

