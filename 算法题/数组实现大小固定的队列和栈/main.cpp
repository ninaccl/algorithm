#include<exception>

using namespace std;

//数组实现大小固定的栈
class ArrayStack
{
private:
	int *arr;
	int index;
	int length;
public:
	ArrayStack(int initSize)
	{
		if (initSize < 0)
		{
			throw exception("the length is not correct");
		}
		arr = new int[initSize];
		length = initSize;
	}
	int peek()
	{
		if (index == 0)
			return NULL;
		return arr[index - 1];
	}
	void push(int obj)
	{
		if(index==length)
			throw exception("the stack is full");
		arr[index++] = obj;
	}
	int pop()
	{
		if (index == 0)
			throw exception("the stack is empty");
		return arr[--index];
	}
};

//数组实现大小固定的队列
class ArrayQueue
{
private:
	int start;
	int end;
	int *arr;
	int size;
	int length;
public:
	ArrayQueue(int initSize)
	{
		if (initSize < 0)
			throw exception("the length is not correct");
		arr = new int[initSize];
		length = initSize;
		start = 0;
		end = 0;
		size = 0;
	}
	int peek()
	{
		if (size == 0)
			return NULL;
		return arr[start];
	}
	void push(int obj)
	{
		if (size == length)
			throw exception("the stack is full");
		size++;
		arr[end] = obj;
		end = nextIndex(length, end);
	}
	int pop()
	{
		if (size == 0)
			throw exception("the stack is empty");
		size--;
		int tmp = start;
		start = nextIndex(length, start);
		return arr[tmp];
	}
	//索引到达固定数组上界后返回到0，循环利用数组空间
	int nextIndex(int length,int index)
	{
		return index == length - 1 ? 0 : index + 1; 
	}
};
void main()
{
	//数组实现固定大小的栈
	ArrayStack array_stack = ArrayStack(3);
	array_stack.push(1);
	array_stack.push(2);
	array_stack.push(3);
	int a = array_stack.pop();
	int b = array_stack.peek();

	//数组实现固定大小的队列
	ArrayQueue array_queue = ArrayQueue(3);
	array_queue.push(1);
	array_queue.push(2);
	array_queue.push(3);
	int c = array_queue.pop();
	array_queue.push(4);
	int d = array_queue.peek();

	system("pause");
}