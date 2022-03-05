#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int maxPower(string s) {
		int count = 1; //��ǰ�ַ��������ֵĴ���
		int max = 1; //�ַ������ַ��������ִ��������ֵ
		for (size_t i = 1; i < s.size(); i++)
		{
			if (s[i] == s[i - 1])
			{
				count++;
				if (count > max) //����max
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