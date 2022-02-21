#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {
		//1��������ϣ����ǰ����26��λ�ò���ʼ��Ϊ0
		vector<int> table(26, 0);
		//2������word1����ÿ����ĸ���ֵĴ���ͳ�Ƶ���ϣ����
		for (auto e : word1)
		{
			table[e - 'a']++;
		}
		//3������word2�����ϣ����ͳ�Ƶ���ĸ���е���
		for (auto e : word2)
		{
			table[e - 'a']--;
		}
		//4��������ϣ���ж��Ƿ��в�ֵ����3����ĸ
		for (auto e : table)
		{
			if (abs(e) > 3)
				return false;
		}
		return true;
	}
};

int main()
{
	string word1 = "aaaa";
	string word2 = "bccb";
	cout << Solution().checkAlmostEquivalent(word1, word2) << endl;
	return 0;
}