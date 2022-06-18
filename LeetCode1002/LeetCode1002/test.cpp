#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		vector<int> mintable(26, INT_MAX); //记录26个字符在各个字符串中出现的最小次数
		vector<int> table(26); //临时记录26个字符在某个字符串中出现的次数

		//1、遍历每个字符串，分别找到26个字符在各个字符串中出现的最小次数
		for (const string& word : words)
		{
			fill(table.begin(), table.end(), 0); //清空table
			//a、统计word中每个字符出现的次数
			for (const auto ch : word)
			{
				table[ch - 'a']++; //直接定址法
			}
			//b、更新26个字符在各个字符串中出现的最小次数
			for (size_t i = 0; i < 26; i++)
			{
				mintable[i] = min(table[i], mintable[i]);
			}
		}

		//2、根据26个字符在各个字符串中出现的最小次数来构建共用字符数组
		vector<string> ret;
		for (size_t i = 0; i < 26; i++)
		{
			for (size_t j = 0; j < mintable[i]; j++)
			{
				ret.emplace_back(1, i + 'a');
			}
		}
		return ret;
	}
};

int main()
{
	vector<string> words{ "bella", "label", "roller" };
	auto ret = Solution().commonChars(words);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}