#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
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
		vector<string> st;
		size_t pos = 0;
		while (pos < s.size())
		{
			if (isdigit(s[pos])) //是数字
			{
				string num = GetNum(s, pos);
				st.push_back(num);
			}
			else if (isalpha(s[pos]) || s[pos] == '[') //是字母或'['
			{
				st.push_back(string(1, s[pos]));
				pos++;
			}
			else //是']'
			{
				string sub;
				while (st.back() != "[")
				{
					sub += st.back();
					st.pop_back();
				}
				st.pop_back();
				reverse(sub.begin(), sub.end());
				int num = stoi(st.back());
				st.pop_back();
				string str;
				while (num)
				{
					str += sub;
					num--;
				}
				st.push_back(str);
				pos++;
			}
		}
		return GetString(st);
	}
};

int main()
{
	string s("3[a]2[bc]");
	cout << Solution().decodeString(s) << endl;
	return 0;
}