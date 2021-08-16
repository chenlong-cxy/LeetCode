#include<iostream>
#include <string>
using namespace std;
//反转字符串Ⅱ（区间部分反转）
//class Solution {
//public:
//	string reverseStr(string s, int k) {
//		int sz = s.size();
//		for (int start = 0; start < sz; start += 2 * k)
//		{
//			int left = start;
//			int right = start + k;
//			if (right > sz)
//				right = sz;
//			while (left < right)
//				reverse(s.begin() + start, s.end() + right);
//				//swap(s[left++], s[right--]);
//		}
//		return s;
//	}
//};
class Solution {
public:
	string reverseStr(string s, int k) {
		int sz = s.size();
		//以2k为一个单位对字符串进行遍历
		for (int left = 0; left < sz; left += 2 * k)
		{
			int right = left + k; //标记最后一个需要被反转的字符的下一个字符
			if (right > sz)
				right = sz; //若越界，则让right标记字符串末尾
			reverse(s.begin() + left, s.begin() + right); //反转left和right所标记的k个字符
		}
		return s; //返回目标字符串
	}
};
int main()
{
	cout << Solution().reverseStr("abcdefg", 2) << endl;
	return 0;
}