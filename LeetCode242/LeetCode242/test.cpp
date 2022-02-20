#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//	bool isAnagram(string s, string t) {
//		unordered_map<char, int> um1, um2;
//		for (char e : s)
//		{
//			um1[e]++;
//		}
//		for (char e : t)
//		{
//			um2[e]++;
//		}
//		if (um1.size() == um2.size())
//		{
//			for (char e : s)
//			{
//				if (um1[e] != um2[e])
//					return false;
//			}
//			return true;
//		}
//		return false;
//	}
//};

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) //��֤�����ַ����ĳ�����ͬ
			return false;

		vector<int> table; //��ϣ��
		table.resize(26); //��ǰ����26��λ��
		//1�������ַ���s��ͳ��s��ÿ����ĸ���ֵĴ���
		for (auto& ch : s)
		{
			table[ch - 'a']++;
		}
		//2�������ַ���t����t��s�е���ĸ���е���
		for (auto& ch : t)
		{
			table[ch - 'a']--;
			if (table[ch - 'a'] < 0) //����ʱ�����˸���
				return false;
		}
		return true; //ȫ�������ɹ�
	}
};

int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << Solution().isAnagram(s, t) << endl;
	return 0;
}