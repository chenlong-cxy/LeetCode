#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> table(26, 0);
		//1�������ַ���s��ͳ��s��ÿ����ĸ���ֵĴ���
		for (auto ch : s)
		{
			table[ch - 'a']++;
		}
		//2�������ַ���t����table����ĸ���ֵĴ������е���
		for (auto ch : t)
		{
			table[ch - 'a']--;
			//���������Ӧ�Ĵ�����Ϊ��������˵������ĸ��t����ӵ���ĸ
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
		//1�������ַ���s����ÿ����ĸ��ASCII��ֵ�������
		for (auto ch : s)
		{
			ns += ch;
		}
		//2�������ַ���t����ÿ����ĸ��ASCII��ֵ�������
		for (auto ch : t)
		{
			nt += ch;
		}
		//3��������ASCII��Ĳ�ֵ��Ӧ����t�������ĸ��ASCII��ֵ
		return nt - ns;
	}
};
class Solution {
public:
	char findTheDifference(string s, string t) {
		char ret = 0;
		//1�������ַ���s��t����ÿ����ĸ����������
		for (auto ch : s)
		{
			ret ^= ch;
		}
		for (auto ch : t)
		{
			ret ^= ch;
		}
		//2��������յõ��ľ���t����ӵ���ĸ
		return ret;
	}
};
int main()
{
	cout << Solution().findTheDifference("abcd", "acbed") << endl;
	return 0;
}
