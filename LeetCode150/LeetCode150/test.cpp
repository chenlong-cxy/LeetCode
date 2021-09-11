#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (size_t i = 0; i < tokens.size(); i++) //遍历逆波兰表达式
		{
			int left, right;
			if (tokens[i] == "+") //是"+"运算符
			{
				GetNum(st, left, right); //获取左右操作数
				st.push(left + right); //运算结果入栈
			}
			else if (tokens[i] == "-") //是"-"运算符
			{
				GetNum(st, left, right); //获取左右操作数
				st.push(left - right); //运算结果入栈
			}
			else if (tokens[i] == "*") //是"*"运算符
			{
				GetNum(st, left, right); //获取左右操作数
				st.push(left*right); //运算结果入栈
			}
			else if (tokens[i] == "/") //是"/"运算符
			{
				GetNum(st, left, right); //获取左右操作数
				st.push(left / right); //运算结果入栈
			}
			else //是数字
			{
				st.push(stoi(tokens[i])); //将字符串转化为整型后入栈
			}
		}
		return st.top(); //表达式遍历结束后，返回栈中的数即为表达式结果
	}
	//获取左右操作数
	void GetNum(stack<int>& st, int& left, int& right)
	{
		right = st.top(); //先弹出的是右操作数
		st.pop();
		left = st.top(); //后弹出的是左操作数
		st.pop();
	}
};

int main()
{
	//vector<string> tokens{ "1", "2", "+", "3", "4", "+", "*" };
	vector<string> tokens{"2", "1", "+", "3", "*" };
	cout << Solution().evalRPN(tokens) << endl;
	return 0;
}