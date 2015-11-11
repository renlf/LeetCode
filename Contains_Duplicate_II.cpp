#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() <= 1)
			return false;
		unordered_map<int, int> dict;
		for (int i = 0; i < nums.size(); i++)
		{
			if (dict.find(nums[i]) != dict.end())
			{
				if (abs(i - dict[nums[i]]) <= k)
					return true;
			}
			dict[nums[i]] = i;
		}
		return false;
	}
};
