#include<iostream>
#include<ctime>

using namespace std;

void print(int a[], int len);//打印
void maopao(int a[], int len);//冒泡排序						  
void kuaipai(int a[], int begin, int end);//快速排序
void charu(int a[], int len);//插入排序
void xuanze(int a[], int len);//选择排序
void guibin(int arr[], int len);//归并排序
void guibinProcess(int arr[], int L, int R);//归并具体过程
void merge(int arr[], int L, int mid, int R);//归并后的连接
int* generateRondomArray(int size, int rangeL, int rangeR);//生成随机数列



void print(int a[],int len)
{
	for (int i = 0;i < len;i++)
		cout << a[i] << " ";
	cout << endl;
}

//冒泡排序
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

//快速排序
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

//插入排序
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

//选择排序
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

//归并排序
void guibin(int arr[], int len)
{
	if (arr == NULL || len < 2)
		return;
	guibinProcess(arr, 0, len - 1);
}

void guibinProcess(int arr[], int L, int R)
{
	if (L == R)
		return;
	int mid = L + ((R - L) >> 1); //L和R的中点位置
	guibinProcess(arr, L, mid);
	guibinProcess(arr, mid + 1, R);
	merge(arr, L, mid, R);
}

void merge(int arr[], int L, int mid, int R)
{
	int* res = new int[R - L + 1];
	int i = 0;
	int p1 = L, p2 = mid + 1;
	while (p1 <= mid && p2 <= R)
	{
		res[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid)
	{
		res[i++] = arr[p1++];
	}
	while (p2 <= R)
	{
		res[i++] = arr[p2++];
	}
	for (i = 0; i < R - L + 1; i++)
	{
		arr[L + i] = res[i];
	}
}

//生成随机数列
int* generateRondomArray(int size, int rangeL, int rangeR)
{
	if (rangeL > rangeR)
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
	guibin(a, len);
	//maopao(a,len);
	//kuaipai(a, 0, len - 1);//传入的是首尾索引
	//charu(a, len);
	//xuanze(a, len);
	print(a, len);
	system("pause");
}