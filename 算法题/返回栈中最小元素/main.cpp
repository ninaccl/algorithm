//ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ�صĲ���
//Ҫ��
//1.pop,push,getMin������ʱ�临�Ӷȶ���O(1)
//2.��Ƶ�ջ���Ϳ���ʹ���ֳɵ�ջ�ṹ

#include<exception>
#include<stack>

using namespace std;

class MyStack
{
private:
	stack<int> stackData;//��¼��ǰջ
	stack<int> stackMin;//��¼��ǰջ��Сֵ

public:
	//����1
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

	//����2������΢��ʡ�ռ�
	void Push2(int newNum)
	{
		if (stackMin.empty())
			stackMin.push(newNum);
		else if (newNum <= stackMin.top())//ֻ�е�ǰ��С�ڵ���stackMinջ��ʱ����ѹ��
			stackMin.push(newNum);
		stackData.push(newNum);
	}

	void Pop2()
	{
		if (stackData.empty())
			throw exception("stack is empty");
		if (stackData.top() == stackMin.top())//ֻ��stackDataջ������stackMinջ��ʱ���ŵ���
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