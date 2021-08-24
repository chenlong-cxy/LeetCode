#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string str_num[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; //ÿ�����ֱ������Ӧ���ַ���
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret; //�洢������ĸ���
		if (digits.empty()) //�����ַ���Ϊ�գ�ֱ�ӷ���
			return ret;
		string str; //��ǰ���ڽ������ɵ��ַ���
		int i = 0; //��ʶ������Ҫʹ�õ����ֱ����digits���е��±�
		_letterCombinations(digits, i, str, ret); //�ݹ�
		return ret; //������ĸ���
	}
	void _letterCombinations(const string& digits, int i, string str, vector<string>& ret)
	{
		if (i == digits.size()) //digits���е����ֱ�Ŷ�ʹ�ù���
		{
			ret.push_back(str); //�����ε���ĸ���β�嵽ret����
		}
		else //digits���е����ֱ�Ż���δʹ�õģ���ǰ�ַ�����δ������
		{
			int num = digits[i] - '0'; //ȡ��digits�ַ������е����ֱ��
			const string& letters = str_num[num]; //���ֱ��Ϊnum����Ӧ���ַ���
			//ʹ�÷�Χfor����ʹ���ַ���letters��ÿ���ַ��������
			for (auto ch : letters)
			{
				_letterCombinations(digits, i + 1, str + ch, ret);
			}
		}
	}
};

int main()
{ 
	for (auto e : Solution().letterCombinations("23"))
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}