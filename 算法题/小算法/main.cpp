#include<iostream>
#include <stack>

using namespace std;

//ɾ��ջ��Ԫ�ز�����
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

//��ȡջ��Ԫ�ز�ɾ����ջΪ�յ�ʱ�����β���
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