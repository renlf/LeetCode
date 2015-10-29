#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int k = 0;
		int sum = 0;
		int min_len = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = k; j < nums.size(); j++)
			{
				k = j;
				sum += nums[j];
				if (sum >= s)
				{
					min_len = min(j - i + 1, min_len);
					break;
				}
			}

			sum -= nums[i];
			if (sum >= s)
				min_len = min(k - i, min_len);

			sum -= nums[k];
		}
		if (min_len == INT_MAX)
			return 0;

		return min_len;
	}
};
