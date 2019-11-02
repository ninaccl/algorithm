#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printMaxarray(int i, int j, vector<vector<int>> flag, string s1)
{
	if (i == 0 || j == 0)
		return;
	if(flag[i][j]==0)
	{ 
		printMaxarray(i - 1, j - 1,flag,s1);
		cout << s1[i-1];
	}
	else if (flag[i][j] == 1)
	{
		printMaxarray(i - 1, j,flag,s1);
	}
	else
	{
		printMaxarray(i, j - 1,flag,s1);
	}
}

//找到最大公共子序列_定位子序列并返回长度
int maxarraylen(string s1, string s2)
{
	int s1_len = s1.length(), s2_len = s2.length();
	if (s1_len == 0 || s2_len == 0)
		return 0;
	//动态规划过程
	vector<vector<int>> array(s1_len+1, vector<int>(s2_len+1));
	vector<vector<int>> flag(s1_len + 1, vector<int>(s2_len + 1));
	for (int i = 0;i < s1_len+1;i++)
	{
		for (int j = 0;j < s2_len+1;j++)
		{
			if (i == 0 || j == 0)
			{
				array[i][j] = 0;
				flag[i][j] = 0;
			}		
		}
	}
	for (int i = 1;i < s1_len+1;i++)
	{
		for (int j = 1;j < s2_len+1;j++)
		{
			if (s1[i - 1] == s2[j - 1])
				array[i][j] = array[i - 1][j - 1] + 1;		
			else
			{
				if (array[i][j - 1] >= array[i - 1][j])
				{
					array[i][j] = array[i][j - 1];
					flag[i][j] = -1;
				}
				else
				{
					array[i][j] = array[i - 1][j];
					flag[i][j] = 1;
				}
			}		
		}
	}
	printMaxarray(s1_len, s2_len, flag, s1);//打印最大公共子序列
	return array[s1_len][ s2_len];
}

//找到最大公共子串_定位子串并返回长度
int maxSubstr(string s1, string s2)
{
	int s1_len = s1.length(), s2_len = s2.length();
	if (s1_len == 0 || s2_len == 0)
		return 0;
	//动态规划过程
	int res = 0,substrend = 0;
	string resstr;
	vector<vector<int>> array(s1_len + 1, vector<int>(s2_len + 1));
	for (int i = 0;i < s1_len + 1;i++)
	{
		for (int j = 0;j < s2_len + 1;j++)
		{
			if (i == 0 || j == 0)
				array[i][j] = 0;
		}
	}
	for (int i = 1;i < s1_len + 1;i++)
	{
		for (int j = 1;j < s2_len + 1;j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				array[i][j] = array[i - 1][j - 1] + 1;
				if (array[i][j]>res)
				{
					res = array[i][j];
					substrend = i;//记录结束位置
				}	
			}
			else
				array[i][j] = 0;
		}
	}
	resstr = s1.substr(substrend- res, res);//提取子串
	return res;
}

int main(void)
{
	string s1, s2;
	int res;
	getline(cin,s1);
	getline(cin,s2);
	res = maxarraylen(s1, s2);
	res = maxSubstr(s1, s2);
	return 0;
}