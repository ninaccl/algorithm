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
			stackList.pop();
			return false;
		}
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