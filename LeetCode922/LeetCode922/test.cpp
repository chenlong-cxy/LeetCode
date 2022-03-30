#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		size_t i = 0, j = 1;
		while (i < nums.size() && j < nums.size())
		{
			//在偶数位上找奇数
			while (i < nums.size() && (nums[i] & 1) == 0)
				i += 2;
			//在奇数位上找偶数
			while (j < nums.size() && (nums[j] & 1) != 0)
				j += 2;
			//如果i和j都没有超出数组下标范围，则交换这两个数
			if (i < nums.size() && j < nums.size())
				swap(nums[i], nums[j]);
			i += 2;
			j += 2;
		}
		return nums;
	}
};

int main()
{
	vector<int> v{ 4, 2, 5, 7 };
	Solution().sortArrayByParityII(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}