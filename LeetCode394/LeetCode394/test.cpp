#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	//���ַ���s��posλ�ÿ�ʼ����ȡ�����ַ���
	string GetNum(string& s, size_t& pos)
	{
		string num;
		while (s[pos] != '[')
		{
			num += s[pos];
			pos++;
		}
		return num;
	}
	//��vector���е��ַ���ƴ�Ӻ���з���
	string GetString(vector<string>& st)
	{
		string s;
		for (auto e : st)
		{
			s += e;
		}
		return s;
	}
	string decodeString(string s) {
		vector<string> st; //����ģ��ջ
		size_t pos = 0; //���ڱ����ַ���s
		while (pos < s.size())
		{
			//1���������������֣��Ƚ������������ַ�����ȡ������Ȼ�����ѹջ
			if (isdigit(s[pos]))
			{
				string num = GetNum(s, pos);
				st.push_back(num);
			}
			//2��������������ĸ��'['��ֱ�ӽ������ѹջ
			else if (isalpha(s[pos]) || s[pos] == '[')
			{
				st.push_back(string(1, s[pos]));
				pos++;
			}
			//3������������']'���Ȼ�ȡ�������Ƶ��ַ������ٽ�����и��ƣ���ý����ƺ���ַ������½���ѹջ
			else
			{
				vector<string> sub; //�����Ƶ������ַ���
				//a���Ƚ��е�ջ�����������ַ������浽vector���У�ֱ��'['������ʱֹͣ��ջ��'['�����浽vector��
				while (st.back() != "[")
				{
					sub.push_back(st.back());
					st.pop_back();
				}
				st.pop_back();

				//b���ٽ�vector���е����ݽ������ã���Ϊ��ջ��˳������ջ˳���෴
				reverse(sub.begin(), sub.end());

				//c��Ȼ�󽫴����Ƶ������ַ�������ƴ�ӣ��õ����մ����Ƶ��ַ���
				string all = GetString(sub);

				//d��������ʱջ���������ַ�����������ת��������num
				int num = stoi(st.back());
				st.pop_back();

				//d���������Ƶ��ַ�������num�Σ����յõ����ƺ���ַ���
				string str; //���ƺ���ַ���
				while (num--)
				{
					str += all;
				}

				//e�������ƺ���ַ�������ѹջ
				st.push_back(str);

				pos++;
			}
		}
		return GetString(st); //��ջ���е��ַ���ƴ�Ӻ���з���
	}
};

int main()
{
	string s("3[a]2[bc]");
	cout << Solution().decodeString(s) << endl;
	return 0;
}