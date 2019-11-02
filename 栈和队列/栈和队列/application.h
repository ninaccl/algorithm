#pragma once
#include "stack.h"
#include<stdio.h>

//走迷宫的元素类型
typedef struct
{
	int ord;//通道块在路径上的序号
	Postype seat;//通道块在迷宫中的坐标位置
	int di;//通道块走向下一通道块的方向
}SElemType;

void conversion();
void LineEdit();