#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string str_num[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; //每个数字编号所对应的字符串
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret; //存储所有字母组合
		if (digits.empty()) //传入字符串为空，直接返回
			return ret;
		string str; //当前正在进行生成的字符串
		int i = 0; //标识本次需要使用的数字编号在digits当中的下标
		_letterCombinations(digits, i, str, ret); //递归
		return ret; //返回字母组合
	}
	void _letterCombinations(const string& digits, int i, string str, vector<string>& ret)
	{
		if (i == digits.size()) //digits当中的数字编号都使用过了
		{
			ret.push_back(str); //将本次的字母组合尾插到ret当中
		}
		else //digits当中的数字编号还有未使用的，当前字符串还未组合完毕
		{
			int num = digits[i] - '0'; //取出digits字符串当中的数字编号
			const string& letters = str_num[num]; //数字编号为num所对应的字符串
			//使用范围for依次使用字符串letters的每个字符进行组合
			for (auto ch : letters)
			{
				_letterCombinations(digits, i + 1, str + ch, ret);
			}
		}
	}
};

int main()
{ 
	for (auto e : Solution().letterCombinations("23"))
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}