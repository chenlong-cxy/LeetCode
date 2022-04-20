#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_map<char, int> um;
		//1������stones��ͳ������ÿ���ַ����ֵĴ�����ͳ��ÿ��ʯͷ���ֵĴ�����
		for (auto e : stones)
		{
			um[e]++;
		}
		//2������jewels��������ÿ���ַ���stones�г��ֵĴ��������ۼӣ�����ʯ���ֵĴ��������ۼӣ�
		int count = 0;
		for (auto e : jewels)
		{
			auto pos = um.find(e);
			if (pos != um.end())
				count += um[e];
		}
		return count; //���ر�ʯ�ĸ���
	}
};

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_set<char> us; //�洢��ʯ������
		//1������jewels�������е�ÿ���ַ��洢��unordered_set�����У���¼��ʯ�����ͣ�
		for (auto e : jewels)
		{
			us.insert(e);
		}
		//2������stones��ͳ�����б�ʯ�ĸ�������ʯͷ���ұ�ʯ��
		int count = 0;
		for (auto e : stones)
		{
			if (us.find(e) != us.end())
				count++;
		}
		return count; //���ر�ʯ�ĸ���
	}
};

int main()
{
	cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl;
	return 0;
}