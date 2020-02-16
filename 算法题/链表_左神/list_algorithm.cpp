#include "list_algorithm.h"

//链表初始化
LNode* CreateList(int n)
{
	LNode *L = (LNode*)malloc(sizeof(LNode));
	LNode *p = L;
	int data;
	scanf("%d", &data);
	p->data = data;
	for (int i = 0; i < n - 1; i++)
	{
		LNode *q = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &data);
		q->data = data;
		q->next = NULL;
		p->next = q;
		p = p->next;
	}
	return L;
}



//打印链表
void printLinkedList(LNode* node)
{
	printf("Linked List: ");
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}



//打印公共部分
void printCommonPart(LNode* head1, LNode* head2) 
{
	printf("Common Part: ");
	while (head1 != NULL && head2 != NULL) {
		if (head1->data < head2->data) {
			head1 = head1->next;
		}
		else if (head1->data > head2->data) {
			head2 = head2->next;
		}
		else {
			printf("%d ", head1->data);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}

//判断一个链表是否为回文结构
//【题目】
//给定一个链表的头节点head，请判断该链表是否为回文结构。
//例如：
//1->2->1，返回true。
//1->2->2->1，返回true。
//15->6->15，返回true。
//1->2->3，返回false。
//进阶：
//如果链表长度为N，时间复杂度达到O(N)，额外空间复杂度达到O(1)。


// need n extra space
//利用堆栈的先进后出将原链表反转存入栈中，之后和原链表进行比较
bool isPalindrome1(LNode* head) {
	stack<LNode*> stackList;
	LNode* cur = head;
	while (cur != NULL) {
		stackList.push(cur);
		cur = cur->next;
	}
	while (head != NULL) {
		if (head->data != stackList.top()->data) {
			return false;
		}
		stackList.pop();
		head = head->next;
	}
	return true;
}

// need n/2 extra space
//利用快慢指针的概念，慢指针走到中点后停止，反转链表的后半部分存入堆栈之中，之后和原链表前半部分进行比较
bool isPalindrome2(LNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	LNode* right = head->next;
	LNode* cur = head;
	while (cur->next != NULL && cur->next->next != NULL) {
		right = right->next;
		cur = cur->next->next;
	}
	stack<LNode*> stackList;
	while (right != NULL) {
		stackList.push(right);
		right = right->next;
	}
	while (!stackList.empty()) {
		if (head->data != stackList.top()->data) {
			return false;
		}
		stackList.pop();
		head = head->next;
	}
	return true;
}

// need O(1) extra space
//反转后半部分链表,从前和后分别逼近中点进行比较
bool isPalindrome3(LNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	LNode* slow = head;
	LNode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL) { // find mid node
		slow = slow->next; // slow -> mid
		fast = fast->next->next; // fast -> end
	}
	LNode* rest = slow->next; // rest is right part first node
	slow->next = NULL; // mid.next -> null
	LNode* n3 = NULL;
	while (rest != NULL) { // right part convert
		n3 = rest->next; // n3 -> save next node
		rest->next = slow; // next of right node convert
		slow = rest; // slow move
		rest = n3; // rest move
	}
	n3 = slow; // n3 -> save last node
	fast = head;// fast -> save first node
	bool res = true;
	while (slow != NULL && fast != NULL) { // check palindrome
		if (slow->data != fast->data) {
			res = false;
			break;
		}
		slow = slow->next; // left to mid
		fast = fast->next; // right to mid
	}
	slow = n3->next;
	n3->next = NULL;
	while (slow != NULL) { // recover list
		fast = slow->next;
		slow->next = n3;
		n3 = slow;
		slow = fast;
	}
	return res;
}



//将单向链表按某值划分成左边小、中间相等、右边大的形式
//【题目】
//给定一个单向链表的头节点head，节点的值类型是整型，再给定一个整数pivot。实现一个调整链表的函数，将链表调整为左部分都是值小于
//pivot的节点，中间部分都是值等于pivot的节点，右部分都是值大于pivot的节点。除这个要求外，对调整后的节点顺序没有更多的要求。
//例如：链表9->0->4->5->1，pivot = 3。
//调整后链表可以是1->0->4->9->5，也可以是0->1->9->5->4。总之，满足左部分都是小于3的节点，中间部分都是等于3的节点（本例中这个部
//分为空），右部分都是大于3的节点即可。对某部分内部的节点顺序不做要求。


//方法一：利用快排的单步思想进行求解
LNode* listPartition1(LNode* head, int pivot)
{
	if (head == NULL) 
		return head;

	LNode* cur = head;
	int length = 0;

	//计算长度
	while (cur != NULL) 
	{
		length++;
		cur = cur->next;
	}

	//将原链表放入数组中
	LNode** nodeArr = new LNode*[length];
	int i = 0;
	cur = head;
	for (i = 0; i != length; i++) 
	{
		nodeArr[i] = cur;
		cur = cur->next;
	}

	arrPartition(nodeArr,length, pivot);//partition过程

	//数组拷贝回链表
	for (i = 1; i != length; i++) {
		nodeArr[i - 1]->next = nodeArr[i];
	}
	nodeArr[i - 1]->next = NULL;

	return nodeArr[0];
}

//partition过程
//可参照排序算法中的快排partition过程
void arrPartition(LNode** nodeArr,int length, int pivot) 
{
	int small = -1;
	int big = length;
	int index = 0;
	while (index != big) {
		if (nodeArr[index]->data < pivot) {
			swap(nodeArr, ++small, index++);
		}
		else if (nodeArr[index]->data == pivot) {
			index++;
		}
		else {
			swap(nodeArr, --big, index);
		}
	}
}

//交换
void swap(LNode* nodeArr[], int a, int b) {
	LNode* tmp = nodeArr[a];
	nodeArr[a] = nodeArr[b];
	nodeArr[b] = tmp;
}


//方法二：遍历寻找小于，等于和大于的部分
LNode* listPartition2(LNode* head, int pivot) 
{
	LNode* sH = NULL; // small head
	LNode* sT = NULL; // small tail
	LNode* eH = NULL; // equal head
	LNode* eT = NULL; // equal tail
	LNode* bH = NULL; // big head
	LNode* bT = NULL; // big tail
	LNode* next = NULL; // 保存下一个节点

	//节点遍历分配过程
	while (head != NULL) 
	{
		next = head->next;//保存下一个节点
		head->next = NULL;//链表断开
		if (head->data < pivot) 
		{
			if (sH == NULL) 
			{
				sH = head;
				sT = head;
			}
			else 
			{
				sT->next = head;
				sT = head;
			}
		}
		else if (head->data == pivot) 
		{
			if (eH == NULL) 
			{
				eH = head;
				eT = head;
			}
			else 
			{
				eT->next = head;
				eT = head;
			}
		}
		else 
		{
			if (bH == NULL) 
			{
				bH = head;
				bT = head;
			}
			else 
			{
				bT->next = head;
				bT = head;
			}
		}
		head = next;//遍历下一个节点
	}

	// 连接过程
	//小于等于部分
	if (sT != NULL) 
	{
		sT->next = eH;
		eT = eT == NULL ? sT : eT;
	}
	//等于大于部分
	if (eT != NULL) 
		eT->next = bH;

	return sH != NULL ? sH : eH != NULL ? eH : bH;
}

