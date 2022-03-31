#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //无法构成这样的二维数组
			return vector<vector<int>>();

		vector<vector<int>> ret; //二维数组
		size_t index = 0;
		for (int i = 0; i < m; i++)
		{
			vector<int> tmp;
			tmp.resize(n);
			//每次从original中取出n个元素放入一维数组tmp中
			for (int j = 0; j < n; j++)
			{
				tmp[j] = original[index];
				index++;
			}
			//将一维数组tmp插入到二维数组中
			ret.push_back(tmp);
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //无法构成这样的二维数组
			return vector<vector<int>>();

		vector<vector<int>> ret;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			//每次从original中获取n个元素的首尾迭代器
			//用该迭代器范围构造出一个一维数组tmp
			vector<int> tmp(it, it + n);
			//将一维数组tmp插入到二维数组中
			ret.push_back(tmp);
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //无法构成这样的二维数组
			return vector<vector<int>>();

		vector<vector<int>> ret;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			//每次从original中获取n个元素的首尾迭代器
			//利用emplace_back将其插入到二维数组中
			ret.emplace_back(it, it + n);
		}
		return ret;
	}
};
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	vector<vector<int>> ret = Solution().construct2DArray(v, 2, 2);
	for (auto arr : ret)
	{
		for (auto e : arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}