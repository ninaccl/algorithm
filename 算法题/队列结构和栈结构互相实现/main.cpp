#include<queue>
#include<stack>

using namespace std;

//队列结构实现栈结构
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

	//交换两个队列的地址
	void swap()
	{
		queue<int> temp = help;
		help = queue_o;
		queue_o = temp;
	}
};

//栈结构实现队列结构
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
		if (popStack.empty())//popStack里有东西不能倒
			while (!pushStack.empty())//一旦开始倒数，pushStack一定要一次性倒完
			{
				popStack.push(pushStack.top());
				pushStack.pop();
			}			
	}
};

void main()
{
	//队列结构实现栈结构
	queueStack a_stack;
	a_stack.queueStack_push(1);
	a_stack.queueStack_push(2);
	a_stack.queueStack_push(3);
	int b = a_stack.queueStack_pop();
	int c = a_stack.queueStack_peek();

	//栈结构实现队列结构
	stackQueue a_queue;
	a_queue.stackQueue_push(1);
	a_queue.stackQueue_push(2);
	a_queue.stackQueue_push(3);
	int d = a_queue.stackQueue_pop();
	int e = a_queue.stackQueue_peek();
	system("pause");
}