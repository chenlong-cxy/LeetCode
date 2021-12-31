#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		unordered_map<int, int> countMap;
		//1、第一次遍历，统计出现次数
		for (auto e : nums)
		{
			countMap[e]++;
		}
		//2、第二次遍历，返回出现n次的元素
		for (auto e : countMap)
		{
			if (e.second == nums.size() / 2)
				return e.first;
		}
		return -1; //保证编译通过（所有路径都有返回值）
	}
};

int main()
{
	vector<int> nums{ 5, 1, 5, 2, 5, 3, 5, 4 };
	int ret = Solution().repeatedNTimes(nums);
	cout << ret << endl;
	return 0;
}