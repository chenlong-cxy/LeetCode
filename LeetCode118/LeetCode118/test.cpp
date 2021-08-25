#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v(numRows); //���ٿɴ洢numRows��vector<int>��vector����
		for (int i = 0; i < numRows; i++) //����numRows��vector�������θ�ֵ
		{
			v[i].resize(i + 1); //��i��vector������Ҫ�洢i+1������
			v[i][0] = v[i][i] = 1; //��һ���������һ����Ϊ1
			for (int j = 1; j < i; j++) //���������������Ϸ������Ϸ���������֮��
			{
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
			}
		}
		return v; //����numRows�е��������
	}
};

int main()
{
	auto ret = Solution().generate(8);
	for (auto x : ret)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}