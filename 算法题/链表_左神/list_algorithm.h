#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stack>
using namespace std;


typedef struct LNode {
	int data;
	LNode* next;
}LNode;



LNode* CreateList(int n);//链表初始化
void printLinkedList(LNode* node); //打印链表				   
void printCommonPart(LNode* head1, LNode* head2);//打印链表中的公共部分
//判断一个链表是否为回文结构
bool isPalindrome1(LNode* head);////利用堆栈的先进后出将原链表反转存入栈中，之后和原链表进行比较
bool isPalindrome2(LNode* head);////利用快慢指针的概念，慢指针走到中点后停止，反转链表的后半部分存入堆栈之中，之后和原链表前半部分进行比较
bool isPalindrome3(LNode* head);//反转后半部分链表,从前和后分别逼近中点进行比较