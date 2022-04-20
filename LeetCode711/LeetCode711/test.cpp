#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_map<char, int> um;
		//1、遍历stones，统计其中每个字符出现的次数（统计每种石头出现的次数）
		for (auto e : stones)
		{
			um[e]++;
		}
		//2、遍历jewels，将其中每个字符在stones中出现的次数进行累加（将宝石出现的次数进行累加）
		int count = 0;
		for (auto e : jewels)
		{
			auto pos = um.find(e);
			if (pos != um.end())
				count += um[e];
		}
		return count; //返回宝石的个数
	}
};

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		unordered_set<char> us; //存储宝石的类型
		//1、遍历jewels，将其中的每个字符存储到unordered_set容器中（记录宝石的类型）
		for (auto e : jewels)
		{
			us.insert(e);
		}
		//2、遍历stones，统计其中宝石的个数（在石头中找宝石）
		int count = 0;
		for (auto e : stones)
		{
			if (us.find(e) != us.end())
				count++;
		}
		return count; //返回宝石的个数
	}
};

int main()
{
	cout << Solution().numJewelsInStones("aA", "aAAbbbb") << endl;
	return 0;
}