#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	bool isAnagram(string s, string t) {
//		unordered_map<char, int> um1, um2;
//		for (char e : s)
//		{
//			um1[e]++;
//		}
//		for (char e : t)
//		{
//			um2[e]++;
//		}
//		if (um1.size() == um2.size())
//		{
//			for (char e : s)
//			{
//				if (um1[e] != um2[e])
//					return false;
//			}
//			return true;
//		}
//		return false;
//	}
//};

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) //保证两个字符串的长度相同
			return false;

		vector<int> table; //哈希表
		table.resize(26); //提前开辟26个位置
		//1、遍历字符串s，统计s中每个字母出现的次数
		for (auto& ch : s)
		{
			table[ch - 'a']++;
		}
		//2、遍历字符串t，将t和s中的字母进行抵消
		for (auto& ch : t)
		{
			table[ch - 'a']--;
			if (table[ch - 'a'] < 0) //抵消时出现了负数
				return false;
		}
		return true; //全部抵消成功
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << Solution().isAnagram(s, t) << endl;
	return 0;
}