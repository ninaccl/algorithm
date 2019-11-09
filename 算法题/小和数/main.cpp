#include <iostream>
using namespace std;

//小和数，指数组中所有的数之前的比它小的数的加和
//如 4 1 3 5 0 6的小和数为 0+1+（4+1+3）+0+（4+1+3+5+0）=22
//利用归并排序中的merge过程求小和数

int guibin(int arr[], int len);
int guibinProcess(int arr[], int L, int R);
int merge(int arr[], int L, int mid, int R);//

int guibin(int arr[], int len)
{
	if (arr == nullptr || len < 2)
		return 0;
	int result = guibinProcess(arr, 0, len - 1);
	return result;
}

int guibinProcess(int arr[], int L, int R)
{
	if (L == R)
		return 0;
	int mid = L + ((R - L) >> 1); //L和R的中点位置
	return guibinProcess(arr, L, mid)
		+guibinProcess(arr, mid + 1, R)
		+merge(arr, L, mid, R);
}

int merge(int arr[], int L, int mid, int R)
{
	int result = 0;
	int* res = new int[R - L + 1];
	int i = 0;
	int p1 = L, p2 = mid + 1;
	while (p1 <= mid && p2 <= R)
	{
		result += arr[p1] < arr[p2] ? (R - p2 + 1)*arr[p1] : 0;
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
	return result;
}

void main()
{
	int a[] = { 4,1,3,5,0,6 };
	int len = sizeof(a) / sizeof(int);
	int result = guibin(a, len);
	cout << result << endl;
}