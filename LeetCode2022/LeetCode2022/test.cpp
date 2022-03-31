#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //�޷����������Ķ�ά����
			return vector<vector<int>>();

		vector<vector<int>> ret; //��ά����
		size_t index = 0;
		for (int i = 0; i < m; i++)
		{
			vector<int> tmp;
			tmp.resize(n);
			//ÿ�δ�original��ȡ��n��Ԫ�ط���һά����tmp��
			for (int j = 0; j < n; j++)
			{
				tmp[j] = original[index];
				index++;
			}
			//��һά����tmp���뵽��ά������
			ret.push_back(tmp);
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //�޷����������Ķ�ά����
			return vector<vector<int>>();

		vector<vector<int>> ret;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			//ÿ�δ�original�л�ȡn��Ԫ�ص���β������
			//�øõ�������Χ�����һ��һά����tmp
			vector<int> tmp(it, it + n);
			//��һά����tmp���뵽��ά������
			ret.push_back(tmp);
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
		if (original.size() != m*n) //�޷����������Ķ�ά����
			return vector<vector<int>>();

		vector<vector<int>> ret;
		for (auto it = original.begin(); it != original.end(); it += n)
		{
			//ÿ�δ�original�л�ȡn��Ԫ�ص���β������
			//����emplace_back������뵽��ά������
			ret.emplace_back(it, it + n);
		}
		return ret;
	}
};
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	vector<vector<int>> ret = Solution().construct2DArray(v, 2, 2);
	for (auto arr : ret)
	{
		for (auto e : arr)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}