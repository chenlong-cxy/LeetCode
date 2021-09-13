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
//	stack<pair<int, int>> _st; //first存储元素，second存储该位置的最小值
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
//		//构造函数无需编写，使用默认构造函数即可
//	}
//
//	void push(int val) {
//		_st.push(val); //将val压入数据栈
//		if (_minst.empty() || val < _minst.top()) //若val比最小栈的栈顶元素小，则将val压入最小栈
//		{
//			_minst.push(val);
//		}
//		else //若val比最小栈的栈顶元素大，则将最小栈栈顶元素压入最小栈
//		{
//			_minst.push(_minst.top());
//		}
//	}
//
//	void pop() {
//		_st.pop(); //数据栈进行pop
//		_minst.pop(); //最小栈进行pop
//	}
//
//	int top() {
//		return _st.top(); //返回数据栈栈顶元素
//	}
//
//	int getMin() {
//		return _minst.top(); //返回最小栈栈顶元素
//	}
//private:
//	stack<int> _st; //数据栈
//	stack<int> _minst; //最小栈
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
		//构造函数无需编写，使用默认构造函数即可
	}

	void push(int val) {
		_st.push(val); //将val压入数据栈
		if (_minst.empty() || val <= _minst.top()) //最小栈为空或val小于等于最小栈栈顶元素
		{
			_minst.push(val); //最小栈也跟着数据栈入数据
		}
	}

	void pop() {
		if (_minst.top() == _st.top()) //最小栈与数据栈栈顶元素相同
		{
			_minst.pop(); //最小栈也跟着出栈
		}
		_st.pop(); //数据栈出栈
	}

	int top() {
		return _st.top(); //返回数据栈栈顶元素
	}

	int getMin() {
		return _minst.top(); //返回最小栈栈顶元素
	}
private:
	stack<int> _st; //数据栈
	stack<int> _minst; //最小栈
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