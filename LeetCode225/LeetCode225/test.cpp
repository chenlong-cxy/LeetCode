#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		//构造函数无需编写，使用默认构造函数即可
	}

	/** Push element x onto stack. */
	void push(int x) {
		//往非空的队列入数据
		if (!_q1.empty()) 
		{
			_q1.push(x);
		}
		else
		{
			_q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		queue<int>* emptyQ = &_q1;
		queue<int>* nonemptyQ = &_q2;
		if (!_q1.empty())
		{
			swap(emptyQ, nonemptyQ);
		}
		//将非空队列的前n-1个元素导入空队列
		while (nonemptyQ->size() > 1)
		{
			emptyQ->push(nonemptyQ->front());
			nonemptyQ->pop();
		}
		//获取最后一个元素值
		int top = nonemptyQ->front();
		nonemptyQ->pop(); //将最后一个元素出队列，即“出栈”
		return top; //返回“出栈”元素

	}

	/** Get the top element. */
	int top() {
		//“栈顶”元素，即非空队列的最后一个数据
		if (!_q1.empty())
		{
			return _q1.back();
		}
		else
		{
			return _q2.back();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return _q1.empty() && _q2.empty(); //两个队列同时为空时，则“栈”为空
	}
private:
	queue<int> _q1;
	queue<int> _q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/

int main()
{
	MyStack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;
}