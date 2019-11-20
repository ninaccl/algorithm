#include"list_algorithm.h"

void main() {
	LNode* node1 = CreateList(5);
	LNode* node2 = CreateList(4);

	////打印链表
	printLinkedList(node1);
	printLinkedList(node2);

	printCommonPart(node1, node2);////打印公共部分
	system("pause");
}
