//复制含有随机指针节点的链表
//【题目】
//Node类中的value是节点值，next指针和正常单链表中next指针的意义一样，都指向下一个节点，rand指针是Node类中新增的指针，这个指针可
//能指向链表中的任意一个节点，也可能指向null。给定一个由Node节点类型组成的无环单链表的头节点head，请实现一个函数完成这个链表中
//所有结构的复制，并返回复制的新链表的头节点。进阶：不使用额外的数据结构，只用有限几个变量，且在时间复杂度为O(N)内完成原问题要
//实现的函数。

#include <unordered_map>

using namespace std;

typedef struct LNode
{
	int value;
	LNode* next;
	LNode* rand;
}LNode;

//链表初始化
LNode* CreateList()
{
	LNode *L = (LNode*)malloc(sizeof(LNode));
	LNode *p = L;
	LNode *r = L;
	int value;
	scanf("%d", &value);
	p->value = value;
	p->next = NULL;
	p->rand = NULL;//需初始化为NULL，不然访问出错
	for (int i = 0; i < 5; i++)
	{
		LNode *q = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &value);
		q->value = value;
		q->next = NULL;
		q->rand = NULL;
		p->next = q;
		p = p->next;
	}
	for (int i = 0; i < 5; i++)
	{
		if (i == 2)
			r->rand = r->next->next;
		if (i == 1)
			r->rand = r->next->next;
		r = r->next;	
	}
	return L;
}

//方法一:利用哈希表的概念建立映射关系
LNode* copyListWithRand1(LNode* head) 
{
	unordered_map<LNode*, LNode*> map;
	LNode* cur = head;
	while (cur != NULL) 
	{
		LNode* curcopy = (LNode*)malloc(sizeof(LNode));
		curcopy->value = cur->value;
		curcopy->next = NULL;
		curcopy->rand = NULL;
		map[cur] = curcopy;
		cur = cur->next;
	}
	cur = head;
	while (cur != NULL) {
		map[cur]->next = map[cur->next];
		map[cur]->rand = map[cur->rand];
		cur = cur->next;
	}
	return map[head];
}

//方法二:
//将每一个节点拷贝一个节点放在它的下一项，即拷贝节点为原节点next
//最后原链表和新链表进行分离
LNode* copyListWithRand2(LNode* head) {
	if (head == NULL) {
		return NULL;
	}

	LNode* cur = head;
	LNode* next = NULL;
	// 拷贝节点并放在原节点下一项
	while (cur != NULL) {
		next = cur->next;//保存下一节点，避免链表信息丢失
		LNode* curcopy = (LNode*)malloc(sizeof(LNode));
		curcopy->value = cur->value;
		curcopy->next = NULL;
		curcopy->rand = NULL;
		cur->next = curcopy;
		cur->next->next = next;
		cur = next;
	}

	cur = head;
	LNode* curCopy = NULL;
	//设置拷贝节点的rand指针
	while (cur != NULL) {
		next = cur->next->next;//保存下一节点，避免链表信息丢失
		curCopy = cur->next;
		curCopy->rand = cur->rand != NULL ? cur->rand->next : NULL;
		cur = next;
	}

	LNode* res = head->next;
	cur = head;
	// 链表分离过程
	while (cur != NULL) {
		next = cur->next->next;//保存下一节点，避免链表信息丢失
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next != NULL ? next->next :NULL;
		cur = next;
	}
	return res;
}

void printRandLinkedList(LNode* head) {
	LNode* cur = head;
	printf("order: ");
	while (cur != NULL) {
		printf("%d ",cur->value);
		cur = cur->next;
	}
	printf("\n");
	cur = head;
	printf("rand:  ");
	while (cur != NULL) 
	{
		if(cur->rand == NULL)
			printf("- ");
		else
			printf("%d ",cur->rand->value);
		cur = cur->next;
	}
	printf("\n");
}

void main() 
{
	LNode *head = CreateList();
	
	printRandLinkedList(head);
	LNode *res1 = copyListWithRand2(head);
	printRandLinkedList(res1);

	system("pause");

}
