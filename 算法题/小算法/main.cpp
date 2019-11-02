#include<iostream>
#include <stack>

using namespace std;

//删除栈顶元素并返回
int getAndRemoveLastElement(stack<int>& s)
{
	int r = s.top();
	s.pop();
	if (s.empty())
		return r;
	int ret = getAndRemoveLastElement(s);
	s.push(r);
	return ret;
	 
}

//获取栈顶元素并删除，栈为空的时候依次插入
void reverseStack(stack<int>& s)
{
	if (s.empty())
		return;
	int r = getAndRemoveLastElement(s);
	reverseStack(s);
	s.push(r);
}

int main(void)
{
	int x, res = 0, multi=1;
	stack<int> s;
	do 
	{
		cin >> x;
		s.push(x);
	}while (getchar() != '\n');
	reverseStack(s);
	return 0;
}