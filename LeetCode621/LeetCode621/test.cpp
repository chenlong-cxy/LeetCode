#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		//1、统计每种任务出现的次数
		vector<int> table(26, 0);
		for (const auto& task : tasks)
		{
			table[task - 'A']++;
		}

		//2、将各个任务按出现次数从多到少进行排序
		sort(table.begin(), table.end(), greater<int>());

		//3、统计出现次数等于最多出现次数的任务个数
		size_t num = 1;
		while (num < 26 && table[num] == table[0])
		{
			num++;
		}

		//4、将计算得到的值与所需执行任务的总数进行比较，返回较大值
		return max(tasks.size(), (table[0] - 1) * (n + 1) + num);
	}
};
int main()
{
	vector<char> v{ 'A', 'A', 'A', 'B', 'B', 'B' };
	cout << Solution().leastInterval(v, 2) << endl;
	return 0;
}