#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> table(26, 0);
		for (const auto& task : tasks)
		{
			table[task - 'A']++;
		}

		sort(table.begin(), table.end(), greater<int>());
		size_t num = 1;
		while (num < 26 && table[num] == table[0])
		{
			num++;
		}
		return max(tasks.size(), (table[0] - 1) * (n + 1) + num);
	}
};
int main()
{
	vector<char> v{ 'A', 'A', 'A', 'B', 'B', 'B' };
	cout << Solution().leastInterval(v, 2) << endl;
	return 0;
}