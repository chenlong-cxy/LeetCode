#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		//1��ͳ��ÿ��������ֵĴ���
		vector<int> table(26, 0);
		for (const auto& task : tasks)
		{
			table[task - 'A']++;
		}

		//2�����������񰴳��ִ����Ӷൽ�ٽ�������
		sort(table.begin(), table.end(), greater<int>());

		//3��ͳ�Ƴ��ִ������������ִ������������
		size_t num = 1;
		while (num < 26 && table[num] == table[0])
		{
			num++;
		}

		//4��������õ���ֵ������ִ��������������бȽϣ����ؽϴ�ֵ
		return max(tasks.size(), (table[0] - 1) * (n + 1) + num);
	}
};
int main()
{
	vector<char> v{ 'A', 'A', 'A', 'B', 'B', 'B' };
	cout << Solution().leastInterval(v, 2) << endl;
	return 0;
}