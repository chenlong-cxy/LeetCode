#include<iostream>
#include <string>
using namespace std;
//��ת�ַ��������䲿�ַ�ת��
//class Solution {
//public:
//	string reverseStr(string s, int k) {
//		int sz = s.size();
//		for (int start = 0; start < sz; start += 2 * k)
//		{
//			int left = start;
//			int right = start + k;
//			if (right > sz)
//				right = sz;
//			while (left < right)
//				reverse(s.begin() + start, s.end() + right);
//				//swap(s[left++], s[right--]);
//		}
//		return s;
//	}
//};
class Solution {
public:
	string reverseStr(string s, int k) {
		int sz = s.size();
		//��2kΪһ����λ���ַ������б���
		for (int left = 0; left < sz; left += 2 * k)
		{
			int right = left + k; //������һ����Ҫ����ת���ַ�����һ���ַ�
			if (right > sz)
				right = sz; //��Խ�磬����right����ַ���ĩβ
			reverse(s.begin() + left, s.begin() + right); //��תleft��right����ǵ�k���ַ�
		}
		return s; //����Ŀ���ַ���
	}
};
int main()
{
	cout << Solution().reverseStr("abcdefg", 2) << endl;
	return 0;
}