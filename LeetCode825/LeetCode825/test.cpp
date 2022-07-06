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
//				if (j == i) //�û��������Լ����ͺ�������
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
//		//1�����û��������������
//		sort(ages.begin(), ages.end());
//		int left = 0, right = 0, ans = 0;
//		//2�����α���ÿһ���û����ҵ�ÿ���û��ܹ����ⷢ�͵ĺ�������ĸ������ۼ���һ��
//		for (size_t i = 0; i < ages.size(); i++)
//		{
//			int x = ages[i];
//			if (x <= 14) //����������Ҫ����û�y
//				continue;
//			while (left < ages.size() && ages[left] <= x / 2 + 7) //�ҵ���߽�
//				left++;
//			while (right + 1 < ages.size() && ages[right + 1] <= x) //�ҵ��ұ߽�
//				right++;
//			ans += right - left; //��������û��ܹ����ⷢ�͵ĺ�������ĸ����ۼӵ�ans��
//		}
//		return ans;
//	}
//};
class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		//1��ͳ��ÿ������ε��û�����
		vector<int> cnt(121);
		for (auto age : ages)
		{
			cnt[age]++;
		}
		//2�������cnt�����ǰ׺������pre
		vector<int> pre(121);
		for (size_t i = 1; i < 121; i++)
		{
			pre[i] = pre[i - 1] + cnt[i];
		}
		//3��ͨ����ʽ�����ÿ������ε����ɸ��û��ܹ����ⷢ�͵ĺ���������ܸ��������ۼ���һ��
		int ans = 0;
		for (size_t i = 15; i < 121; i++) //14�꼰���µ��û��޷����ⷢ�ͺ�������
		{
			if (cnt[i] != 0) //������ε��û�������Ϊ0
			{
				int bounds = i / 2 + 7;
				//��ÿ������ε��û��ܹ����ⷢ�͵ĺ�����������ۼ�
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