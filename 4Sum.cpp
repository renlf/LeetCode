#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {	
	vector< vector<int> > result;
	if (nums.size() < 4)
		return result;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && nums[i - 1] == nums[i])
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			if (j > i + 1 && nums[j - 1] == nums[j])
				continue;
			int l_index = j + 1;
			int r_index = nums.size() - 1;
			int remain = target - nums[i] - nums[j];
			while (l_index < r_index)
			{
				if (nums[l_index] + nums[r_index] == remain)
				{
					vector<int> tmp_result;
					tmp_result.push_back(nums[i]);
					tmp_result.push_back(nums[j]);
					tmp_result.push_back(nums[l_index]);
					tmp_result.push_back(nums[r_index]);
					result.push_back(tmp_result);
					while (l_index < r_index && nums[l_index] == nums[l_index + 1])
						l_index++;
					while (l_index < r_index && nums[r_index] == nums[r_index - 1])
						r_index--;
					l_index++;
					r_index--;
				}
				if (nums[l_index] + nums[r_index] < remain)
					l_index++;
				if (nums[l_index] + nums[r_index] > remain)
					r_index--;
			}
		}
	}
	return result;
}

int main()
{
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	vector< vector<int> > result;
	result = fourSum(nums, 0);
	return 0;
}
