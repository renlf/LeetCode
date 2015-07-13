#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int result = 0;
	if (nums.size() < 3)
		return result;
	sort(nums.begin(), nums.end());

	int sum_begin = nums[0] + nums[1] + nums[2];

	int gap = abs(sum_begin - target);
	
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int l_index = i + 1;
		int r_index = nums.size() - 1;
		int remain = target - nums[i];
		while (l_index < r_index)
		{
			int tmp_sum = nums[l_index] + nums[r_index];
			int smallest = remain - tmp_sum;
            int tmp_smallest = abs(smallest);

			if (tmp_smallest <= gap)
			{
				result = nums[i] + nums[l_index] + nums[r_index];
				if (tmp_smallest == 0)
				{
					return result;
				}
				gap = tmp_smallest;
				while (l_index < r_index && nums[l_index] == nums[l_index + 1])
					l_index++;
				while (l_index < r_index && nums[r_index] == nums[r_index - 1])
					r_index--;
			}
            if(smallest < 0)
            {
                r_index--;
            }
			if (smallest > 0)
			{
				l_index++;
			}
		}
	}
	return result;
}

int main()
{
	vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128};
	/*for (int i = 0; i < 3; i++)
	{
		nums.push_back(i);
	}*/
	int result = threeSumClosest(nums, 82);
	return 0;
}
