#pragma once
#include <iostream>
#include<queue>
#include<list>

typedef struct BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
}BinaryTreeNode, *BiTree;

using namespace std;

BiTree createbyNum(vector<int> arr);//利用数组构造二叉树
void Create(BiTree &T);
int GetNodeNum(BiTree T);//求二叉树中的结点个数
int GetDepth(BiTree T);//求二叉树的深度
void preOrder(BiTree T);//前序遍历
void inOrder(BiTree T);//中序遍历
void postOrder(BiTree T);//后序遍历				 
void levelOrder(BinaryTreeNode* T);//层遍历								   
void converttolist(BiTree T, BinaryTreeNode* &pFirstNode, BinaryTreeNode* &pLastNode);//二叉树变为有序的双向链表																			  
int getNthNode(BiTree T, int k);//求二叉树第k层的结点个数							
int maxSum(BiTree T);//算出途径最大的支路				 
int leafNum(BiTree T);//求叶子结点个数
bool structSame(BiTree T1, BiTree T2);//判断二叉树是否相同				  
bool isAVL(BiTree T, int &height);//判断二叉树是不是平衡二叉树
BiTree mirror(BiTree T);//求二叉树的镜像
BinaryTreeNode* getCommonParent(BiTree T, BinaryTreeNode* node1, BinaryTreeNode* node2);//求二叉树中两个节点的最低公共祖先节点_递归解法
BinaryTreeNode* getCommonParent2(BiTree T, int node1, int node2);//求二叉树中两个节点的最低公共祖先节点_非递归解法										 
pair<int, int> getMaxDistance(BiTree T);//求二叉树节点的最大距离				   
BinaryTreeNode *rebulidTree(int *preOrder, int*  pInOrder, int nodenum);//由前序遍历和中序遍历重建二叉树															
bool isComplete(BiTree T);//判断二叉树是否是完全二叉树
bool isPerfect(BiTree T);//判断是否为满二叉树