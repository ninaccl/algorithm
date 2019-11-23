//两个单链表相交的一系列问题
//【题目】
//在本题中，单链表可能有环，也可能无环。给定两个单链表的头节点head1和head2，这两个链表可能相交，也可能不相交。请实现一个函数，
//如果两个链表相交，请返回相交的第一个节点；如果不相交，返回null即可。
//要求：如果链表1的长度为N，链表2的长度为M，时间复杂度请达到O(N + M)，额外空间复杂度请达到O(1)。

#include<stdlib.h>

typedef struct LNode
{
	int value;
	LNode *next;
}LNode;

LNode* getIntersectNode(LNode* head1, LNode* head2);//找到相交节点
//思路：
//1.找到链表的第一个入环节点(无环返回NULL)
LNode* getLoopNode(LNode* head);
//2.查看两个链表的交点
//a.都有环
LNode* bothLoop(LNode* head1, LNode* loop1, LNode* head2, LNode* loop2);
//b.都无环
LNode* noLoop(LNode* head1, LNode* head2);
//c.一个有环一个无环，不存在相交可能



LNode* getIntersectNode(LNode* head1, LNode* head2) 
{
	if (head1 == NULL || head2 == NULL) 
	{
		return NULL;
	}
	LNode* loop1 = getLoopNode(head1);
	LNode* loop2 = getLoopNode(head2);
	if (loop1 == NULL && loop2 == NULL) 
	{
		return noLoop(head1, head2);
	}
	if (loop1 != NULL && loop2 != NULL) 
	{
		return bothLoop(head1, loop1, head2, loop2);
	}
	return NULL;
}

//找到第一个环节点
LNode* getLoopNode(LNode* head) 
{
	if (head == NULL || head->next == NULL || head->next->next == NULL) 
	{
		return NULL;
	}
	LNode* n1 = head->next; // n1 -> 慢指针
	LNode* n2 = head->next->next; // n2 -> 快指针

	//快慢指针相遇时停止
	while (n1 != n2) 
	{
		if (n2->next == NULL || n2->next->next == NULL) 
		{
			return NULL;//有环的话不可能出现NULL
		}
		n2 = n2->next->next;
		n1 = n1->next;
	}

	// n2从头节点开始走,n1从当前位置开始走，相遇外置即环的开始节点
	n2 = head; 
	while (n1 != n2) 
	{
		n1 = n1->next;
		n2 = n2->next;
	}

	return n1;
}

//两个链表都无环的情况
LNode* noLoop(LNode* head1, LNode* head2) 
{
	if (head1 == NULL || head2 == NULL) 
	{
		return NULL;
	}
	LNode* cur1 = head1;
	LNode* cur2 = head2;

	int n = 0;//记录两链长度差值
	while (cur1->next != NULL) 
	{
		n++;
		cur1 = cur1->next;
	}
	while (cur2->next != NULL) 
	{
		n--;
		cur2 = cur2->next;
	}

	//如果尾节点不相等，两个链表不可能相交
	if (cur1 != cur2) 
	{
		return NULL;
	}

	//长度多的链表指针先走几步，定位到与另一链表长度相同
	cur1 = n > 0 ? head1 : head2;
	cur2 = cur1 == head1 ? head2 : head1;
	n = abs(n);
	while (n != 0) 
	{
		n--;
		cur1 = cur1->next;
	}
	
	//两链表定位到剩余长度一样时，一起往尾节点走，找到第一个相同的节点
	while (cur1 != cur2) {
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

//两个链表都有环的情况
LNode* bothLoop(LNode* head1, LNode* loop1, LNode* head2, LNode* loop2) {
	LNode* cur1 = NULL;
	LNode* cur2 = NULL;

	//两链表的环起点相交，将环去除后等同于无环情况
	if (loop1 == loop2) 
	{
		cur1 = head1;
		cur2 = head2;
		int n = 0;
		while (cur1 != loop1) 
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2 != loop2) {
			n--;
			cur2 = cur2->next;
		}
		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		n = abs(n);
		while (n != 0) {
			n--;
			cur1 = cur1->next;
		}
		while (cur1 != cur2) {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	//环起点不相交，从其中一个起点遍历，查看是否能遍历到另一个环起点；遍历不到，则不相交
	else 
	{
		cur1 = loop1->next;
		while (cur1 != loop1) 
		{
			if (cur1 == loop2) 
			{
				return loop1;
			}
			cur1 = cur1->next;
		}
		return NULL;
	}
}

void main() 
{
	LNode* head1, *head2;
	getIntersectNode(head1, head2);
}
