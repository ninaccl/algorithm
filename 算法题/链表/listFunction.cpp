#include"listFunction.h"

//链表初始化
pair<Linklist, Linklist> CreateList(int n)
{
	LNode *L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *q = L;
	for (int i = 0;i < n;i++)
	{
		LNode *p = (LNode*)malloc(sizeof(LNode));
		p->next = NULL;
		int data;
		cin >> data;
		p->data = data;
		q->next = p;
		q = q->next;
	}
	return pair<Linklist, Linklist>(L, q);
}

//链表快排
void quickSort(Linklist head, Linklist end)
{
	if (head == NULL || head == end)
		return;
	Linklist p = head->next;
	Linklist small = head;
	int temp;
	while (p != end)
	{
		if (p->data < head->data)
		{
			small = small->next;
			temp = p->data;
			p->data = small->data;
			small->data = temp;
		}
		p = p->next;
	}
	temp = head->data;
	head->data = small->data;
	small->data = temp;
	quickSort(head, small);
	quickSort(small->next, end);
}

//链表输出
void print(Linklist head)
{
	Linklist p = head;
	p = p->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

//单链表节点数目
int nodeNum(Linklist head)
{
	if (head == NULL)
		return 0;
	Linklist p = head;
	int res = 0;
	while (p != NULL)
	{
		res++;
		p = p->next;
	}
	return res;
}

//反转链表
Linklist reverseList(Linklist head)
{
	if (head == NULL)
		return NULL;
	Linklist p = head;
	p = p->next;
	Linklist reverseHead = NULL;
	while (p != NULL)
	{
		Linklist q = p;
		p = p->next;
		q->next = reverseHead;
		reverseHead = q;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = reverseHead;
	reverseHead = s;
	return reverseHead;
}

//查找倒数第k个节点
LNode* findRKthNode(Linklist head, unsigned int k)
{
	if (head == NULL || k == 0)
		return NULL;
	Linklist p = head->next;
	Linklist p1,p2;
	p1 = p2 = p;
	int num = 1;
	while (k > 1 && p1!=NULL)
	{
		p1 = p1->next;
		k--;
	}
	if (k > 1|| p1 == NULL)
		return NULL;
	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

//查找中间节点
LNode* findMidNode(Linklist head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	LNode* low, *fast;
	low = fast = head;
	while (fast->next != NULL)
	{
		fast = fast->next;
		low = low->next;
		if (fast->next != NULL)
			fast = fast->next;
	}
	return low;
}

//反向打印链表-递归
void printReverse(Linklist head)
{
	if (head == NULL)
		return;
	printReverse(head->next);
	cout << head->data << endl;;
	return;
}

//反向打印链表-堆栈
void printReverse2(Linklist head)
{
	if (head == NULL)
		return;
	Linklist p = head->next;
	stack<LNode*> s;
	while (p != NULL)
	{
		s.push(p);
		p = p->next;
	}
	while (!s.empty())
	{
		cout << s.top()->data << endl;
		s.pop();
	}
}

//合并两个有序链表
Linklist mergeList(Linklist p1, Linklist p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	LNode *mergeHead = (LNode*)malloc(sizeof(LNode));
	LNode *p = mergeHead;
	p1 = p1->next;
	p2 = p2->next;
	while (p1 != NULL&&p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p->next = p1;
			p1 = p1->next;
		}
		else
		{
			p->next = p2;
			p2 = p2->next;
		}
		p = p->next;
	}
	if (p1 != NULL)
	{
		p->next = p1;
	}
	else
		p->next = p2;
	return mergeHead;
}

//判断单链表是否有环
bool hasCircle(Linklist p)
{
	Linklist low = p, fast = p;
	while (fast!= NULL&&fast->next != NULL)
	{
		low = low->next;
		fast = fast->next->next;
		if (low == fast)
			return true;
	}
	return false;
}

//判断两个单链表是否相交(单链表相交尾必相同)
bool isInter(Linklist p1, Linklist p2)
{
	if (p1 == NULL || p2 == NULL)
		return false;
	Linklist c1 = p1,c2=p2;
	while (c1->next != NULL)
		c1 = c1->next;
	while (c2->next != NULL)
		c2 = c2->next;
	return c1 == c2;
}

//求两个单链表相交的第一个节点
LNode* getFirstInter(Linklist p1, Linklist p2)
{
	if (p1 == NULL || p2 == NULL)
		return NULL;
	int len1 = 1,len2 = 1;
	Linklist c1 = p1, c2 = p2;
	while (c1->next != NULL)
	{
		c1 = c1->next;
		len1++;
	}	
	while (c2->next != NULL)
	{
		c2 = c2->next;
		len2++;
	}
	if (c1 != c2)
		return NULL;
	Linklist traverse1 = p1, traverse2 = p2;
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
			traverse1 = traverse1->next;
	}
	else
	{
		int k = len2 - len1;
		while (k--)
			traverse2 = traverse2->next;
	}
	while (traverse1 != traverse2)
	{
		traverse1++;
		traverse2++;
	}
	return traverse1;
}

//已知一个单链表中存在环，求进入环中的第一个节点
//onenote上记录了更加简洁的解法：即两指针交点到环入口的距离为从链表头到环入口的距离
LNode* findFirstNodeInCircle(Linklist p)
{
	//找环中的节点
	if (p == NULL || p->next == NULL)
		return false;
	LNode* fast = p;
	LNode* slow = p;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	//将环断开求两个单链表的相交节点
	Linklist list1head, list2head;
	LNode *assumedTail = slow;
	list1head = p;
	list2head = slow->next;
	
	Linklist l1, l2;
	int len1 = 1;
	l1 = list1head;
	while (l1 != assumedTail)
	{
		l1 = l1->next;
		len1++;
	}
	int len2 = 1;
	l2 = list2head;
	while (l2 != assumedTail)
	{
		l2 = l2->next;
		len2++;
	}
	
	l1 = list1head;
	l2 = list2head;
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
			l1 = l1->next;
	}
	else
	{
		int k = len2 - len1;
		while (k--)
			l2 = l2->next;
	}
	while (l1 != l2)
	{
		l1 = l1->next;
		l2 = l2->next;
	}
	return l1;
}
