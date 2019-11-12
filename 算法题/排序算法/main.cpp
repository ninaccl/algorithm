#include<iostream>
#include<ctime>

using namespace std;

void print(int a[], int len);//打印
void maopao(int a[], int len);//冒泡排序						  
void kuaipai(int a[], int begin, int end);//快速排序
void originKuaipai(int a[], int begin,int end);//原始快排
void charu(int a[], int len);//插入排序
void xuanze(int a[], int len);//选择排序
void guibin(int arr[], int len);//归并排序							
void guibinProcess(int arr[], int L, int R);//归并具体过程
void merge(int arr[], int L, int mid, int R);//归并后的连接
void heapSort(int arr[],int len);//堆排序
void heapInsert(int arr[],int index);//构建大根堆过程
void heapify(int arr[],int index, int heapSize);//堆向下查找，将大的值换到根节点
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

//原始快排
void originKuaipai(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int p = end;
	int temp;
	int less = begin - 1;//小于等于区的右边界
	for (int i = begin; i <= end; i++)
	{
		if (a[i] <= a[p])
		{
			temp = a[i];
			a[i] = a[++less];
			a[less] = temp;
		}
	}
	originKuaipai(a, begin, less - 1);
	originKuaipai(a, less + 1, end);
}

//快速排序(错误版本TODO)
//void kuaipai(int a[], int begin, int end)
//{
//	if (begin >= end)
//		return;
//	int left = begin, right = end-1;
//	int p = end;
//	int temp;
//	while (left < right)
//	{
//		while (left<right&&a[left]<=a[p])
//			left++;
//		while (left < right&&a[right] > a[p])
//			right--;
//		if (left < right)
//		{
//			temp = a[left];
//			a[left] = a[right];
//			a[right] = temp;
//		}
//	}
//	temp = a[left];
//	a[left] = a[p];
//	a[p] = temp;
//	kuaipai(a,begin,left - 1);
//	kuaipai(a,left+1,end);
//}

//快速排序(可以修改成随机快速排序，这样快排的复杂度成为概率事件)随机快排只需要随机选择一位数并将其同最后一位交换位置
void kuaipai(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int p=begin,less = begin-1, more = end;
	int temp;
	while (p < more)
	{
		if (a[p] < a[end])
		{
			temp = a[p];
			a[p++] = a[++less];
			a[less] = temp;
		}
		else if (a[p] == a[end])
			p++;
		else
		{
			temp = a[p];
			a[p] = a[--more];
			a[more] = temp;
		}
	}
	temp = a[more];
	a[more] = a[end];
	a[end] = temp;
	kuaipai(a,begin,less);
	kuaipai(a,more,end);
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

//堆排序
void heapSort(int arr[],int len)
{
	if (arr == NULL || len < 2)
		return;
	for (int i = 0; i < len; i++)
		heapInsert(arr, i);
	int heapSize = len;
	//根节点(即最大节点)换到最后，同时使堆大小减1
	int temp;
	temp = arr[0];
	arr[0] = arr[--heapSize];
	arr[heapSize] = temp;
	while (heapSize > 0)
	{
		heapify(arr, 0, heapSize);
		temp = arr[0];
		arr[0] = arr[--heapSize];
		arr[heapSize] = temp;
	}

}

//构建大根堆过程
void heapInsert(int arr[],int index)
{
	int temp;
	while (arr[index] > arr[(index - 1) / 2])
	{
		//当前位置和父节点位置交换
		temp = arr[index];
		arr[index] = arr[(index - 1) / 2];
		arr[(index - 1) / 2] = temp;
		//调整完当前位置改变，继续和父节点比较
		index = (index - 1) / 2;
	}
}

//堆向下查找，将大的值换到根节点
void heapify(int arr[],int index, int heapSize)
{
	int left = index * 2 + 1;
	int temp;
	while (left < heapSize)
	{
		//找到父节点和子节点中最大的点
		int largest = left + 1 < heapSize&&arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[largest] > arr[index] ? largest : index;
		//如果父节点最大，结束循环
		if (largest == index)
			break;
		//如果最大的不是父节点，将子节点位置和父节点位置交换
		temp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = temp;
		//继续往下遍历
		index = largest;
		left = index * 2 + 1;
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
	int *arr = new int[(int)(size )];
	srand(time(NULL));//利用系统时间，设置随机种子
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}

void main()
{
	generateRondomArray(5,1,10);
	int a[] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	//int a[] = { 30,70,30,40,20,30 };
	int len = sizeof(a) / sizeof(int);
	//guibin(a, len);
	//maopao(a,len);
	//kuaipai(a, 0, len - 1);//传入的是首尾索引
	//originKuaipai(a,0,len-1);
	//charu(a, len);
	//xuanze(a, len);
	heapSort(a, len);
	print(a, len);
	system("pause");
}