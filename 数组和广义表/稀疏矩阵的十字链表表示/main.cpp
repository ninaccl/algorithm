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
	int i, j; //非零元所在行、列
	ElemType e;//非零元值
	OLNode *right, *down;
};
typedef OLNode *OLink;
struct CrossList
{
	OLink *rhead, *chead;//行、列表头的头节点
	int mu, nu, tu;//矩阵的行、列和非零元个数
};

int Create(CrossList &M)
{
	int i, j, k, m, n, t;
	ElemType e;
	OLNode *p, *q;
	printf("请输入稀疏距阵的行数 列数 非零元的个数：");
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
	for (k = 0;k != m;k++)//初始化行头指针
		M.rhead[k] = NULL;
	for (k = 0;k != n;k++)//初始化列头指针
		M.chead[k] = NULL;
	printf("请按任意次序输入%d个非零元的行 列 元素值:\n", M.tu);
	for (k = 0;k<t;k++)
	{
		scanf_s("%d%d%d", &i, &j, &e);
		if (i>m || j>n)
		{
			printf("你输入的元素不在矩阵中 请检查重输:\n");
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
			if (M.rhead[i] == NULL || M.rhead[i]->j>j)//p插入该行第一节点处
			{
				p->right = M.rhead[i];
				M.rhead[i] = p;
			}
			else//寻找行表插入位置
			{
				for (q = M.rhead[i];q->right&&q->right->j<j;q = q->right);
				p->right = q->right;//完成行插入
				q->right = p;
			}
			if (M.chead[j] == NULL || M.chead[j]->i>i)//p插入该列第一节点处
			{
				p->down = M.chead[j];
				M.chead[j] = p;
			}
			else//寻找列表插入位置
			{
				for (q = M.chead[j];q->down&&q->down->i<i;q = q->down);
				p->down = q->down;//完成列插入
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
			array[i][j] = 0;//初始化数组所需部分
		}
	}
	for (k = 0;k != M.nu;k++)
	{
		p = M.chead[k];
		while (p)
		{
			array[p->i][p->j] = p->e;//将非零元存入数组中
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
				cout << array[i][j] << " ";//以矩阵的显示方式显示稀疏矩阵
		}
	}
	return OK;
}

int Add(CrossList M, CrossList N, CrossList &Q)
{
	int i, k;
	OLink p, pq=NULL, pm, pn;
	OLink *col;
	Q.mu = M.mu;//初始化Q
	Q.nu = M.nu;
	Q.tu = 0;
	Q.rhead = (OLink*)malloc((Q.mu + 1)*sizeof(OLink));
	if (!Q.rhead)
		exit(MY_OVERFLOW);
	Q.chead = (OLink*)malloc((Q.nu + 1)*sizeof(OLink));
	if (!Q.chead)
		exit(MY_OVERFLOW);
	for (k = 0;k != Q.mu;k++)//初始化行
		Q.rhead[k] = NULL;
	for (k = 0;k != Q.nu;k++)//初始化列
		Q.chead[k] = NULL;
	col = (OLink*)malloc((Q.nu + 1)*sizeof(OLink));//生成指向列的最后节点的数组
	if (!col)
		exit(MY_OVERFLOW);
	for (k = 0;k != Q.nu;k++)//赋初始值
		col[k] = NULL;
	for (i = 0;i != M.mu;i++)//按行序相加
	{
		pm = M.rhead[i];
		pn = N.rhead[i];
		while (pm&&pn)
		{
			if (pm->j<pn->j)//矩阵M当前结点的列小于矩阵N当前结点的列
			{
				p = (OLink)malloc(sizeof(OLNode));//生成Q的结点
				if (!p)
					exit(MY_OVERFLOW);
				Q.tu++; //非零元个数＋1
				p->i = i; //赋值
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; //pm右移
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
			else if (pm->e + pn->e)//M,N当前结点的列相同并且两元素之和非零
			{
				p = (OLink)malloc(sizeof(OLNode));
				if (!p)
					exit(MY_OVERFLOW);
				Q.tu++;
				p->i = i;
				p->j = pn->j;
				p->e = pm->e + pn->e;
				p->right = NULL;
				pm = pm->right;//pm右移
				pn = pn->right;//pn右移
			}
			else//两元素相加为零
			{
				pm = pm->right;
				pn = pn->right;
				continue;
			}
			if (Q.rhead[i] == NULL)
				Q.rhead[i] = pq = p;
			else
			{
				pq->right = p;//完成行插入
				pq = pq->right;
			}
			if (Q.chead[p->j] == NULL)
				Q.chead[p->j] = col[p->j] = p;
			else
			{
				col[p->j]->down = p;//完成列插入
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm)//将矩阵M该行的剩余元素插入矩阵Q
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
		while (pn)//将矩阵N该行的剩余元素插入矩阵Q
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
			p->e = -p->e;//将非零元的值反号
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
		printf("你输入的两个距阵不能进行此操作\n");
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
		for (i = 0;i != Q.mu;i++)//初始化行
			Q.rhead[i] = NULL;
		for (i = 0;i != Q.nu;i++)//初始化列
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
						q0 = q0->down;//列后移
					else if (q0->i>p0->j)
						p0 = p0->right;//行后移
					else
					{
						e = e + p0->e*q0->e;//乘积累加
						q0 = q0->down;
						p0 = p0->right;//行列后移
					}
				}
				if (e)//e不为零则插入Q
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
	CrossList A, B, C;//声明三各矩阵
	int Select;
	cout << "请选择你需要的操作" << endl;
	cout << "1 加法" << endl;
	cout << "2 减法" << endl;
	cout << "3 乘法" << endl;
	cin >> Select;
	switch (Select)
	{
	case 1://稀疏矩阵相加
	{
		Create(A);
		Create(B);
		cout << "你输入的是" << endl;
		Print(A);
		cout << "加上" << endl;
		Print(B);
		Add(A, B, C);
		cout << "结果是" << endl;
		Print(C);
		break;
	}
	case 2://稀疏矩阵相减
	{
		Create(A);
		Create(B);
		cout << "你输入的是" << endl;
		Print(A);
		cout << "减去" << endl;
		Print(B);
		Negative(B);
		Add(A, B, C);
		cout << "结果是" << endl;
		Print(C);
		break;
	}
	case 3://稀疏矩阵相乘
	{
		Create(A);
		Create(B);
		cout << "你输入的是" << endl;
		Print(A);
		cout << "乘以" << endl;
		Print(B);
		Mult(A, B, C);
		cout << "结果是" << endl;
		Print(C);
		break;
	}
	}
	system("pause");
}