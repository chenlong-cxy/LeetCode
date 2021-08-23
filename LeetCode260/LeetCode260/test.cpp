#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int ret = 0; //����������Ԫ�ؽ�������Ľ��
		//ͨ����Χfor�������飬�������е�����Ԫ�ؽ������
		for (auto e : nums)
		{
			ret ^= e;
		}
		int div = 1; //���ret��32��bitλ��ĳ����Ϊ0��bitλ
		//��������Ѱ��ret��32��bitλ�е�һ����Ϊ0��bitλ
		while ((ret&div) == 0)
		{
			div <<= 1; //��������Ѱ��bitλ
		}
		int a = 0, b = 0; //�ֱ�洢����ֻ����һ�ε�Ԫ��
		for (auto e : nums)
		{
			if (e&div) //Ԫ��divλ�õ�bitλΪ1��Ϊһ��������
				a ^= e;
			else //Ԫ��divλ�õ�bitλΪ0��Ϊһ��������
				b ^= e;
		}
		//������ֻ����һ�ε�Ԫ�طŵ�����v����
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		return v; //��������v
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