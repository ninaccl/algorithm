#pragma once
#include<malloc.h>
#include<iostream>
#include<utility>
#include<stack>

using namespace std;

typedef struct LNode
{
	int data;
	LNode *next;
}LNode, *Linklist;


pair<Linklist, Linklist> CreateList(int n);//�����ʼ��				   
void quickSort(Linklist head, Linklist end);//�������
void print(Linklist head);//�������
int nodeNum(Linklist head);//������ڵ���Ŀ
Linklist reverseList(Linklist head);//��ת����
LNode* findRKthNode(Linklist head, unsigned int k);//���ҵ�����k���ڵ�
LNode* findMidNode(Linklist head);//�����м�ڵ�
void printReverse(Linklist head);//�����ӡ����
void printReverse2(Linklist head); //�����ӡ����-��ջ
Linklist mergeList(Linklist p1, Linklist p2);//�ϲ�������������//�������õݹ�ķ�ʽ���
bool hasCircle(Linklist p);//�жϵ������Ƿ��л�
bool isInter(Linklist p1, Linklist p2);//�ж������������Ƿ��ཻ
Linklist getFirstInter(Linklist p1, Linklist p2);//�������������ཻ�ĵ�һ���ڵ�
LNode* findFirstNodeInCircle(Linklist head);//��֪һ���������д��ڻ�������뻷�еĵ�һ���ڵ�
