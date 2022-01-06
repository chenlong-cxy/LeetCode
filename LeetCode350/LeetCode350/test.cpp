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

//��ϣ��
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		//Ϊ�˽��Ϳռ临�Ӷȣ�Ӧ���Ƚ�Ԫ�ظ������ٵ���������ϣ��
		if (nums1.size() > nums2.size())
		{
			return intersect(nums2, nums1);
		}
		//1����nums1�е�ÿ�������Լ���Ӧ���ֵĴ��������ϣ����
		unordered_map<int, int> um;
		for (auto e : nums1)
		{
			um[e]++;
		}
		//2������nums2���ҳ�nums1��nums2�Ľ���
		vector<int> vRet;
		for (auto e : nums2)
		{
			if (um.count(e)) //��Ԫ���ڹ�ϣ����
			{
				vRet.push_back(e); //��Ԫ�����ڽ���
				um[e]--; //���ٸ�Ԫ���ڹ�ϣ���г��ֵĴ���
				if (um[e] == 0) //��Ԫ�صĴ����Ѿ���Ϊ0��
				{
					um.erase(e); //����Ԫ�شӹ�ϣ����ɾ��
				}
			}
		}
		return vRet;
	}
};

//����+˫ָ��
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		//1����nums1��nums2�ֱ��������
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		//2��ʹ��˫ָ���ҳ�num1��nums2�Ľ���
//		vector<int> vRet;
//		int len1 = nums1.size(), len2 = nums2.size();
//		int pos1 = 0, pos2 = 0;
//		while (pos1 < len1&&pos2 < len2)
//		{
//			if (nums1[pos1] < nums2[pos2]) //����ָ��ָ���Ԫ�ز����
//			{
//				pos1++; //С��������
//			}
//			else if (nums2[pos2] < nums1[pos1]) //����ָ��ָ���Ԫ�ز����
//			{
//				pos2++; //С��������
//			}
//			else //����ָ��ָ���Ԫ�����
//			{
//				vRet.push_back(nums1[pos1]); //��Ԫ�����ڽ���
//				//����ָ��һ��������
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