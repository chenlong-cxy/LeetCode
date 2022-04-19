#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> um; //存储每个大小写字母与其所在行号的映射
		//1、建立第一行字母与行号1的映射
		string s1("qwertyuiop");
		for (auto e : s1)
		{
			um[e] = um[e - 32] = 1;
		}
		//2、建立第二行字母与行号2的映射
		string s2("asdfghjkl");
		for (auto e : s2)
		{
			um[e] = um[e - 32] = 2;
		}
		//3、建立第三行字母与行号3的映射
		string s3("zxcvbnm");
		for (auto e : s3)
		{
			um[e] = um[e - 32] = 3;
		}
		vector<string> ret; //存储符合要求的字符串
		//4、依次判断每一个字符串是否符合题目要求
		for (auto word : words)
		{
			//a、记录字符串中第一个字符所在行号
			int row = um[word[0]]; 
			bool flag = true;
			//b、遍历该字符串中其他字符
			for (auto ch : word)
			{
				if (um[ch] != row) //该字符串中其他某个字符与第一个字符所在的行号不同
				{
					flag = false; //不符合题目要求
					break;
				}
			}
			//c、若字符串符合题目要求，则将其放入集合
			if (flag == true) 
				ret.push_back(word);
		}
		return ret; //返回符合要求的字符串集合
	}
};
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> um; //存储每个大小写字母与其所在行号的映射
		vector<string> v{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };
		//1、建立每个字符与其所在行号的映射（第0行、第1行、第2行）
		for (size_t i = 0; i < v.size(); i++)
		{
			for (auto e : v[i])
			{
				um[e] = um[e - 32] = i;
			}
		}
		//2、依次判断每一个字符串是否符合题目要求
		vector<string> ret; //存储符合要求的字符串
		for (auto word : words)
		{
			//a、记录字符串中第一个字符所在行号
			int row = um[word[0]];
			bool flag = true;
			//b、遍历该字符串中其他字符
			for (auto ch : word)
			{
				if (um[ch] != row) //该字符串中其他某个字符与第一个字符所在的行号不同
				{
					flag = false; //不符合题目要求
					break;
				}
			}
			//c、若字符串符合题目要求，则将其放入集合
			if (flag == true)
				ret.push_back(word);
		}
		return ret; //返回符合要求的字符串集合
	}
};
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		//1、建立每个字符与其所在行号的映射（第0行、第1行、第2行）
		string table("12210111011122000010020202");
		vector<string> ret; //存储符合要求的字符串
		//2、依次判断每一个字符串是否符合题目要求
		for (auto word : words)
		{
			//a、记录字符串中第一个字符所在行号
			char row = table[tolower(word[0]) - 'a'];
			bool flag = true;
			//b、遍历该字符串中其他字符
			for (auto e : word)
			{
				if (table[tolower(e) - 'a'] != row) //该字符串中其他某个字符与第一个字符所在的行号不同
				{
					flag = false; //不符合题目要求
					break;
				}
			}
			//c、若字符串符合题目要求，则将其放入集合
			if (flag == true)
				ret.push_back(word);
		}
		return ret; //返回符合要求的字符串集合
	}
};
int main()
{
	vector<string> words{ "Hello", "Alaska", "Dad", "Peace" };
	vector<string> ret = Solution().findWords(words);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}