#include <iostream>
#include <string>
using namespace std;

//反转字符串中的单词
class Solution {
public:
	 //void myReverse(string& s, size_t start, size_t end)
	 //{
	 //    while(start < end)
	 //    {
	 //        char tmp = s[start];
	 //        s[start] = s[end];
	 //        s[end] = tmp;
	 //        start++;
	 //        end--;
	 //    }
	 //}
	string reverseWords(string s) {
		size_t start = 0; //标记字符串中第一个待反转单词的第一个字符
		size_t end = s.find(' '); //获取第一个空格的下标
		while (end != std::string::npos) //找到空格就继续进行
		{
			//myReverse(s, start, end-1);
			reverse(s.begin() + start, s.begin() + end); //反转单个单词
			start = end + 1; //标记下一个待反转的单词的第一个字符
			end = s.find(' ', start); //从start位置开始向后寻找空格
		}
		end = s.size(); //标记最后一个单词的下一个位置
		//myReverse(s, start, end-1);
		reverse(s.begin() + start, s.begin() + end); //反转最后一个单词
		return s; //返回反转后的字符串
	}
};
int main()
{
	string s = Solution().reverseWords("this is the first problem");
	cout << s << endl;
	return 0;
}