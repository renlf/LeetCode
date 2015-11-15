#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		map<int, int> dict;
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i - j > k)
				dict.erase(nums[j++]);
			auto iter = dict.lower_bound(nums[i] - t);
			if (iter != dict.end() && abs(nums[i] - iter->first) <= t)
				return true;
			dict[nums[i]] = i;
		}
		return false;
	}
};
