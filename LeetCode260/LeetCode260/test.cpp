#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int ret = 0; //数组中所有元素进行异或后的结果
		//通过范围for遍历数组，对数组中的所有元素进行异或
		for (auto e : nums)
		{
			ret ^= e;
		}
		int div = 1; //标记ret的32个bit位中某个不为0的bit位
		//从右向左寻找ret的32个bit位中第一个不为0的bit位
		while ((ret&div) == 0)
		{
			div <<= 1; //从右向左寻找bit位
		}
		int a = 0, b = 0; //分别存储两个只出现一次的元素
		for (auto e : nums)
		{
			if (e&div) //元素div位置的bit位为1的为一组进行异或
				a ^= e;
			else //元素div位置的bit位为0的为一组进行异或
				b ^= e;
		}
		//将两个只出现一次的元素放到容器v当中
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		return v; //返回容器v
	}
};

int main()
{
	vector<int> v{ 1, 2, 4, 5, 4, 2 };
	vector<int> ret = Solution().singleNumber(v);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}