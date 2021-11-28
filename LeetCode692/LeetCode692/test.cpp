#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> countMap;
		for (const auto& e : words)
		{
			countMap[e]++;
		}
		multimap<int, string, greater<int>> sortMap;
		for (const auto& e : countMap)
		{
			sortMap.insert(make_pair(e.second, e.first));
		}
		vector<string> retV;
		auto it = sortMap.begin();
		while (k--)
		{
			retV.push_back(it->second);
			it++;
		}
		return retV;
	}
};