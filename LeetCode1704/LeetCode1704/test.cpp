#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//	bool halvesAreAlike(string s) {
//		string a(s.begin(), s.begin() + s.size() / 2);
//		string b(s.begin() + s.size() / 2, s.end());
//		string str = "aeiouAEIOU";
//		unordered_set<char> us(str.begin(), str.end());
//		int count = 0;
//		for (auto e : a)
//		{
//			if (us.find(e) != us.end())
//				count++;
//		}
//		for (auto e : b)
//		{
//			if (us.find(e) != us.end())
//				count--;
//		}
//		return count == 0;
//	}
//};
class Solution {
public:
	bool halvesAreAlike(string s) {
		//1、将元音字母存储到unordered_set容器中
		string str = "aeiouAEIOU";
		unordered_set<char> us(str.begin(), str.end());
		int count = 0;
		//2、遍历字符串的前半部分，统计元音字母个数
		for (size_t i = 0; i < s.size() / 2; i++)
		{
			if (us.find(s[i]) != us.end())
				count++;
		}
		//3、遍历字符串的后半部分，与前半部分的元音字母个数进行抵消
		for (size_t i = s.size() / 2; i < s.size(); i++)
		{
			if (us.find(s[i]) != us.end())
				count--;
		}
		//4、若最终count被抵消为0，则说明该字符串前半段和后半段具有相同数目的元音字母
		return count == 0;
	}
};
int main()
{
	string s = "book";
	cout << Solution().halvesAreAlike(s) << endl;
	return 0;
}