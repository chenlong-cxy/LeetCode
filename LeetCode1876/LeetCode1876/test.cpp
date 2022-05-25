#include <iostream>
using namespace std;

class Solution {
public:
	int countGoodSubstrings(string s) {
		int count = 0, len = s.size();
		for (int i = 0; i < len - 2; i++)
		{
			if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
				count++;
		}
		return count;
	}
};
int main()
{
	cout << Solution().countGoodSubstrings("xyzzaz") << endl;
	return 0;
}