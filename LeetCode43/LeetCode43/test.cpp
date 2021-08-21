#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//	//字符串相乘
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		string retArr; //相乘后的字符串
//		int flag = 0; //标识需要添加的0的个数
//		for (int i = num2.size() - 1; i >= 0; i--) //依次取乘数的倒数第一位、倒数第二位、...
//		{
//			int count = num2[i] - '0'; //乘数当中待与被乘数相乘的那一位的数字
//			string tmp; //存储乘数该位与被乘数相乘后的结果（此时为空）
//			//数count与被乘数相乘，相当于将被乘数加count次到tmp当中
//			for (int j = 0; j < count; j++)
//			{
//				tmp = addStrings(tmp, num1);
//			}
//			//在字符串tmp后添上flag个0
//			for (int k = 0; k < flag; k++)
//				tmp.push_back('0');
//			retArr = addStrings(retArr, tmp); //将字符串tmp加到结果字符串retArr当中
//			flag++; //下一次tmp字符串后面需要添加的0的个数增加
//		}
//		return retArr; //返回相乘后的字符串
//	}
//	//字符串相加
//	string addStrings(string s1, string s2) {
//		int next = 0; //标识进位
//		int end1 = s1.size() - 1, end2 = s2.size() - 1;
//		string retArr; //相加后的字符串
//		while (end1 >= 0 || end2 >= 0) //只要有一个字符串未遍历完毕就继续
//		{
//			int num1 = 0; //第一个字符串待相加的数字
//			if (end1 >= 0)
//			{
//				num1 = s1[end1] - '0';
//				end1--;
//			}
//			int num2 = 0; //第二个字符串待相加的数字
//			if (end2 >= 0)
//			{
//				num2 = s2[end2] - '0';
//				end2--;
//			}
//			int sum = num1 + num2 + next; //两个待相加数字相加后的结果（注意加上进位next）
//			if (sum > 9) //需要进位
//			{
//				next = 1; //标识进位
//				sum -= 10; //进位后该位置的数字
//			}
//			else //无需进位
//				next = 0;
//			retArr.push_back(sum + '0'); //尾插到结果字符串retArr当中
//		}
//		if (next == 1) //还需进位
//			retArr.push_back('1'); //将字符1尾插到结果字符串retArr当中
//		reverse(retArr.begin(), retArr.end()); //逆置字符串retArr
//		return retArr; //返回相加后的字符串
//	}
//};


class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int m = num1.size(), n = num2.size();
		vector<int> arr(m + n, 0);
		for (int i = n - 1; i >= 0; i--) //取乘数的每一位
		{
			int a = num2[i] - '0';
			for (int j = m - 1; j >= 0; j--) //取被乘数的每一位
			{
				int b = num1[j] - '0';
				arr[i + j + 1] += a*b; //将结果
			}
		}
		int end = m + n - 1;
		while (end > 0)
		{
			arr[end - 1] += arr[end] / 10;
			arr[end] %= 10;
			end--;
		}
		int flag = 1;
		if (arr[0] != 0)
			flag = 0;
		string retArr;
		for (int i = flag; i < m + n; i++)
		{
			retArr += arr[i] + '0';
		}
		return retArr;
	}
};

int main()
{
	cout << Solution().multiply("2", "3") << endl;
	return 0;
}