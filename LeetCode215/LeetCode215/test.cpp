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
		//先用数组当中的前K个元素构建小堆
		priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.begin() + k);
		//处理数组剩余元素
		for (size_t i = k; i < nums.size(); i++)
		{
			if (nums[i] > q.top()) //若比堆顶元素大
			{
				q.pop(); //将堆顶元素弹出
				q.push(nums[i]); //将该元素入堆
			}
		}
		return q.top(); //返回堆顶元素即为数组当中的第K个最大元素
	}
};

int main()
{
	vector<int> v{ 3, 2, 1, 5, 6, 4 };
	cout << Solution().findKthLargest(v, 2) << endl;
	return 0;
}