#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& nums) {
		unordered_map<int, int> countMap;
		//1����һ�α�����ͳ�Ƴ��ִ���
		for (auto e : nums)
		{
			countMap[e]++;
		}
		//2���ڶ��α��������س���n�ε�Ԫ��
		for (auto e : countMap)
		{
			if (e.second == nums.size() / 2)
				return e.first;
		}
		return -1; //��֤����ͨ��������·�����з���ֵ��
	}
};

int main()
{
	vector<int> nums{ 5, 1, 5, 2, 5, 3, 5, 4 };
	int ret = Solution().repeatedNTimes(nums);
	cout << ret << endl;
	return 0;
}