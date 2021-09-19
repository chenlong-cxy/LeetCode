#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		//���캯�������д��ʹ��Ĭ�Ϲ��캯������
	}

	/** Push element x onto stack. */
	void push(int x) {
		//���ǿյĶ���������
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
		//���ǿն��е�ǰn-1��Ԫ�ص���ն���
		while (nonemptyQ->size() > 1)
		{
			emptyQ->push(nonemptyQ->front());
			nonemptyQ->pop();
		}
		//��ȡ���һ��Ԫ��ֵ
		int top = nonemptyQ->front();
		nonemptyQ->pop(); //�����һ��Ԫ�س����У�������ջ��
		return top; //���ء���ջ��Ԫ��

	}

	/** Get the top element. */
	int top() {
		//��ջ����Ԫ�أ����ǿն��е����һ������
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
		return _q1.empty() && _q2.empty(); //��������ͬʱΪ��ʱ����ջ��Ϊ��
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