#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		sort(nums.rbegin(), nums.rend());
//		return nums[k - 1];
//	}
//};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		sort(nums.begin(), nums.end(), greater<int>());
//		return nums[k - 1];
//	}
//};

//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int> q(nums.begin(), nums.end());
//		while (k - 1 > 0)
//		{
//			q.pop();
//			k--;
//		}
//		return q.top();
//	}
//};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.begin() + k);
		for (size_t i = k; i < nums.size(); i++)
		{
			if (nums[i] > q.top())
			{
				q.pop();
				q.push(nums[i]);
			}
		}
		return q.top();
	}
};

int main()
{
	vector<int> v{ 3, 2, 1, 5, 6, 4 };
	cout << Solution().findKthLargest(v, 2) << endl;
	return 0;
}