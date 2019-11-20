//转圈打印矩阵
//【题目】
//给定一个整型矩阵matrix，请按照转圈的方式打印它。
//例如：
//1 2 3 4
//5 6 7 8
//9 10 11 12
//13 14 15 16
//打印结果为：1，2，3，4，8，12，16，15，14，13，9，5，6，7，11，
//10
//【要求】
//额外空间复杂度为O(1)。
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void printEdge(int** m, int row1, int col1, int row2, int col2,int colLength)
{
	if (row1 == row2)
		for (int i = col1; i < col2; i++)
			printf("%d ", *((int *)m + i));
	else if (col1 == col2)
		for (int i = row1; i < row2; i++)
			printf("%d ", *((int *)m + i*(col2 - col1 + 1)));
	else
	{
		int curC = col1;
		int curR = row1;
		while (curC != col2)
		{
			printf("%d ", *((int *)m + row1*colLength + curC));
			curC++;
		}
		while (curR != row2)
		{
			printf("%d ", *((int *)m + curR*colLength + col2));
			curR++;
		}
		while (curC != col1)
		{
			printf("%d ", *((int *)m + row2*colLength + curC));
			curC--;
		}
		while (curR != row1)
		{
			printf("%d ", *((int *)m + curR*colLength + col1));
			curR--;
		}
	}
}

void spiralOrderPrint(int** matrix,int rowLength,int colLength)
{
	int row1 = 0, col1 = 0, row2 = rowLength - 1, col2 = colLength - 1;
	while (row1 <= row2&&col1 <= col2)
		printEdge(matrix, row1++, col1++, row2--, col2--,colLength);
}

void main()
{
	int m[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int rowLength = 4;
	int colLength = 4;
	spiralOrderPrint((int **)m,rowLength,colLength);
	system("pause");
}