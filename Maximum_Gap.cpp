#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maximumGap(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	auto minmax = minmax_element(nums.begin(), nums.end());
	int min_val = *minmax.first;
	int max_val = *minmax.second;

	if (min_val == max_val)
		return 0;
	int count = nums.size();
	int len = max(((max_val - min_val) / (count - 1)), 1);
	int buck_num = (max_val - min_val) / len + 1;

	vector<int> buck_min(buck_num, INT_MAX);
	vector<int> buck_max(buck_num, INT_MIN);

	for (int num : nums)
	{
		int i = (num - min_val) / len;
		buck_min[i] = min(buck_min[i], num);
		buck_max[i] = max(buck_max[i], num);
	}

	int gap = 0;
	int j = 0;
	for (int i = 1; i < buck_min.size(); i++)
	{
		if (buck_min[i] == INT_MAX)
			continue;
		gap = max(gap, buck_min[i] - buck_max[j]);
		j = i;
	}
	return gap;
}
