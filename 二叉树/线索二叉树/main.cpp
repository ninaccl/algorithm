#include<iostream>

using namespace std;

typedef struct BiThrNode
{
	int data;
	struct BiThrNode *lchild, *rchild;      /*���Һ���ָ��*/
	int LTag, RTag;             			    /*���ұ�־*/
}BiThrNode, *BiThrTree;

BiThrTree pre;

void CreateBiTree(BiThrTree &T)
{
	int ch;
	/*�������������������н���ֵ(һ���ַ�)���������������ʾ�Ķ�����T*/
	cin >> ch;
	if (ch == -1) T = NULL;
	else
	{
		T = new BiThrNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

/*�Խ��pΪ������������������*/
void InThreading(BiThrTree p)
{
	/*pre��ȫ�ֱ�������ʼ��ʱ���Һ���ָ��Ϊ�գ���������������㿪ʼ������*/
	if (p)
	{
		InThreading(p->lchild);            /*�������ݹ�������*/
		if (!(p->lchild))                      /*p������Ϊ��*/
		{
			p->LTag = 1;                     /*��p����������*/
			p->lchild = pre;                 /*p������ָ��ָ��pre(ǰ��)*/
		}
		else
		{
			p->LTag = 0;
		}
		if (!(pre->rchild))                  /*pre���Һ���Ϊ��*/
		{
			pre->RTag = 1;                  /*��pre����������*/
			pre->rchild = p;                /*pre���Һ���ָ��ָ��p(���)*/
		}
		else
		{
			pre->RTag = 0;
		}
		pre = p;                            /*����preָ��p��ǰ��*/
		InThreading(p->rchild);           /*�������ݹ�������*/
	}
}

/*��ͷ��������������*/
void InOrderThreading(BiThrTree &Thrt, BiThrTree T)
{
	/*�������������T��������������������Thrtָ��ͷ���*/
	Thrt = new BiThrNode;  		/*��ͷ��ͷ*/
	Thrt->LTag = 0;               /*ͷ��������ӣ������ǿգ���������Ϊ����*/
	Thrt->RTag = 1;               /*ͷ�����Һ���ָ��Ϊ������*/
	Thrt->rchild = Thrt;          /*��ʼ��ʱ��ָ��ָ���Լ�*/
	if (!T) Thrt->lchild = Thrt;   /*����Ϊ�գ�����ָ��Ҳָ���Լ�*/
	else
	{
		Thrt->lchild = T; pre = Thrt; /*ͷ��������ָ�����pre��ֵָ��ͷ���*/
		InThreading(T);          /*���������㷨������TΪ���Ķ�������������������*/
		pre->rchild = Thrt;        /*�㷨������preΪ���ҽ�㣬pre��������ָ��ͷ���*/
		pre->RTag = 1;
		Thrt->rchild = pre;        /*ͷ����������ָ��pre*/
	}
}

/*������������������*/ //NINA�������ԣ�ò��ֻ����������������ܳɹ�
void InOrderTraverse_Thr(BiThrTree T)
{
	/*Tָ��ͷ��㣬ͷ��������lchildָ������*/
	/*�����������������T�ķǵݹ��㷨����ÿ������Ԫ��ֱ�����*/
	BiThrTree p = T->lchild;    /*pָ������*/
	while (p != T)
	{
		while (p->LTag == 0)      /*����������*/
		{
			p = p->lchild;
		}
		cout << p->data << " ";           /*������������Ϊ�յĽ��*/
		while (p->RTag == 1 && p->rchild != T)  /*�����������ʺ�̽��*/
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
	cout << p->data;
}

int main()
{
	BiThrTree T;
	BiThrTree Thrt;
	cout << "Input the Threaded BinaryTree 's node:" << endl;
	CreateBiTree(T);
	InOrderThreading(Thrt, T); /*��ͷ��������������*/
	cout << "InOrderTraverse_Thr:" << endl;
	InOrderTraverse_Thr(T);   /*������������������*/
	return 0;
}
