#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> ret;
		size_t index = 0;
		for (int i = 1; i <= n; i++)
		{
			if (target[index] == i)
			{
				ret.push_back("Push");
				index++;
				if (index == target.size())
					break;
			}
			else
			{
				ret.push_back("Push");
				ret.push_back("Pop");
			}
		}
		return ret;
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