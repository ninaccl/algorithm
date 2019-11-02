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


pair<Linklist, Linklist> CreateList(int n);//链表初始化				   
void quickSort(Linklist head, Linklist end);//链表快排
void print(Linklist head);//链表输出
int nodeNum(Linklist head);//单链表节点数目
Linklist reverseList(Linklist head);//反转链表
LNode* findRKthNode(Linklist head, unsigned int k);//查找倒数第k个节点
LNode* findMidNode(Linklist head);//查找中间节点
void printReverse(Linklist head);//反向打印链表
void printReverse2(Linklist head); //反向打印链表-堆栈
Linklist mergeList(Linklist p1, Linklist p2);//合并两个有序链表//还可以用递归的方式解决
bool hasCircle(Linklist p);//判断单链表是否有环
bool isInter(Linklist p1, Linklist p2);//判断两个单链表是否相交
Linklist getFirstInter(Linklist p1, Linklist p2);//求两个单链表相交的第一个节点
LNode* findFirstNodeInCircle(Linklist head);//已知一个单链表中存在环，求进入环中的第一个节点
