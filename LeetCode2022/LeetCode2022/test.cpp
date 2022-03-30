#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n)
			return vector<vector<int>>();
		vector<vector<int>> vv;
		vector<int> tmp;
		tmp.resize(n);
		size_t index = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp[j] = original[index];
				index++;
			}
			vv.push_back(tmp);
		}
		return vv;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n)
			return vector<vector<int>>();
		vector<vector<int>> vv;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			vector<int> tmp(it, it + n);
			vv.push_back(tmp);
		}
		return vv;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n)
			return vector<vector<int>>();
		vector<vector<int>> vv;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			vv.emplace_back(it, it + n);
		}
		return vv;
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