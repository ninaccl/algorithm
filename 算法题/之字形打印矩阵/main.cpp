//“之”字形打印矩阵
//【题目】
//给定一个矩阵matrix，按照“之”字形的方式打印这个矩阵，例如：
//1 2 3 4
//5 6 7 8
//9 10 11 12
//“之”字形打印的结果为：1，2，5，9，6，3，4，7，10，11，8，12
//【要求】
//额外空间复杂度为O(1)。
#include<stdio.h>
#include<stdlib.h>

using namespace std;

void printLevel(int **m, int row1, int col1, int row2, int col2,int colLength, bool fromUp)
{
	if(fromUp)//自上向下打印
		while (row1 <= row2)
		{
			printf("%d ", *((int *)m + row1*colLength + col1));
			row1++;
			col1--;
		}
	else//自下向上打印
	{
		while (row2 >= row1)
		{
			printf("%d ", *((int *)m + row2*colLength + col2));
			row2--;
			col2++;
		}
	}
}

void printMatrixZigZag(int **m,int rowLength,int colLength)
{
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
	int endR = rowLength - 1;
	int endC = colLength - 1;
	bool fromUp = false;
	while (row1 != endR + 1)
	{
		printLevel(m,row1,col1,row2,col2,colLength,fromUp);
		row1 = col1 == endC ? row1 + 1 : row1;
		col1 = col1 == endC ? col1 : col1 + 1;
		col2 = row2 == endR ? col2 + 1 : col2;
		row2 = row2 == endR ? row2 : row2 + 1;	
		fromUp = !fromUp;
	}
}

void main()
{
	int m[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int rowLength = 3, colLength = 4;
	printMatrixZigZag((int**)m, rowLength, colLength);
	system("pause");
}