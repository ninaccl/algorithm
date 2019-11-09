#include "treeFunction.h"

using namespace std;

//利用数组构造二叉树
BiTree createbyNum(vector<int> arr)
{
	std::queue<BinaryTreeNode**> deck; //为了传引用
	BinaryTreeNode *root;
	deck.push(&root);
	for (int i = 0;i < arr.size();i++)
	{
		BinaryTreeNode **next = deck.front();
		*next = new BinaryTreeNode;
		(*next)->data = arr[i];
		deck.push(&(*next)->left);
		deck.push(&(*next)->right);
		deck.pop();
	}
	return arr.size() == 0 ? NULL : root;
}

void Create(BiTree &T)
{
	int ch;
	cin >> ch;
	if (ch == -1)
		T = NULL;
	else
	{
		T = new BinaryTreeNode;
		T->data = ch;
		Create(T->left);
		Create(T->right);
	}
}

//求二叉树中的结点个数
int GetNodeNum(BiTree T)
{
	if (T == NULL)
		return 0;
	else
		return GetNodeNum(T->left) + GetNodeNum(T->right) + 1;
}

//求二叉树的深度
int GetDepth(BiTree T)
{
	if (T == NULL)
		return 0;
	int depthL = GetDepth(T->left);
	int depthR = GetDepth(T->right);
	int depth = depthL > depthR ? (depthL + 1) : (depthR + 1);
	return depth;
}

//前序遍历
void preOrder(BiTree T)
{
	if (T == NULL)
		return;
	cout << T->data << endl;
	preOrder(T->left);
	preOrder(T->right);
}

//中序遍历
void inOrder(BiTree T)
{
	if (T == NULL)
		return;
	inOrder(T->left);
	cout << T->data << endl;
	inOrder(T->right);
}

//后序遍历
void postOrder(BiTree T)
{
	if (T == NULL)
		return;
	postOrder(T->left);
	postOrder(T->right);
	cout << T->data << endl;
}

//层遍历
void levelOrder(BinaryTreeNode* T)
{
	if (T == NULL)
		return;
	queue<BinaryTreeNode*> q;
	q.push(T);
	while (!q.empty())
	{
		BinaryTreeNode* s = q.front();
		q.pop();
		cout << s->data << endl;
		if (s->left != NULL)
			q.push(s->left);
		if (s->right != NULL)
			q.push(s->right);
	}
	return;
}

//二叉树变为有序的双向链表
void converttolist(BiTree T, BinaryTreeNode* &pFirstNode, BinaryTreeNode* &pLastNode)
{
	BinaryTreeNode* firstL = nullptr, *lastL = nullptr, *firstR = nullptr, *lastR = nullptr;
	if (T == nullptr)
	{
		pFirstNode = nullptr;
		pLastNode = nullptr;
		return;
	}
	if (T->left == NULL)
	{
		pFirstNode = T;
	}
	else
	{
		converttolist(T->left, firstL, lastL);
		pFirstNode = firstL;
		T->left = lastL;
		lastL->right = T;
	}
	if (T->right == NULL)
	{
		pLastNode = T;
	}
	else
	{
		converttolist(T->right, firstR, lastR);
		pLastNode = lastR;
		T->right = firstR;
		firstR->left = T;
	}
	return;
}

//求二叉树第k层的结点个数
int getNthNode(BiTree T, int k)
{
	if (T == nullptr || k < 1)
		return 0;
	if (k == 1)
		return 1;
	int numLeft = getNthNode(T->left, k - 1);
	int numRight = getNthNode(T->right, k - 1);
	return numLeft + numRight;
}

//算出途径最大的支路
int maxSum(BiTree T)
{
	if (T == nullptr)
		return 0;
	int maxL = maxSum(T->left) + T->data;
	int maxR = maxSum(T->right) + T->data;
	int max = maxL > maxR ? maxL : maxR;
	return max;
}

//求叶子结点个数
int leafNum(BiTree T)
{
	if (T == nullptr)
		return 0;
	if (T->left == nullptr&&T->right == nullptr)
		return 1;
	int numL = leafNum(T->left);
	int numR = leafNum(T->right);
	return numL + numR;
}

//判断二叉树是否相同
bool structSame(BiTree T1, BiTree T2)
{
	if (T1 == nullptr&&T2 == nullptr)
		return true;
	else if (T1 == nullptr || T2 == nullptr)
		return false;
	bool resL = structSame(T1->left, T2->left);
	bool resR = structSame(T1->right, T2->right);
	return resL&&resR;
}

//判断二叉树是不是平衡二叉树
bool isAVL(BiTree T, int &height)
{
	if (T == nullptr)
	{
		height = 0;
		return true;
	}
	int heightL;
	bool avlL = isAVL(T->left, heightL);
	int heightR;
	bool avlR = isAVL(T->right, heightR);
	if (avlL&&avlR&&abs(heightL - heightR) <= 1)
	{
		height = max(heightL, heightR) + 1;
		return true;
	}
	else
	{
		height = max(heightL, heightR) + 1;
		return false;
	}
}

//求二叉树的镜像
BiTree mirror(BiTree T)
{
	if (T == nullptr)
		return NULL;
	BiTree Tleft = mirror(T->left);
	BiTree Tright = mirror(T->right);
	T->left = Tright;
	T->right = Tleft;
	return T;
}

//求二叉树中两个节点的最低公共祖先节点
//递归解法：
bool findNode(BinaryTreeNode * T, BinaryTreeNode * pNode) 
{ 
	if (T == NULL || pNode == NULL)		
		return false; 	
	if (T == pNode)		
		return true; 	
	bool found = findNode(T->left, pNode);	
	if (!found)		
		found = findNode(T->right, pNode); 	
	return found; 
}

//（1）如果两个节点分别在根节点的左子树和右子树，则返回根节点
//（2）如果两个节点都在左子树，则递归处理左子树；如果两个节点都在右子树，则递归处理右子树
BinaryTreeNode* getCommonParent(BiTree T, BinaryTreeNode* node1, BinaryTreeNode* node2)
{
	if (findNode(T->left, node1))
	{
		if (findNode(T->right, node2))
			return T;
		else
			return getCommonParent(T->left, node1, node2);
	}
	else
	{
		if (findNode(T->left, node2))
			return T;
		else
			return getCommonParent(T->right, node1, node2);
	}
}

//非递归解法
bool getPath(BiTree T, int node, list<BinaryTreeNode*> &path)
{
	if (T == nullptr)
		return false;
	if (T->data == node)
	{
		path.push_back(T);
		return true;
	}
	path.push_back(T);
	bool found = false;
	found = getPath(T->left, node, path);
	if (!found)
		found = getPath(T->right, node, path);
	if (!found)
		path.pop_back();
	return found;
}

BinaryTreeNode* getCommonParent2(BiTree T, int node1, int node2)
{
	if (T == nullptr)
		return NULL;
	list<BinaryTreeNode*>path1;
	bool result1 = getPath(T, node1, path1);
	list<BinaryTreeNode*>path2;
	bool result2 = getPath(T, node2, path2);
	if (!result1 || !result2)
		return false;
	BinaryTreeNode* plast = NULL;
	auto iter1 = path1.begin(), iter2 = path2.begin();
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
			plast = *iter1;
		else
			break;
		*iter1++;
		*iter2++;
	}
	return plast;
}

//求二叉树节点的最大距离
pair<int, int> getMaxDistance(BiTree T)
{
	if (T == NULL)
		return{ 0,0 };
	pair<int, int> resL, resR, res;
	if (T->left != NULL)
	{
		resL = getMaxDistance(T->left);
	}
	else
	{
		resL = { 0,0 };
	}
	if (T->right != NULL)
	{
		resR = getMaxDistance(T->right);
	}
	else
	{
		resR = { 0,0 };
	}
	res.first = resL.first > resR.first ? resL.first + 1 : resR.first + 1;//first放深度,second放距离
	res.second = (resL.first + resR.first + 1) > max(resL.second, resR.second) ? (resL.first + resR.first + 1) : max(resL.second, resR.second);
	return res;
}

//由前序遍历和中序遍历重建二叉树
BinaryTreeNode *rebulidTree(int *preOrder, int*  pInOrder, int nodenum)
{
	if (preOrder == NULL || pInOrder == NULL || nodenum <= 0)
		return NULL;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->data = preOrder[0];
	root->left = NULL;
	root->right = NULL;
	int rootLocation = -1;
	for (int i = 0;i < nodenum;i++)
	{
		if (pInOrder[i] == root->data)
		{
			rootLocation = i;
			break;
		}
	}
	if (rootLocation == -1)
	{
		throw std::exception("Invalid root");
	}
	root->left = rebulidTree(preOrder + 1, pInOrder, rootLocation);
	root->right = rebulidTree(preOrder + rootLocation + 1, pInOrder + rootLocation + 1, nodenum - rootLocation - 1);
	return root;
}

//判断二叉树是否是完全二叉树
bool isComplete(BiTree T)
{
	if (T == NULL)
		return false;
	queue<BinaryTreeNode*> q;
	q.push(T);
	bool musthavenoChild = false;
	bool result = true;
	while (!q.empty())
	{
		BinaryTreeNode* s = q.front();
		q.pop();
		if (musthavenoChild)
		{
			if (s->left != NULL || s->right != NULL)
			{
				result = false;
				break;
			}
		}
		else
		{
			if (s->left == NULL)
			{
				musthavenoChild = true;
				if (s->right != NULL)
				{
					result = false;
					break;
				}
			}
			else
			{
				if (s->right == NULL)
				{
					musthavenoChild = true;
					q.push(s->left);
				}
				else
				{
					q.push(s->left);
					q.push(s->right);
				}
			}
		}
	}
	return result;
}

//判断是否为满二叉树
bool isPerfect(BiTree T)
{
	if (T == NULL)
		return false;
	queue<BinaryTreeNode*> q;
	q.push(T);
	int n = 1;
	while (!q.empty())
	{
		BinaryTreeNode* s = q.front();
		q.pop();
		if (s != NULL)
		{
			q.push(s->left);
			q.push(s->right);
		}
		else if ((n&(n - 1)) == 0)
			return true;
		else
			return false;
		n++;
	}
	return true;
}