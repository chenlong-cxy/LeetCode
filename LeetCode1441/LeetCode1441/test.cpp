#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ret;
		size_t index = 0;
		int data = 1;
		while (index < target.size())
		{
			//1�����ν�list���е�����data����Push����
			ret.push_back("Push");
			//2��data��ֵ�뵱ǰ��������target���е����ֲ�ƥ��
			if (data != target[index])
			{
				ret.push_back("Pop"); //��Ҫ����Pop����
			}
			//3��data��ֵ�뵱ǰ��������target���е�����ƥ��
			else
			{
				index++; //��������target���е���һ�����ֽ��й���
			}
			data++; //��һ��data
		}
		return ret; //���ز�������
	}
};
int main()
{
	vector<int> target{ 1, 3 };
	vector<string> ret = Solution().buildArray(target, 3);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}