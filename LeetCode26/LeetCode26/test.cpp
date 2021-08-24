#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) //空数组返回0
			return 0;
		size_t slow = 0, fast = 1; //定义快慢指针
		for (fast = 1; fast < nums.size(); fast++) //快指针用于遍历数组
		{
			if (nums[fast] != nums[slow]) //快慢指针所指元素不同
			{
				slow++; //慢指针自增
				nums[slow] = nums[fast]; //将快指针指向的元素赋值给慢指针
			}
		}
		return slow + 1; //返回数组中非重复项的元素个数
	}
};

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	int ret = Solution().removeDuplicates(v);
	for (int i = 0; i < ret; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}