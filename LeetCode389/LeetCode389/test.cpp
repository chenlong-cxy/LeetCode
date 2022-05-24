#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> table(26, 0);
		//1、遍历字符串s，统计s中每个字母出现的次数
		for (auto ch : s)
		{
			table[ch - 'a']++;
		}
		//2、遍历字符串t，对table中字母出现的次数进行抵消
		for (auto ch : t)
		{
			table[ch - 'a']--;
			//若抵消后对应的次数变为负数，则说明该字母是t中添加的字母
			if (table[ch - 'a'] < 0)
			{
				return ch;
			}
		}
		return ' ';
	}
};
class Solution {
public:
	char findTheDifference(string s, string t) {
		int ns = 0, nt = 0;
		//1、遍历字符串s，对每个字母的ASCII码值进行求和
		for (auto ch : s)
		{
			ns += ch;
		}
		//2、遍历字符串t，对每个字母的ASCII码值进行求和
		for (auto ch : t)
		{
			nt += ch;
		}
		//3、两个总ASCII码的差值对应就是t中添加字母的ASCII码值
		return nt - ns;
	}
};
class Solution {
public:
	char findTheDifference(string s, string t) {
		char ret = 0;
		//1、遍历字符串s和t，对每个字母进行异或操作
		for (auto ch : s)
		{
			ret ^= ch;
		}
		for (auto ch : t)
		{
			ret ^= ch;
		}
		//2、异或最终得到的就是t中添加的字母
		return ret;
	}
};
int main()
{
	cout << Solution().findTheDifference("abcd", "acbed") << endl;
	return 0;
}
