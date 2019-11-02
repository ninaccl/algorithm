#include<iostream>
using namespace std;

int main(void)
{
	string str = "saf4546\\\\+++";
	char *a = new char[1];
	char *p = a;
	//char a[50];
	/*char *a[] = { "athd","bdhg"};
	char **p = a;
	cout << *(p++) << endl;
	int i = sizeof(a) / sizeof(char*);*/
	/*int num=0;
	for (char it : str)
	{
		if (it >= '0'&&it <= '9')
		{
			/*(*p) = it;
			p++;*/
			//a[num] = it;
			/*num++;
		}
	}
	char temp;
	for (int i = num-1; i > 0;i--)
	{
		for (int j = 1;j < i;j++)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	for (int i = 0;i < num;i++)
	{
		cout << a[i] << endl;
	}*/
	return 0;
}