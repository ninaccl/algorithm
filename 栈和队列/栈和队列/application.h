#pragma once
#include "stack.h"
#include<stdio.h>

//���Թ���Ԫ������
typedef struct
{
	int ord;//ͨ������·���ϵ����
	Postype seat;//ͨ�������Թ��е�����λ��
	int di;//ͨ����������һͨ����ķ���
}SElemType;

void conversion();
void LineEdit();