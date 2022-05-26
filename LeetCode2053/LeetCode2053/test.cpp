#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		unordered_map<string, int> um;
		//1����������arr��ͳ��ÿ���ַ�����Ӧ���ֵĴ���
		for (auto e : arr)
		{
			um[e]++;
		}
		//2���ٴα�������arr���ҵ���k����һ�޶����ַ���
		for (auto e : arr)
		{
			if (um[e] == 1) //�ж��Ƿ��Ƕ�һ�޶����ַ���
			{
				k--;
				if (k == 0) //�ж��Ƿ��ǵ�k����һ�޶����ַ���
					return e;
			}
		}
		return ""; //�����ڵ�k����һ�޶����ַ������򷵻ؿ��ַ���
	}
};
int main()
{
	vector<string> arr{ "d", "b", "c", "b", "c", "a" };
	cout << Solution().kthDistinct(arr, 2) << endl;
	return 0;
}