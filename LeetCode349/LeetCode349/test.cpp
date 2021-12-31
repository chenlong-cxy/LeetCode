#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		//1、对nums1当中的元素进行去重，得到序列s1
//		unordered_set<int> s1;
//		for (auto e : nums1)
//		{
//			s1.insert(e);
//		}
//		//2、对nums2当中的元素进行去重，得到序列s2
//		unordered_set<int> s2;
//		for (auto e : nums2)
//		{
//			s2.insert(e);
//		}
//		//3、遍历s1，依次判断s1中的每个元素是否在s2当中出现，若没有出现则为交集元素
//		vector<int> vRet;
//		for (auto e : s1)
//		{
//			if (s2.find(e) != s2.end())
//			{
//				vRet.push_back(e);
//			}
//		}
//		return vRet;
//	}
//};

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//1、对nums1当中的元素进行去重，得到序列s1
		set<int> s1;
		for (auto e : nums1)
		{
			s1.insert(e);
		}
		//2、对nums2当中的元素进行去重，得到序列s2
		set<int> s2;
		for (auto e : nums2)
		{
			s2.insert(e);
		}
		//3、使用双指针找出s1和s2的交集
		vector<int> vRet;
		set<int>::iterator it1 = s1.begin();
		set<int>::iterator it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			if (*it1 < *it2) //两个指针指向的元素不相等
			{
				it1++; //小的往后走
			}
			else if (*it2 < *it1) //两个指针指向的元素不相等
			{
				it2++; //小的往后走
			}
			else //两个指针指向的元素相等
			{
				vRet.push_back(*it1); //该元素属于交集
				//两个指针一起往后走
				it1++;
				it2++;
			}
		}
		return vRet;
	}
};

int main()
{
	vector<int> nums1{ 1, 2, 4, 6, 7 };
	vector<int> nums2{ 2, 5, 6, 8 };
	vector<int> ret = Solution().intersection(nums1, nums2);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}