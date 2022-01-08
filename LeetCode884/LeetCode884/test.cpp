#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> um;
		//1���������ַ���ƴ���������м��һ��" "�ַ���
		string str = s1 + " " + s2;

		//2����ƴ�Ӻ��ַ������еĵ��ʷ����ϣ��
		size_t start = 0; //��ͷ
		size_t pos = str.find(' '); //��β
		while (pos != string::npos) //ֱ���ҵ��ַ�����β
		{
			string word = str.substr(start, pos - start); //��������ȡ����
			um[word]++; //�����ʷ����ϣ��
			start = pos + 1; //������ͷ
			pos = str.find(' ', start); //������β
		}
		//�����һ�����ʷ����ϣ��
		string word = str.substr(start);
		um[word]++;

		//3���ҳ���ϣ����ֻ���ֹ�һ�εĵ��ʣ�������������
		vector<string> vRet;
		for (auto e : um)
		{
			if (e.second == 1) //ֻ���ֹ�һ�εĵ���
			{
				vRet.push_back(e.first);
			}
		}
		return vRet;
	}
};

int main()
{
	string s1("this apple is sweet");
	string s2("this apple is sour");
	vector<string> ret = Solution().uncommonFromSentences(s1, s2);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}