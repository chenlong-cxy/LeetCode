#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		//通过范围for遍历容器，逐个异或
		for (auto e : nums)
		{
			ret ^= e;
		}
		return ret; //返回异或后的结果
	}
};

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);
	v.push_back(6);
	v.push_back(7);
	v.push_back(7);
	cout << Solution().singleNumber(v) << endl;
	return 0;
}