#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int m = num1.size(), n = num2.size();
		vector<int> arr(m + n, 0);
		for (int i = m - 1; i >= 0; i--)
		{
			int a = num1[i] - '0';
			for (int j = n - 1; j >= 0; j--)
			{
				int b = num2[j] - '0';
				arr[i + j + 1] += a*b;
			}
		}
		int end = m + n - 1;
		while (end > 0)
		{
			arr[end - 1] += arr[end] / 10;
			arr[end] %= 10;
			end--;
		}
		int flag = 1;
		if (arr[0] != 0)
			flag = 0;
		string retArr;
		for (int i = flag; i < m + n; i++)
		{
			retArr += arr[i] + '0';
		}
		return retArr;
	}
};

int main()
{
	cout << Solution().multiply("222", "0") << endl;
	return 0;
}