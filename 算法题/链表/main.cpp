#include"listFunction.h"

int main(void)
{
	pair<Linklist, Linklist> L = CreateList(7);
	Linklist head = L.first, end = L.second;
	//quickSort(head->next, end->next);
	print(head);
	//int num = nodeNum(head);
	/*Linklist reverseHead = reverseList(head);
	print(reverseHead);*/
	//LNode* KthNode = findRKthNode(head, 3);
	/*LNode* midNode = findMidNode(head);*/
	//printReverse(head->next);
	//printReverse2(head);
	//pair<Linklist, Linklist> L1 = CreateList(3);
	//Linklist head1 = L1.first;
	//pair<Linklist, Linklist> L2 = CreateList(3);
	//Linklist head2 = L2.first;
	//Linklist mergeHead = mergeList(head1, head2);
	
	return 0;
}