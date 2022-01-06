#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		map<int, int> m1, m2;
//		for (auto e : nums1)
//		{
//			m1[e]++;
//		}
//		for (auto e : nums2)
//		{
//			m2[e]++;
//		}
//		vector<int> vRet;
//		map<int, int>::iterator it1 = m1.begin();
//		map<int, int>::iterator it2 = m2.begin();
//		while (it1 != m1.end() && it2 != m2.end())
//		{
//			if (it1->first < it2->first)
//			{
//				it1++;
//			}
//			else if (it2->first < it1->first)
//			{
//				it2++;
//			}
//			else
//			{
//				int count = it1->second;
//				if (it2->second < it1->second)
//				{
//					count = it2->second;
//				}
//				for (int i = 0; i < count; i++)
//				{
//					vRet.push_back(it1->first);
//				}
//				it1++;
//				it2++;
//			}
//		}
//		return vRet;
//	}
//};

//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		if (nums1.size() > nums2.size())
//		{
//			return intersect(nums2, nums1);
//		}
//		unordered_map<int, int> um;
//		for (auto e : nums1)
//		{
//			um[e]++;
//		}
//		vector<int> vRet;
//		for (auto e : nums2)
//		{
//			auto pos = um.find(e);
//			if (pos != um.end() && pos->second > 0)
//			{
//				vRet.push_back(e);
//				pos->second--;
//			}
//		}
//		return vRet;
//	}
//};

//哈希表
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		//为了降低空间复杂度，应该先将元素个数较少的数组放入哈希表
		if (nums1.size() > nums2.size())
		{
			return intersect(nums2, nums1);
		}
		//1、将nums1中的每个数字以及对应出现的次数放入哈希表中
		unordered_map<int, int> um;
		for (auto e : nums1)
		{
			um[e]++;
		}
		//2、遍历nums2，找出nums1和nums2的交集
		vector<int> vRet;
		for (auto e : nums2)
		{
			if (um.count(e)) //该元素在哈希表中
			{
				vRet.push_back(e); //该元素属于交集
				um[e]--; //减少该元素在哈希表中出现的次数
				if (um[e] == 0) //该元素的次数已经变为0了
				{
					um.erase(e); //将该元素从哈希表中删除
				}
			}
		}
		return vRet;
	}
};

//排序+双指针
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		//1、将nums1和nums2分别进行排序
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		//2、使用双指针找出num1和nums2的交集
//		vector<int> vRet;
//		int len1 = nums1.size(), len2 = nums2.size();
//		int pos1 = 0, pos2 = 0;
//		while (pos1 < len1&&pos2 < len2)
//		{
//			if (nums1[pos1] < nums2[pos2]) //两个指针指向的元素不相等
//			{
//				pos1++; //小的往后走
//			}
//			else if (nums2[pos2] < nums1[pos1]) //两个指针指向的元素不相等
//			{
//				pos2++; //小的往后走
//			}
//			else //两个指针指向的元素相等
//			{
//				vRet.push_back(nums1[pos1]); //该元素属于交集
//				//两个指针一起往后走
//				pos1++;
//				pos2++;
//			}
//		}
//		return vRet;
//	}
//};

int main()
{
	vector<int> nums1{ 4, 9, 5 };
	vector<int> nums2{ 9, 4, 9, 8, 4 };
	vector<int> ret = Solution().intersect(nums1, nums2);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}