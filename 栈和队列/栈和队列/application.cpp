#include "application.h"

//数制转换-十进制转八进制
void conversion()
{
	SqStack S;
	int N,e;
	Init(S);
	scanf_s("%d", &N);
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	while (S.base != S.top)
	{
		pop(S, e);
		printf("%d", e);
	}
}

//行编辑程序-退格符#退行符@
//需要注意stack.cpp的栈数据是为int型的，这里用的是char型，类型需要自己修改
void LineEdit()
{
	//利用字符栈S，从终端接收一行并传送至调用过程的数据区
	SqStack S;
	Init(S);
	char ch = getchar();
	char c;
	while (ch != EOF)
	{
		while (ch != EOF&&ch != '\n')
		{
			switch (ch)
				{
			case '#':pop(S, c);
			case '@':Clear(S);
			default:
				Push(S,ch);
			}
			ch = getchar();
		}
		//将栈内字符传送至调用过程的数据区
		Clear(S);
		if (ch != EOF)
			ch = getchar();
	}
	DestroyStack(S);
}

//走迷宫-返回成功通道
bool MazePath(MazeType maze, PosType start, PosType end)
{
	SqStack S;
	PosType curpos = start; //设定当前位置为初始位置
	Init(S);
	int curstep = 1;
	do
	{
		if (Pass(curpos))//当前位置可以通过，即是未遍历的块
		{
			FootPrint(curpos);//留下足迹，避免重复通过相同路径
			e = (curstep, curpos, 1);
			Push(S, e);
			if (curpos == end)
				return(true);
			curpos = NextPos(curpos, 1);//下一位置是当前位置的东邻
			curstep++;
		}
		else
		{
			if (!StackEmpty())
			{
				pop(S, e);
				while (e.di == 4 && !StackEmpty(S))//如果四个方向都遍历过，退回
				{
					MarkPrint(e.seat);//留下不能通过的标记
					pop(S, e);//退回
				}
				if (e.di < 4)
				{
					e.di++;
					Push(S, e);//换下一个方向探索
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
	}
	return false;
}

