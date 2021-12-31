#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		//1����nums1���е�Ԫ�ؽ���ȥ�أ��õ�����s1
//		unordered_set<int> s1;
//		for (auto e : nums1)
//		{
//			s1.insert(e);
//		}
//		//2����nums2���е�Ԫ�ؽ���ȥ�أ��õ�����s2
//		unordered_set<int> s2;
//		for (auto e : nums2)
//		{
//			s2.insert(e);
//		}
//		//3������s1�������ж�s1�е�ÿ��Ԫ���Ƿ���s2���г��֣���û�г�����Ϊ����Ԫ��
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
		//1����nums1���е�Ԫ�ؽ���ȥ�أ��õ�����s1
		set<int> s1;
		for (auto e : nums1)
		{
			s1.insert(e);
		}
		//2����nums2���е�Ԫ�ؽ���ȥ�أ��õ�����s2
		set<int> s2;
		for (auto e : nums2)
		{
			s2.insert(e);
		}
		//3��ʹ��˫ָ���ҳ�s1��s2�Ľ���
		vector<int> vRet;
		set<int>::iterator it1 = s1.begin();
		set<int>::iterator it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			if (*it1 < *it2) //����ָ��ָ���Ԫ�ز����
			{
				it1++; //С��������
			}
			else if (*it2 < *it1) //����ָ��ָ���Ԫ�ز����
			{
				it2++; //С��������
			}
			else //����ָ��ָ���Ԫ�����
			{
				vRet.push_back(*it1); //��Ԫ�����ڽ���
				//����ָ��һ��������
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