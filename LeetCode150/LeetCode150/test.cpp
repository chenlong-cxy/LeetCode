#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (size_t i = 0; i < tokens.size(); i++) //�����沨�����ʽ
		{
			int left, right;
			if (tokens[i] == "+") //��"+"�����
			{
				GetNum(st, left, right); //��ȡ���Ҳ�����
				st.push(left + right); //��������ջ
			}
			else if (tokens[i] == "-") //��"-"�����
			{
				GetNum(st, left, right); //��ȡ���Ҳ�����
				st.push(left - right); //��������ջ
			}
			else if (tokens[i] == "*") //��"*"�����
			{
				GetNum(st, left, right); //��ȡ���Ҳ�����
				st.push(left*right); //��������ջ
			}
			else if (tokens[i] == "/") //��"/"�����
			{
				GetNum(st, left, right); //��ȡ���Ҳ�����
				st.push(left / right); //��������ջ
			}
			else //������
			{
				st.push(stoi(tokens[i])); //���ַ���ת��Ϊ���ͺ���ջ
			}
		}
		return st.top(); //���ʽ���������󣬷���ջ�е�����Ϊ���ʽ���
	}
	//��ȡ���Ҳ�����
	void GetNum(stack<int>& st, int& left, int& right)
	{
		right = st.top(); //�ȵ��������Ҳ�����
		st.pop();
		left = st.top(); //�󵯳������������
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