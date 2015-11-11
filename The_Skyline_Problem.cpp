#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> ret;
		vector<pair<int, int>> height;
		for (int i = 0; i < buildings.size(); i++)
		{
			height.push_back(make_pair(buildings[i][0], -buildings[i][2]));
			height.push_back(make_pair(buildings[i][1], buildings[i][2]));
		}
		sort(height.begin(), height.end());
		multiset<int> heap;
		heap.insert(0);
		int pre = 0;
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i].second < 0)
				heap.insert(-height[i].second);
			else
				heap.erase(heap.find(height[i].second));
			int cur = *heap.rbegin();
			if (cur != pre)
			{
				ret.push_back(make_pair(height[i].first, cur));
				pre = cur;
			}
		}
		return ret;
	}
};
