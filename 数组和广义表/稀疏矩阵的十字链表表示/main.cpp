#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<process.h>
#define OK 1
#define ERROR 0
#define MY_OVERFLOW -2
typedef int ElemType;

using namespace std;
struct OLNode
{
	int i, j; //����Ԫ�����С���
	ElemType e;//����Ԫֵ
	OLNode *right, *down;
};
typedef OLNode *OLink;
struct CrossList
{
	OLink *rhead, *chead;//�С��б�ͷ��ͷ�ڵ�
	int mu, nu, tu;//������С��кͷ���Ԫ����
};

int Create(CrossList &M)
{
	int i, j, k, m, n, t;
	ElemType e;
	OLNode *p, *q;
	printf("������ϡ���������� ���� ����Ԫ�ĸ�����");
	scanf_s("%d%d%d", &m, &n, &t);
	M.mu = m;
	M.nu = n;
	M.tu = t;
	M.rhead = (OLink*)malloc((m + 1)*sizeof(OLink));
	if (!M.rhead)
		exit(MY_OVERFLOW);
	M.chead = (OLink*)malloc((n + 1)*sizeof(OLink));
	if (!M.chead)
		exit(MY_OVERFLOW);
	for (k = 0;k != m;k++)//��ʼ����ͷָ��
		M.rhead[k] = NULL;
	for (k = 0;k != n;k++)//��ʼ����ͷָ��
		M.chead[k] = NULL;
	printf("�밴�����������%d������Ԫ���� �� Ԫ��ֵ:\n", M.tu);
	for (k = 0;k<t;k++)
	{
		scanf_s("%d%d%d", &i, &j, &e);
		if (i>m || j>n)
		{
			printf("�������Ԫ�ز��ھ����� ��������:\n");
			exit(MY_OVERFLOW);
		}
		else
		{
			p = (OLNode*)malloc(sizeof(OLNode));
			if (!p)
				exit(MY_OVERFLOW);
			p->i = i;
			p->j = j;
			p->e = e;
			if (M.rhead[i] == NULL || M.rhead[i]->j>j)//p������е�һ�ڵ㴦
			{
				p->right = M.rhead[i];
				M.rhead[i] = p;
			}
			else//Ѱ���б����λ��
			{
				for (q = M.rhead[i];q->right&&q->right->j<j;q = q->right);
				p->right = q->right;//����в���
				q->right = p;
			}
			if (M.chead[j] == NULL || M.chead[j]->i>i)//p������е�һ�ڵ㴦
			{
				p->down = M.chead[j];
				M.chead[j] = p;
			}
			else//Ѱ���б����λ��
			{
				for (q = M.chead[j];q->down&&q->down->i<i;q = q->down);
				p->down = q->down;//����в���
				q->down = p;
			}
		}
	}
	return OK;
}

int Print(CrossList M)
{
	int i, j, k;
	OLink p;
	int array[100][100];
	for (i = 0;i != M.mu;i++)
	{
		for (j = 0;j != M.nu;j++)
		{
			array[i][j] = 0;//��ʼ���������貿��
		}
	}
	for (k = 0;k != M.nu;k++)
	{
		p = M.chead[k];
		while (p)
		{
			array[p->i][p->j] = p->e;//������Ԫ����������
			p = p->down;
		}
	}
	for (i = 0;i != M.mu;i++)
	{
		for (j = 0;j != M.nu;j++)
		{
			if (j == M.nu - 1)
				cout << array[i][j] << endl;
			else
				cout << array[i][j] << " ";//�Ծ������ʾ��ʽ��ʾϡ�����
		}
	}
	return OK;
}

int Add(CrossList M, CrossList N, CrossList &Q)
{
	int i, k;
	OLink p, pq=NULL, pm, pn;
	OLink *col;
	Q.mu = M.mu;//��ʼ��Q
	Q.nu = M.nu;
	Q.tu = 0;
	Q.rhead = (OLink*)malloc((Q.mu + 1)*sizeof(OLink));
	if (!Q.rhead)
		exit(MY_OVERFLOW);
	Q.chead = (OLink*)malloc((Q.nu + 1)*sizeof(OLink));
	if (!Q.chead)
		exit(MY_OVERFLOW);
	for (k = 0;k != Q.mu;k++)//��ʼ����
		Q.rhead[k] = NULL;
	for (k = 0;k != Q.nu;k++)//��ʼ����
		Q.chead[k] = NULL;
	col = (OLink*)malloc((Q.nu + 1)*sizeof(OLink));//����ָ���е����ڵ������
	if (!col)
		exit(MY_OVERFLOW);
	for (k = 0;k != Q.nu;k++)//����ʼֵ
		col[k] = NULL;
	for (i = 0;i != M.mu;i++)//���������
	{
		pm = M.rhead[i];
		pn = N.rhead[i];
		while (pm&&pn)
		{
			if (pm->j<pn->j)//����M��ǰ������С�ھ���N��ǰ������
			{
				p = (OLink)malloc(sizeof(OLNode));//����Q�Ľ��
				if (!p)
					exit(MY_OVERFLOW);
				Q.tu++; //����Ԫ������1
				p->i = i; //��ֵ
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; //pm����
			}
			else if (pm->j>pn->j)
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(MY_OVERFLOW);
				Q.tu++;
				p->i = i;
				p->j = pn->j;
				p->e = pn->e;
				p->right = NULL;
				pn = pn->right;
			}
			else if (pm->e + pn->e)//M,N��ǰ��������ͬ������Ԫ��֮�ͷ���
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(MY_OVERFLOW);
				Q.tu++;
				p->i = i;
				p->j = pn->j;
				p->e = pm->e + pn->e;
				p->right = NULL;
				pm = pm->right;//pm����
				pn = pn->right;//pn����
			}
			else//��Ԫ�����Ϊ��
			{
				pm = pm->right;
				pn = pn->right;
				continue;
			}
			if (Q.rhead[i] == NULL)
				Q.rhead[i] = pq = p;
			else
			{
				pq->right = p;//����в���
				pq = pq->right;
			}
			if (Q.chead[p->j] == NULL)
				Q.chead[p->j] = col[p->j] = p;
			else
			{
				col[p->j]->down = p;//����в���
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm)//������M���е�ʣ��Ԫ�ز������Q
		{
			p = (OLink)malloc(sizeof(OLNode));
			if (!p)
				exit(MY_OVERFLOW);
			Q.tu++;
			p->i = i;
			p->j = pm->j;
			p->e = pm->e;
			p->right = NULL;
			pm = pm->right;
			if (Q.rhead[i] == NULL)
				Q.rhead[i] = pq = p;
			else
			{
				pq->right = p;
				pq = pq->right;
			}
			if (Q.chead[p->j] == NULL)
				Q.chead[p->j] = col[p->j] = p;
			else
			{
				col[p->j]->down = p;
				col[p->j] = col[p->j]->down;
			}
		}
		while (pn)//������N���е�ʣ��Ԫ�ز������Q
		{
			p = (OLink)malloc(sizeof(OLNode));
			if (!p)
				exit(MY_OVERFLOW);
			Q.tu++;
			p->i = i;
			p->j = pn->j;
			p->e = pn->e;
			p->right = NULL;
			pn = pn->right;
			if (Q.rhead[i] == NULL)
				Q.rhead[i] = pq = p;
			else
			{
				pq->right = p;
				pq = pq->right;
			}
			if (Q.chead[p->j] == NULL)
				Q.chead[p->j] = col[p->j] = p;
			else
			{
				col[p->j]->down = p;
				col[p->j] = col[p->j]->down;
			}
		}
	}
	for (k = 0;k != Q.nu;k++)
		if (col[k])
			col[k]->down = NULL;
	free(col);
	return OK;
}

CrossList Negative(CrossList M)
{
	OLink p;
	for (int j = 0;j != M.mu;j++)
	{
		p = M.rhead[j];
		while (p)
		{
			p->e = -p->e;//������Ԫ��ֵ����
			p = p->right;
		}
	}
	return (M);
}

int Mult(CrossList M, CrossList N, CrossList &Q)
{
	int i, j, e;
	OLink q, p0, q0, q1=NULL, q2;
	if (M.nu != N.mu)
	{
		printf("����������������ܽ��д˲���\n");
		exit(MY_OVERFLOW);
	}
	else
	{
		Q.mu = M.mu;
		Q.nu = N.nu;
		Q.tu = 0;
		Q.rhead = (OLink*)malloc((Q.mu + 1)*sizeof(OLink));
		if (!Q.rhead)
			exit(MY_OVERFLOW);
		Q.chead = (OLink*)malloc((Q.nu + 1)*sizeof(OLink));
		if (!Q.chead)
			exit(MY_OVERFLOW);
		for (i = 0;i != Q.mu;i++)//��ʼ����
			Q.rhead[i] = NULL;
		for (i = 0;i != Q.nu;i++)//��ʼ����
			Q.chead[i] = NULL;
		for (i = 0;i != Q.mu;i++)
			for (j = 0;j != Q.nu;j++)
			{
				p0 = M.rhead[i];
				q0 = N.chead[j];
				e = 0;
				while (p0&&q0)
				{
					if (q0->i<p0->j)
						q0 = q0->down;//�к���
					else if (q0->i>p0->j)
						p0 = p0->right;//�к���
					else
					{
						e = e + p0->e*q0->e;//�˻��ۼ�
						q0 = q0->down;
						p0 = p0->right;//���к���
					}
				}
				if (e)//e��Ϊ�������Q
				{
					Q.tu++;
					q = (OLink)malloc(sizeof(OLNode));
					if (!q)
						exit(MY_OVERFLOW);
					q->i = i;
					q->j = j;
					q->e = e;
					q->right = NULL;
					q->down = NULL;
					if (!Q.rhead[i])
						Q.rhead[i] = q1 = q;
					else
						q1 = q1->right = q;
					if (!Q.chead[j])
						Q.chead[j] = q;
					else
					{
						q2 = Q.chead[j];
						while (q2->down)
							q2 = q2->down;
						q2->down = q;
					}
				}
			}
		return OK;
	}
}

void main()
{
	CrossList A, B, C;//������������
	int Select;
	cout << "��ѡ������Ҫ�Ĳ���" << endl;
	cout << "1 �ӷ�" << endl;
	cout << "2 ����" << endl;
	cout << "3 �˷�" << endl;
	cin >> Select;
	switch (Select)
	{
	case 1://ϡ��������
	{
		Create(A);
		Create(B);
		cout << "���������" << endl;
		Print(A);
		cout << "����" << endl;
		Print(B);
		Add(A, B, C);
		cout << "�����" << endl;
		Print(C);
		break;
	}
	case 2://ϡ��������
	{
		Create(A);
		Create(B);
		cout << "���������" << endl;
		Print(A);
		cout << "��ȥ" << endl;
		Print(B);
		Negative(B);
		Add(A, B, C);
		cout << "�����" << endl;
		Print(C);
		break;
	}
	case 3://ϡ��������
	{
		Create(A);
		Create(B);
		cout << "���������" << endl;
		Print(A);
		cout << "����" << endl;
		Print(B);
		Mult(A, B, C);
		cout << "�����" << endl;
		Print(C);
		break;
	}
	}
	system("pause");
}