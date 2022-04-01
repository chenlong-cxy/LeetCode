#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ret;
		size_t index = 0;
		int data = 1;
		while (index < target.size())
		{
			//1、依次将list当中的数字data进行Push操作
			ret.push_back("Push");
			//2、data的值与当前遍历到的target当中的数字不匹配
			if (data != target[index])
			{
				ret.push_back("Pop"); //需要进行Pop操作
			}
			//3、data的值与当前遍历到的target当中的数字匹配
			else
			{
				index++; //继续遍历target当中的下一个数字进行构建
			}
			data++; //下一个data
		}
		return ret; //返回操作序列
	}
};
int main()
{
	vector<int> target{ 1, 3 };
	vector<string> ret = Solution().buildArray(target, 3);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}