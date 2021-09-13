#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		if (_st.empty())
//		{
//			_st.push({ val, val });
//		}
//		else
//		{
//			_st.push({ val, min(val, _st.top().second) });
//		}
//	}
//
//	void pop() {
//		_st.pop();
//	}
//
//	int top() {
//		return _st.top().first;
//	}
//
//	int getMin() {
//		return _st.top().second;
//	}
//private:
//	stack<pair<int, int>> _st; //first�洢Ԫ�أ�second�洢��λ�õ���Сֵ
//};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

//class MinStack {
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//		//���캯�������д��ʹ��Ĭ�Ϲ��캯������
//	}
//
//	void push(int val) {
//		_st.push(val); //��valѹ������ջ
//		if (_minst.empty() || val < _minst.top()) //��val����Сջ��ջ��Ԫ��С����valѹ����Сջ
//		{
//			_minst.push(val);
//		}
//		else //��val����Сջ��ջ��Ԫ�ش�����Сջջ��Ԫ��ѹ����Сջ
//		{
//			_minst.push(_minst.top());
//		}
//	}
//
//	void pop() {
//		_st.pop(); //����ջ����pop
//		_minst.pop(); //��Сջ����pop
//	}
//
//	int top() {
//		return _st.top(); //��������ջջ��Ԫ��
//	}
//
//	int getMin() {
//		return _minst.top(); //������Сջջ��Ԫ��
//	}
//private:
//	stack<int> _st; //����ջ
//	stack<int> _minst; //��Сջ
//};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		//���캯�������д��ʹ��Ĭ�Ϲ��캯������
	}

	void push(int val) {
		_st.push(val); //��valѹ������ջ
		if (_minst.empty() || val <= _minst.top()) //��СջΪ�ջ�valС�ڵ�����Сջջ��Ԫ��
		{
			_minst.push(val); //��СջҲ��������ջ������
		}
	}

	void pop() {
		if (_minst.top() == _st.top()) //��Сջ������ջջ��Ԫ����ͬ
		{
			_minst.pop(); //��СջҲ���ų�ջ
		}
		_st.pop(); //����ջ��ջ
	}

	int top() {
		return _st.top(); //��������ջջ��Ԫ��
	}

	int getMin() {
		return _minst.top(); //������Сջջ��Ԫ��
	}
private:
	stack<int> _st; //����ջ
	stack<int> _minst; //��Сջ
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main()
{
	MinStack st;
	st.push(-2);
	st.push(0);
	st.push(-3);
	cout << st.getMin() << endl;
	st.pop();
	cout << st.top() << endl;;
	cout << st.getMin() << endl;
	return 0;
}