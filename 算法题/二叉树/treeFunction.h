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

BiTree createbyNum(vector<int> arr);//�������鹹�������
void Create(BiTree &T);
int GetNodeNum(BiTree T);//��������еĽ�����
int GetDepth(BiTree T);//������������
void preOrder(BiTree T);//ǰ�����
void inOrder(BiTree T);//�������
void postOrder(BiTree T);//�������				 
void levelOrder(BinaryTreeNode* T);//�����								   
void converttolist(BiTree T, BinaryTreeNode* &pFirstNode, BinaryTreeNode* &pLastNode);//��������Ϊ�����˫������																			  
int getNthNode(BiTree T, int k);//���������k��Ľ�����							
int maxSum(BiTree T);//���;������֧·				 
int leafNum(BiTree T);//��Ҷ�ӽ�����
bool structSame(BiTree T1, BiTree T2);//�ж϶������Ƿ���ͬ				  
bool isAVL(BiTree T, int &height);//�ж϶������ǲ���ƽ�������
BiTree mirror(BiTree T);//��������ľ���
BinaryTreeNode* getCommonParent(BiTree T, BinaryTreeNode* node1, BinaryTreeNode* node2);//��������������ڵ����͹������Ƚڵ�_�ݹ�ⷨ
BinaryTreeNode* getCommonParent2(BiTree T, int node1, int node2);//��������������ڵ����͹������Ƚڵ�_�ǵݹ�ⷨ										 
pair<int, int> getMaxDistance(BiTree T);//��������ڵ��������				   
BinaryTreeNode *rebulidTree(int *preOrder, int*  pInOrder, int nodenum);//��ǰ���������������ؽ�������															
bool isComplete(BiTree T);//�ж϶������Ƿ�����ȫ������
bool isPerfect(BiTree T);//�ж��Ƿ�Ϊ��������