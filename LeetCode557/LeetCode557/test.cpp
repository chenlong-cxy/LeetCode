#include <iostream>
#include <string>
using namespace std;

//��ת�ַ����еĵ���
class Solution {
public:
	 //void myReverse(string& s, size_t start, size_t end)
	 //{
	 //    while(start < end)
	 //    {
	 //        char tmp = s[start];
	 //        s[start] = s[end];
	 //        s[end] = tmp;
	 //        start++;
	 //        end--;
	 //    }
	 //}
	string reverseWords(string s) {
		size_t start = 0; //����ַ����е�һ������ת���ʵĵ�һ���ַ�
		size_t end = s.find(' '); //��ȡ��һ���ո���±�
		while (end != std::string::npos) //�ҵ��ո�ͼ�������
		{
			//myReverse(s, start, end-1);
			reverse(s.begin() + start, s.begin() + end); //��ת��������
			start = end + 1; //�����һ������ת�ĵ��ʵĵ�һ���ַ�
			end = s.find(' ', start); //��startλ�ÿ�ʼ���Ѱ�ҿո�
		}
		end = s.size(); //������һ�����ʵ���һ��λ��
		//myReverse(s, start, end-1);
		reverse(s.begin() + start, s.begin() + end); //��ת���һ������
		return s; //���ط�ת����ַ���
	}
};
int main()
{
	string s = Solution().reverseWords("this is the first problem");
	cout << s << endl;
	return 0;
}