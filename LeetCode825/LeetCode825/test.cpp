#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class Solution {
//public:
//	int numFriendRequests(vector<int>& ages) {
//		int ans = 0;
//		for (size_t i = 0; i < ages.size(); i++)
//		{
//			int x = ages[i];
//			for (size_t j = 0; j < ages.size(); j++)
//			{
//				if (j == i) //用户不会向自己发送好友请求
//					continue;
//				int y = ages[j];
//				if ((y > x / 2 + 7) && (y <= x) && ((y <= 100) || (x >= 100)))
//				{
//					ans++;
//				}
//			}
//		}
//		return ans;
//	}
//};
//class Solution {
//public:
//	int numFriendRequests(vector<int>& ages) {
//		//1、对用户的年龄进行排序
//		sort(ages.begin(), ages.end());
//		int left = 0, right = 0, ans = 0;
//		//2、依次遍历每一个用户，找到每个用户能够向外发送的好友请求的个数并累加在一起
//		for (size_t i = 0; i < ages.size(); i++)
//		{
//			int x = ages[i];
//			if (x <= 14) //不存在满足要求的用户y
//				continue;
//			while (left < ages.size() && ages[left] <= x / 2 + 7) //找到左边界
//				left++;
//			while (right + 1 < ages.size() && ages[right + 1] <= x) //找到右边界
//				right++;
//			ans += right - left; //将满足该用户能够向外发送的好友请求的个数累加到ans上
//		}
//		return ans;
//	}
//};
class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		//1、统计每个年龄段的用户个数
		vector<int> cnt(121);
		for (auto age : ages)
		{
			cnt[age]++;
		}
		//2、计算出cnt数组的前缀和数组pre
		vector<int> pre(121);
		for (size_t i = 1; i < 121; i++)
		{
			pre[i] = pre[i - 1] + cnt[i];
		}
		//3、通过公式计算出每个年龄段的若干个用户能够向外发送的好友请求的总个数，并累加在一起
		int ans = 0;
		for (size_t i = 15; i < 121; i++) //14岁及以下的用户无法向外发送好友请求
		{
			if (cnt[i] != 0) //该年龄段的用户个数不为0
			{
				int bounds = i / 2 + 7;
				//将每个年龄段的用户能够向外发送的好友请求进行累加
				ans += (pre[i] - pre[bounds] - 1)*cnt[i];
			}
		}
		return ans;
	}
};
int main()
{
	vector<int> ages{ 20, 30, 100, 110, 120 };
	cout << Solution().numFriendRequests(ages) << endl;
	return 0;
}