#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		//���캯�������д��ʹ��Ĭ�Ϲ��캯������
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_pushST.push(x); //������ֱ�Ӷ�pushST����ѹջ
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int front = peek(); //��ȡpopSTջ��Ԫ�أ�������ͷ��Ԫ��
		_popST.pop(); //��popSTջ��Ԫ��ɾ������ɾ������ͷ��Ԫ��
		return front; //����ɾ����Ԫ��
	}

	/** Get the front element. */
	int peek() {
		if (_popST.empty()) //���popSTΪ�գ����Ƚ�pushST���е�ȫ��Ԫ��ѹ��popST
		{
			while (!_pushST.empty())
			{
				_popST.push(_pushST.top());
				_pushST.pop();
			}
		}
		return _popST.top(); //����popSTջ��Ԫ�أ�������ͷ��Ԫ��
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _pushST.empty() && _popST.empty(); //pushST��popSTͬʱΪ�գ��򡰶��С�Ϊ��
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