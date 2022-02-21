#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {
		//1、创建哈希表，提前开辟26个位置并初始化为0
		vector<int> table(26, 0);
		//2、遍历word1，将每个字母出现的次数统计到哈希表中
		for (auto e : word1)
		{
			table[e - 'a']++;
		}
		//3、遍历word2，与哈希表中统计的字母进行抵消
		for (auto e : word2)
		{
			table[e - 'a']--;
		}
		//4、遍历哈希表，判断是否有差值大于3的字母
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