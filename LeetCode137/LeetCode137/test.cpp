#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < 32; i++) //int类型有32个bit位
		{
			int total = 0; //记录nums当中第i个bit位为1的元素个数
			for (auto e : nums)
			{
				total += (e >> i) & 1; //统计数组nums当中第i个bit位为1的元素个数
			}
			if (total % 3 != 0)
			{
				//如果第i个bit位为1的元素个数不能被3整除
				//那么说明只出现一次的数字的这一bit位为1
				ret |= 1 << i; 
			}
		}
		return ret; //返回只出现一次的数字
	}
};

int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(99);
	cout << Solution().singleNumber(v) << endl;
	return 0;
}