#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < 32; i++) //int������32��bitλ
		{
			int total = 0; //��¼nums���е�i��bitλΪ1��Ԫ�ظ���
			for (auto e : nums)
			{
				total += (e >> i) & 1; //ͳ������nums���е�i��bitλΪ1��Ԫ�ظ���
			}
			if (total % 3 != 0)
			{
				//�����i��bitλΪ1��Ԫ�ظ������ܱ�3����
				//��ô˵��ֻ����һ�ε����ֵ���һbitλΪ1
				ret |= 1 << i; 
			}
		}
		return ret; //����ֻ����һ�ε�����
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