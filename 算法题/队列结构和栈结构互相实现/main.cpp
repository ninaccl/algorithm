#include<queue>
#include<stack>

using namespace std;

//���нṹʵ��ջ�ṹ
class queueStack
{
private:
	queue<int> queue_o;
	queue<int> help;
public:
	void queueStack_push(int pushInt)
	{
		queue_o.push(pushInt);
	}

	int queueStack_peek()
	{
		if (queue_o.empty())
			throw exception("stack is empty");
		while (queue_o.size() != 1)
		{
			help.push(queue_o.front());
			queue_o.pop();
		}
		int res = queue_o.front();
		queue_o.pop();
		help.push(res);
		swap();
		return res;
	}

	int queueStack_pop()
	{
		if (queue_o.empty())
			throw exception("stack is empty");
		while (queue_o.size() > 1)
		{
			help.push(queue_o.front());
			queue_o.pop();
		}
		int res = queue_o.front();
		queue_o.pop();
		swap();
		return res;
	}

	//�����������еĵ�ַ
	void swap()
	{
		queue<int> temp = help;
		help = queue_o;
		queue_o = temp;
	}
};

//ջ�ṹʵ�ֶ��нṹ
class stackQueue
{
private:
	stack<int> pushStack;
	stack<int> popStack;
public:
	void stackQueue_push(int pushInt)
	{
		pushStack.push(pushInt);
		dao();
	}

	int stackQueue_pop()
	{
		if (popStack.empty() && pushStack.empty())
			throw exception("queue is empty");
		dao();
		int temp = popStack.top();
		popStack.pop();
		return temp;
	}

	int stackQueue_peek()
	{
		if (popStack.empty() && pushStack.empty())
			throw exception("queue is empty");
		dao();
		return popStack.top();
	}

	void dao()
	{
		if (popStack.empty())//popStack���ж������ܵ�
			while (!pushStack.empty())//һ����ʼ������pushStackһ��Ҫһ���Ե���
			{
				popStack.push(pushStack.top());
				pushStack.pop();
			}			
	}
};

void main()
{
	//���нṹʵ��ջ�ṹ
	queueStack a_stack;
	a_stack.queueStack_push(1);
	a_stack.queueStack_push(2);
	a_stack.queueStack_push(3);
	int b = a_stack.queueStack_pop();
	int c = a_stack.queueStack_peek();

	//ջ�ṹʵ�ֶ��нṹ
	stackQueue a_queue;
	a_queue.stackQueue_push(1);
	a_queue.stackQueue_push(2);
	a_queue.stackQueue_push(3);
	int d = a_queue.stackQueue_pop();
	int e = a_queue.stackQueue_peek();
	system("pause");
}