#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int m = mat.size(), n = mat[0].size();
		vector<pair<int, int>> table;
		for (int i = 0; i < m; i++)
		{
			int left = 0, right = n - 1, pos = -1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (mat[i][mid] == 0)
				{
					right = mid - 1;
				}
				else
				{
					pos = mid;
					left = mid + 1;
				}
			}
			//table.push_back(make_pair(pos+1, i));
			table.emplace_back(pos + 1, i);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq(table.begin(), table.end());
		//priority_queue pq(greater<pair<int, int>>(), move(table));
		vector<int> ret;
		for (int i = 0; i < k; i++)
		{
			ret.push_back(pq.top().second);
			pq.pop();
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> mat = { 
		{ 1, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 1 } };
	int k = 3;
	vector<int> ret = Solution().kWeakestRows(mat, k);
	for (const int& e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}