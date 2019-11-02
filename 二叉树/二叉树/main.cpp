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
	//�������������������н���ֵ��һ���ַ������ո��ַ���ʾ����
	//������������ʾ�Ķ�����T
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
	std::queue<BiTNode> q;//��������	
	if (T != NULL)	
	{		
		BiTNode temp;//�ݴ�Ҫ���ӵĽ��		
		q.push(*T);//��������		
		while (!q.empty())//���зǿ�		
		{			
			temp = q.front();			
			q.pop();			
			printf("%d ", temp.data);			
			if (temp.lchild != NULL) 
				q.push(*temp.lchild);//�����Ƚ��ȳ�����������			
			if (temp.rchild != NULL) 
				q.push(*temp.rchild);		
		}	
	}
}

//���ݽṹ-�ϡ����鱾�ο�����
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