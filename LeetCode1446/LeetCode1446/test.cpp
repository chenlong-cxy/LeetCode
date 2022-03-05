#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int maxPower(string s) {
		int count = 1; //当前字符连续出现的次数
		int max = 1; //字符串中字符连续出现次数的最大值
		for (size_t i = 1; i < s.size(); i++)
		{
			if (s[i] == s[i - 1])
			{
				count++;
				if (count > max) //更新max
					max = count;
			}
			else
			{
				count = 1;
			}
		}
		return max;
	}
};

int main()
{
	cout << Solution().maxPower("leetcode") << endl;
	return 0;
}