#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//	bool halvesAreAlike(string s) {
//		string a(s.begin(), s.begin() + s.size() / 2);
//		string b(s.begin() + s.size() / 2, s.end());
//		string str = "aeiouAEIOU";
//		unordered_set<char> us(str.begin(), str.end());
//		int count = 0;
//		for (auto e : a)
//		{
//			if (us.find(e) != us.end())
//				count++;
//		}
//		for (auto e : b)
//		{
//			if (us.find(e) != us.end())
//				count--;
//		}
//		return count == 0;
//	}
//};
class Solution {
public:
	bool halvesAreAlike(string s) {
		//1����Ԫ����ĸ�洢��unordered_set������
		string str = "aeiouAEIOU";
		unordered_set<char> us(str.begin(), str.end());
		int count = 0;
		//2�������ַ�����ǰ�벿�֣�ͳ��Ԫ����ĸ����
		for (size_t i = 0; i < s.size() / 2; i++)
		{
			if (us.find(s[i]) != us.end())
				count++;
		}
		//3�������ַ����ĺ�벿�֣���ǰ�벿�ֵ�Ԫ����ĸ�������е���
		for (size_t i = s.size() / 2; i < s.size(); i++)
		{
			if (us.find(s[i]) != us.end())
				count--;
		}
		//4��������count������Ϊ0����˵�����ַ���ǰ��κͺ��ξ�����ͬ��Ŀ��Ԫ����ĸ
		return count == 0;
	}
};
int main()
{
	string s = "book";
	cout << Solution().halvesAreAlike(s) << endl;
	return 0;
}