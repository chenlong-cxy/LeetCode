#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) //�����鷵��0
			return 0;
		size_t slow = 0, fast = 1; //�������ָ��
		for (fast = 1; fast < nums.size(); fast++) //��ָ�����ڱ�������
		{
			if (nums[fast] != nums[slow]) //����ָ����ָԪ�ز�ͬ
			{
				slow++; //��ָ������
				nums[slow] = nums[fast]; //����ָ��ָ���Ԫ�ظ�ֵ����ָ��
			}
		}
		return slow + 1; //���������з��ظ����Ԫ�ظ���
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