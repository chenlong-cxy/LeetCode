#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		unordered_map<string, int> um;
		//1、遍历数组arr，统计每个字符串对应出现的次数
		for (auto e : arr)
		{
			um[e]++;
		}
		//2、再次遍历数组arr，找到第k个独一无二的字符串
		for (auto e : arr)
		{
			if (um[e] == 1) //判断是否是独一无二的字符串
			{
				k--;
				if (k == 0) //判断是否是第k个独一无二的字符串
					return e;
			}
		}
		return ""; //不存在第k个独一无二的字符串，则返回空字符串
	}
};
int main()
{
	vector<string> arr{ "d", "b", "c", "b", "c", "a" };
	cout << Solution().kthDistinct(arr, 2) << endl;
	return 0;
}