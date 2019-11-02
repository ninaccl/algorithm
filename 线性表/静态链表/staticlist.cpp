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
	//������ռ��ʼ��Ϊһ������
	//��һά����S�и���������һ����������S[0].curΪͷָ��
	//"0"��ʾ��ָ��
	for (int i = 0;i < MAXSIZE;i++)
		S[i].cur = i + 1;
	S[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList &S)
{
	//�ӱ��ÿռ�ȡ��һ�����
	//����������ǿգ������±�
	//���򣬷���0
	int i = S[0].cur;
	if (S[0].cur)
		S[0].cur = S[i].cur;
	return i;
}

void Free_SL(SLinkList &S, int k)
{
	//���±�Ϊk�Ŀ��н����յ���������
	S[k].cur = S[0].cur;
	S[0].cur = k;
}

void difference(SLinkList &S, int &l)
{
	//�������뼯��A��B��Ԫ�أ���һά����S�н�����ʾ����(A-B)U(B-A)�ľ�̬����
	//SΪ��ͷָ�룬���豸�ÿռ��㹻��,S[0].curΪ��ͷָ��
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

