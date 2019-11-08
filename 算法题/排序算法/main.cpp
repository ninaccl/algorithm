#include<iostream>
#include<ctime>

using namespace std;

void print(int a[],int len)
{
	for (int i = 0;i < len;i++)
		cout << a[i] << " ";
	cout << endl;
}

void maopao(int a[],int len)
{
	int temp;
	for (int i = len;i>0;i--)
	{
		for (int j = 0;j < i-1;j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void kuaipai(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin, right = end-1;
	int p = end;
	int temp;
	while (left < right)
	{
		while (left<right&&a[left]<a[p])
			left++;
		while (left < right&&a[right] > a[p])
			right--;
		if (left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	temp = a[left];
	a[left] = a[p];
	a[p] = temp;
	kuaipai(a,begin,left - 1);
	kuaipai(a,left+1,end);
}

void charu(int a[], int len)
{
	int temp,current;
	for (int i = 1;i < len;i++)
	{
		current = i;
		for (int j = i-1;j >= 0;j--)
		{
			if (a[j] > a[current])
			{
				temp = a[j];
				a[j] = a[current];
				a[current] = temp;
				current = j;
			}
			if (a[j] < a[current])
				break;
		}
	}
}

void xuanze(int a[], int len)
{
	int min,temp;
	for (int i = 0;i < len-1;i++)
	{
		min = i;
		for (int j = i+1;j < len;j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}	
	}		
}

int* generateRondomArray(int size, int rangeL, int rangeR)
{
	if (rangeL <= rangeR)
	{
		cout << "false range" << endl;
		return nullptr;
	}
	int *arr = new int[(int)(size+1)*rand()/double(RAND_MAX)];
	srand(time(NULL));//利用系统时间，设置随机种子
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}

void main()
{
	generateRondomArray(5,1,10);
	int a[] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	int len = sizeof(a) / sizeof(int);
	//maopao(a,len);
	//kuaipai(a, 0, len - 1);//传入的是首尾索引
	//charu(a, len);
	//xuanze(a, len);
	print(a, len);
	system("pause");
}