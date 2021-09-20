#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		//构造函数无需编写，使用默认构造函数即可
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_pushST.push(x); //入数据直接对pushST进行压栈
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int front = peek(); //获取popST栈顶元素，即“队头”元素
		_popST.pop(); //将popST栈顶元素删除，即删除“队头”元素
		return front; //返回删除的元素
	}

	/** Get the front element. */
	int peek() {
		if (_popST.empty()) //如果popST为空，则先将pushST当中的全部元素压入popST
		{
			while (!_pushST.empty())
			{
				_popST.push(_pushST.top());
				_pushST.pop();
			}
		}
		return _popST.top(); //返回popST栈顶元素，即“队头”元素
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _pushST.empty() && _popST.empty(); //pushST和popST同时为空，则“队列”为空
	}
private:
	stack<int> _pushST;
	stack<int> _popST;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/

int main()
{
	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while (!q.empty())
	{
		cout << q.peek() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}