#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v(numRows); //开辟可存储numRows个vector<int>的vector容器
		for (int i = 0; i < numRows; i++) //对这numRows个vector容器依次赋值
		{
			v[i].resize(i + 1); //第i个vector容器需要存储i+1个整型
			v[i][0] = v[i][i] = 1; //第一个数和最后一个数为1
			for (int j = 1; j < i; j++) //其余数等于其左上方和左上方的两个数之和
			{
				v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
			}
		}
		return v; //返回numRows行的杨辉三角
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