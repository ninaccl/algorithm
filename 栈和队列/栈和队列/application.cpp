#include "application.h"

//����ת��-ʮ����ת�˽���
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

//�б༭����-�˸��#���з�@
//��Ҫע��stack.cpp��ջ������Ϊint�͵ģ������õ���char�ͣ�������Ҫ�Լ��޸�
void LineEdit()
{
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵�������
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
		//��ջ���ַ����������ù��̵�������
		Clear(S);
		if (ch != EOF)
			ch = getchar();
	}
	DestroyStack(S);
}

//���Թ�-���سɹ�ͨ��
bool MazePath(MazeType maze, PosType start, PosType end)
{
	SqStack S;
	PosType curpos = start; //�趨��ǰλ��Ϊ��ʼλ��
	Init(S);
	int curstep = 1;
	do
	{
		if (Pass(curpos))//��ǰλ�ÿ���ͨ��������δ�����Ŀ�
		{
			FootPrint(curpos);//�����㼣�������ظ�ͨ����ͬ·��
			e = (curstep, curpos, 1);
			Push(S, e);
			if (curpos == end)
				return(true);
			curpos = NextPos(curpos, 1);//��һλ���ǵ�ǰλ�õĶ���
			curstep++;
		}
		else
		{
			if (!StackEmpty())
			{
				pop(S, e);
				while (e.di == 4 && !StackEmpty(S))//����ĸ����򶼱��������˻�
				{
					MarkPrint(e.seat);//���²���ͨ���ı��
					pop(S, e);//�˻�
				}
				if (e.di < 4)
				{
					e.di++;
					Push(S, e);//����һ������̽��
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
	}
	return false;
}

