#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		vector<int> mintable(26, INT_MAX); //��¼26���ַ��ڸ����ַ����г��ֵ���С����
		vector<int> table(26); //��ʱ��¼26���ַ���ĳ���ַ����г��ֵĴ���

		//1������ÿ���ַ������ֱ��ҵ�26���ַ��ڸ����ַ����г��ֵ���С����
		for (const string& word : words)
		{
			fill(table.begin(), table.end(), 0); //���table
			//ͳ��word��ÿ���ַ����ֵĴ���
			for (const auto ch : word)
			{
				table[ch - 'a']++; //ֱ�Ӷ�ַ��
			}
			//����26���ַ��ڸ����ַ����г��ֵ���С����
			for (size_t i = 0; i < 26; i++)
			{
				mintable[i] = min(table[i], mintable[i]);
			}
		}

		//2������mintable���������ַ�����
		vector<string> ret;
		for (size_t i = 0; i < 26; i++)
		{
			for (size_t j = 0; j < mintable[i]; j++)
			{
				ret.emplace_back(1, i + 'a');
			}
		}
		return ret;
	}
};

int main()
{
	vector<string> words{ "bella", "label", "roller" };
	auto ret = Solution().commonChars(words);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}