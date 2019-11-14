//不能使用排序算法，利用桶排序中桶的概念进行求解

#include <iostream>
#include <algorithm>

using namespace std;

//确定数属于哪个桶
int bucket(long num, long len, long minNum, long maxNum)
{
	return (int)((num - minNum)*len / (maxNum - minNum));
}

//找到排序后相邻数的最大值(不能排序)
//借用桶的概念，但不进行桶排序
int findMaxGap(long nums[], int len)
{
	long maxNum=nums[0], minNum=nums[0];
	//找到数的最大值和最小值
	for (int i = 1; i < len; i++)
	{
		if (nums[i] > maxNum)
		{
			maxNum = nums[i];
		}		
		if (nums[i] < minNum)
			minNum = nums[i];
	}
	bool* hasNum = new bool[len + 1]();//标识桶内是否不为空桶//加()初始化为零
	long* maxs = new long[len + 1]();//标识桶内最大值
	long *mins = new long[len + 1]();//标识桶内最小值
	//遍历数组放入桶内的过程
	int bid = 0;
	for (int i = 0; i < len; i++)
	{
		bid = bucket(nums[i], len, minNum, maxNum);//确定放入的桶的位置
		mins[bid] = hasNum[bid]?min(mins[bid], nums[i]) : nums[i];
		maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
		hasNum[bid] = true;
	}
	//寻找最大差值过程
	long res = 0;
	long lastMax = maxs[0];
	for (int i = 1; i < len; i++)
	{
		if (hasNum[i])
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}
	return res;
}


void main()
{
	int n;
	cin >> n;
	long* nums = new long[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	if (nums == NULL || n < 2)
		cout << "length error" << endl;
	long res = findMaxGap(nums, n);
	delete[] nums;
}