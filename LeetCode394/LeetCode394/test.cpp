#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	//从字符串s的pos位置开始，提取数字字符串
	string GetNum(string& s, size_t& pos)
	{
		string num;
		while (s[pos] != '[')
		{
			num += s[pos];
			pos++;
		}
		return num;
	}
	//将vector当中的字符串拼接后进行返回
	string GetString(vector<string>& st)
	{
		string s;
		for (auto e : st)
		{
			s += e;
		}
		return s;
	}
	string decodeString(string s) {
		vector<string> st; //数组模拟栈
		size_t pos = 0; //用于遍历字符串s
		while (pos < s.size())
		{
			//1、遍历到的是数字，先将完整的数字字符串提取出来，然后进行压栈
			if (isdigit(s[pos]))
			{
				string num = GetNum(s, pos);
				st.push_back(num);
			}
			//2、遍历到的是字母或'['，直接将其进行压栈
			else if (isalpha(s[pos]) || s[pos] == '[')
			{
				st.push_back(string(1, s[pos]));
				pos++;
			}
			//3、遍历到的是']'，先获取到待复制的字符串，再将其进行复制，最好将复制后的字符串重新进行压栈
			else
			{
				vector<string> sub; //待复制的若干字符串
				//a、先进行弹栈，将弹出的字符串保存到vector当中，直到'['被弹出时停止弹栈，'['不保存到vector中
				while (st.back() != "[")
				{
					sub.push_back(st.back());
					st.pop_back();
				}
				st.pop_back();

				//b、再将vector当中的内容进行逆置，因为出栈的顺序与入栈顺序相反
				reverse(sub.begin(), sub.end());

				//c、然后将待复制的若干字符串进行拼接，得到最终待复制的字符串
				string all = GetString(sub);

				//d、弹出此时栈顶的数字字符串，并将其转换成整数num
				int num = stoi(st.back());
				st.pop_back();

				//d、将待复制的字符串复制num次，最终得到复制后的字符串
				string str; //复制后的字符串
				while (num--)
				{
					str += all;
				}

				//e、将复制后的字符串进行压栈
				st.push_back(str);

				pos++;
			}
		}
		return GetString(st); //将栈当中的字符串拼接后进行返回
	}
};

int main()
{
	string s("3[a]2[bc]");
	cout << Solution().decodeString(s) << endl;
	return 0;
}