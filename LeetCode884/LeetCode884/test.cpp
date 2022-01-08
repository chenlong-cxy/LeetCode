#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> um;
		//1、将两个字符串拼接起来，中间加一个" "字符串
		string str = s1 + " " + s2;

		//2、将拼接后字符串当中的单词放入哈希表
		size_t start = 0; //字头
		size_t pos = str.find(' '); //字尾
		while (pos != string::npos) //直到找到字符串结尾
		{
			string word = str.substr(start, pos - start); //将单词提取出来
			um[word]++; //将单词放入哈希表
			start = pos + 1; //更新字头
			pos = str.find(' ', start); //更新字尾
		}
		//将最后一个单词放入哈希表
		string word = str.substr(start);
		um[word]++;

		//3、找出哈希表中只出现过一次的单词，即不常见单词
		vector<string> vRet;
		for (auto e : um)
		{
			if (e.second == 1) //只出现过一次的单词
			{
				vRet.push_back(e.first);
			}
		}
		return vRet;
	}
};

int main()
{
	string s1("this apple is sweet");
	string s2("this apple is sour");
	vector<string> ret = Solution().uncommonFromSentences(s1, s2);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}