#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> um; //�洢ÿ����Сд��ĸ���������кŵ�ӳ��
		//1��������һ����ĸ���к�1��ӳ��
		string s1("qwertyuiop");
		for (auto e : s1)
		{
			um[e] = um[e - 32] = 1;
		}
		//2�������ڶ�����ĸ���к�2��ӳ��
		string s2("asdfghjkl");
		for (auto e : s2)
		{
			um[e] = um[e - 32] = 2;
		}
		//3��������������ĸ���к�3��ӳ��
		string s3("zxcvbnm");
		for (auto e : s3)
		{
			um[e] = um[e - 32] = 3;
		}
		vector<string> ret; //�洢����Ҫ����ַ���
		//4�������ж�ÿһ���ַ����Ƿ������ĿҪ��
		for (auto word : words)
		{
			//a����¼�ַ����е�һ���ַ������к�
			int row = um[word[0]]; 
			bool flag = true;
			//b���������ַ����������ַ�
			for (auto ch : word)
			{
				if (um[ch] != row) //���ַ���������ĳ���ַ����һ���ַ����ڵ��кŲ�ͬ
				{
					flag = false; //��������ĿҪ��
					break;
				}
			}
			//c�����ַ���������ĿҪ��������뼯��
			if (flag == true) 
				ret.push_back(word);
		}
		return ret; //���ط���Ҫ����ַ�������
	}
};
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> um; //�洢ÿ����Сд��ĸ���������кŵ�ӳ��
		vector<string> v{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };
		//1������ÿ���ַ����������кŵ�ӳ�䣨��0�С���1�С���2�У�
		for (size_t i = 0; i < v.size(); i++)
		{
			for (auto e : v[i])
			{
				um[e] = um[e - 32] = i;
			}
		}
		//2�������ж�ÿһ���ַ����Ƿ������ĿҪ��
		vector<string> ret; //�洢����Ҫ����ַ���
		for (auto word : words)
		{
			//a����¼�ַ����е�һ���ַ������к�
			int row = um[word[0]];
			bool flag = true;
			//b���������ַ����������ַ�
			for (auto ch : word)
			{
				if (um[ch] != row) //���ַ���������ĳ���ַ����һ���ַ����ڵ��кŲ�ͬ
				{
					flag = false; //��������ĿҪ��
					break;
				}
			}
			//c�����ַ���������ĿҪ��������뼯��
			if (flag == true)
				ret.push_back(word);
		}
		return ret; //���ط���Ҫ����ַ�������
	}
};
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		//1������ÿ���ַ����������кŵ�ӳ�䣨��0�С���1�С���2�У�
		string table("12210111011122000010020202");
		vector<string> ret; //�洢����Ҫ����ַ���
		//2�������ж�ÿһ���ַ����Ƿ������ĿҪ��
		for (auto word : words)
		{
			//a����¼�ַ����е�һ���ַ������к�
			char row = table[tolower(word[0]) - 'a'];
			bool flag = true;
			//b���������ַ����������ַ�
			for (auto e : word)
			{
				if (table[tolower(e) - 'a'] != row) //���ַ���������ĳ���ַ����һ���ַ����ڵ��кŲ�ͬ
				{
					flag = false; //��������ĿҪ��
					break;
				}
			}
			//c�����ַ���������ĿҪ��������뼯��
			if (flag == true)
				ret.push_back(word);
		}
		return ret; //���ط���Ҫ����ַ�������
	}
};
int main()
{
	vector<string> words{ "Hello", "Alaska", "Dad", "Peace" };
	vector<string> ret = Solution().findWords(words);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}