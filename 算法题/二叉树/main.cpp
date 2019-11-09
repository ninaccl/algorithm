#include "treeFunction.h"

int main(void)
{
	BiTree T;
	/*vector<int> arr = { 17,0,-4,3,15 };
	T = createbyNum(arr);*/
	Create(T);
	//int nodenum,depth;
	//nodenum=GetNodeNum(T);
	//depth = GetDepth(T);
	//preOrder(T);
	//inOrder(T);
	//postOrder(T);
	//levelOrder(T);
	//int NthNum = getNthNode(T, 3);
	//int maxSumValue = maxSum(T);
	//int leaf = leafNum(T);
	BinaryTreeNode* pFirstNode=nullptr, *pLastNode=nullptr;
	converttolist(T,pFirstNode,pLastNode);
	/*int height = 0;
	bool AVL=isAVL(T,height);
	BiTree Tmirror = mirror(T);*/
	//std::list<BinaryTreeNode*> path;
	//getPath(T, 16, path);
	//BinaryTreeNode* commonParent;
	//commonParent = getCommonParent2(T, 16, 13);
	//int maxL, maxR;
	//pair<int,int> res;
	//res=getMaxDistance(T);
	/*int preOrder[] = { 17,3,2,-10,16,1,13 };
	int inOrder[] = { 2,3,17,16,-10,13,1 };
	rebulidTree(preOrder, inOrder, 7);*/
	//bool res = isComplete(T);
	bool res = isPerfect(T);
	return 0;
}
