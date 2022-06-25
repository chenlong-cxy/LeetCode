#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int balancedStringSplit(string s) {
		int left = 0, right = -1;
		int level = 0;
		int count = 0;
		while (right < (int)s.size() - 1)
		{
			if (s[++right] == 'L')
				level--;
			else
				level++;
			if (level == 0)
			{
				count++;
				left = right;
			}
		}
		return count;
	}
};
class Solution {
public:
	int balancedStringSplit(string s) {
		size_t left = 0, right = 0;
		int level = 0;
		int count = 0;
		while (right < s.size())
		{
			if (s[right] == 'L')
				level--;
			else
				level++;
			if (level == 0)
			{
				count++;
				left = right;
			}
			right++;
		}
		return count;
	}
};
class Solution {
public:
	int balancedStringSplit(string s) {
		int count = 0, level = 0;
		for (const auto& ch : s) //��Χfor����ƽ���ַ���s
		{
			ch == 'L' ? level-- : level++; //L�Լ���R����
			if (level == 0)
			{
				//level��ֵ��Ϊ0������ƽ���ַ���������һ
				count++;
			}
		}
		return count;
	}
};
int main()
{
	cout << Solution().balancedStringSplit("RLLLLRRRLR") << endl;
	return 0;
}
