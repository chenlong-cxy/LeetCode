#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		//ͨ����Χfor����������������
		for (auto e : nums)
		{
			ret ^= e;
		}
		return ret; //��������Ľ��
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