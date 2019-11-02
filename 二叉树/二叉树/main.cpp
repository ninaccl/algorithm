#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<process.h>
#include<stack>
#include<queue>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

bool CreateBiTree(BiTree &T)
{
	//按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树
	//构造二叉链表表示的二叉树T
	int ch;
	scanf_s("%d",&ch);
	if (ch == -1)
		T = NULL;
	else
	{
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return true;
}

bool Visit(int e)
{
	printf("%d",e);
	return true;
}

bool PreOrderTraverse(BiTree T, bool(*Visit)(int e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return true;
		return false;
	}
	else
		return true;
}

bool InOrderTraverese(BiTree T, bool(*visit)(int e))
{
	if (T)
	{
		InOrderTraverese(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverese(T->rchild, Visit);
	}
	return true;
}

bool PostTraverse(BiTree T, bool(*visit)(int e))
{
	if (T)
	{
		PostTraverse(T->lchild, Visit);
		PostTraverse(T->rchild, Visit);
		Visit(T->data);
	}
	return true;
}

void LevelOrder(BiTree T) 
{
	std::queue<BiTNode> q;//借助队列	
	if (T != NULL)	
	{		
		BiTNode temp;//暂存要出队的结点		
		q.push(*T);//根结点入队		
		while (!q.empty())//队列非空		
		{			
			temp = q.front();			
			q.pop();			
			printf("%d ", temp.data);			
			if (temp.lchild != NULL) 
				q.push(*temp.lchild);//队列先进先出，先入左孩子			
			if (temp.rchild != NULL) 
				q.push(*temp.rchild);		
		}	
	}
}

//数据结构-严——书本参考做法
//bool InOrderTraverse1(BiTree T, bool(*visit)(int e))
//{
//	std::stack<BiTree> S;
//	BiTree p;
//	S.push(T);
//	while (!S.empty())
//	{
//		while ((p=S.top())&&p)
//		{
//			S.push(p->lchild);
//		}
//		S.pop();
//		if (!S.empty())
//		{
//			S.pop();
//			if (!Visit(p->data))
//				return false;
//			S.push(p->rchild);
//		}
//	}
//	return true;
//}

void main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T,Visit);
	InOrderTraverese(T, Visit);
	PostTraverse(T, Visit);
	LevelOrder(T);
	system("pause");
}