//实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作
//要求：
//1.pop,push,getMin操作的时间复杂度都是O(1)
//2.设计的栈类型可以使用现成的栈结构

#include<exception>
#include<stack>

using namespace std;

class MyStack
{
private:
	stack<int> stackData;//记录当前栈
	stack<int> stackMin;//记录当前栈最小值

public:
	//方法1
	void Push(int newNum)
	{
		if (stackMin.empty())
			stackMin.push(newNum);
		else if (newNum < stackMin.top())
			stackMin.push(newNum);
		else
		{
			int newMin = stackMin.top();
			stackMin.push(newMin);
		}
		stackData.push(newNum);
	}

	void Pop()
	{
		if (stackData.empty())
			throw exception("stack is empty");
		stackData.pop();
		stackMin.pop();
	}

	int getMin()
	{
		if (stackMin.empty())
			throw exception("stack is empty");
		return stackMin.top();
	}

	//方法2——稍微节省空间
	void Push2(int newNum)
	{
		if (stackMin.empty())
			stackMin.push(newNum);
		else if (newNum <= stackMin.top())//只有当前数小于等于stackMin栈顶时，才压入
			stackMin.push(newNum);
		stackData.push(newNum);
	}

	void Pop2()
	{
		if (stackData.empty())
			throw exception("stack is empty");
		if (stackData.top() == stackMin.top())//只有stackData栈顶等于stackMin栈顶时，才弹出
			stackMin.pop();
		stackData.pop();	
	}
};

void main()
{
	MyStack mystack;
	mystack.Push2(3);
	mystack.Push2(2);
	mystack.Push2(4);
	mystack.Push2(1);
	mystack.Push2(5);
	int min = mystack.getMin();
	mystack.Pop2();
	mystack.Pop2();
	min = mystack.getMin();
	system("pause");
}